#include "types.h"

long parseInput(char* input){
    long time = 0;
    char* curr = input;

    while(*curr != '\0' || *curr !='\n'){
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
        ntWriteFile_SYSCALL(stdOutHandle, 0, 0, 0, &iosb, cl.Buffer, cl.Length - 1, 0, 0);
        return 1;
    }

    char* secondsIn = argv[1];
    long seconds = parseInput(secondsIn);

    //printf("sleeping for %d seconds", seconds);
    //sleep(seconds);
    
    return 0;
}


// This is a bandaid solution, need to replace standard wmain for asm start call
extern "C" void start(){
    char** argv;
    while (wmain(1, argv)) {}
}