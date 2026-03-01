#include "types.h"

char* getArg() {
    // skip to end of path with quote

    // continue until num char

    // return addr
}

NTSTATUS sleep(int time){
    LARGE_INTEGER nano;
    nano.QuadPart = -(LONGLONG)time * 10000000;;
    int nanoTime = time * 1000000000;
    return ntDelayExecution_SYSCALL(0, &nano);
}

int parseInput(char* input){
    int time = 0;
    char* curr = input;

    while(*curr != '\0' && *curr !='\n'){
        if (*curr >= '0' && *curr <= '9'){
            time = time * 10 + (*curr - '0');
        }
        curr++;
    }

    return time;
}


int wmain(int argc, char *argv[]){
    PEB* peb = getPEB();
    HANDLE stdOutHandle = peb->ProcessParameters->StandardOutput;
    IO_STATUS_BLOCK iosb;
    UNICODE_STRING ip = peb->ProcessParameters->ImagePathName;
    UNICODE_STRING cl = peb->ProcessParameters->CommandLine;
    if(argc != 2){
        char helpMsg[] = "\nUsage ./sleep <number>\nThis will pause for <number> seconds\n";
        ntWriteFile_SYSCALL(stdOutHandle, 0, 0, 0, &iosb, helpMsg, sizeof(helpMsg) - 1, 0, 0);
        ntWriteFile_SYSCALL(stdOutHandle, 0, 0, 0, &iosb, cl.Buffer, cl.Length, 0, 0);
        return 1;
    }

    //char* secondsIn = argv[1];
    char secondsIn[] = "5\0";
    int seconds = parseInput(secondsIn);
    char msg1[] = "Sleeping for";
    char msg2[] = " seconds\n";
    ntWriteFile_SYSCALL(stdOutHandle, 0, 0, 0, &iosb, msg1, sizeof(msg1) - 1, 0, 0);
    ntWriteFile_SYSCALL(stdOutHandle, 0, 0, 0, &iosb, cl.Buffer, cl.Length, 0, 0);
    ntWriteFile_SYSCALL(stdOutHandle, 0, 0, 0, &iosb, msg2, sizeof(msg2) - 1, 0, 0);


    sleep(seconds);
    
    return 0;
}


// This is a bandaid solution, need to replace standard wmain for asm start call
extern "C" void start(){
    char** argv;
    while (wmain(2, argv)) {}
}