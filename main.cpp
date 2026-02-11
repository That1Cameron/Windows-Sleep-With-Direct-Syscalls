#include "syscalls.cpp"

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

//int main(int argc, char* argv[]){
//int wmain(int argc, wchar_t *argv[]);
int wmain(int argc, char *argv[]){
    if(argc != 2){
        char helpMsg[] = "Usage ./sleep <number>\nThis will pause for <number> seconds";
        NtWriteFile_SYSCALL(hStdout, 0, 0, 0, &iosb, helpMsg, sizeof(helpMsg) - 1, 0, 0);
        return 1;
    }

    char* secondsIn = argv[1];
    long seconds = parseInput(secondsIn);

    //printf("sleeping for %d seconds", seconds);
    //sleep(seconds);
    
    return 0;
}