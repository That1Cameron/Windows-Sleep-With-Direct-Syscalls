#include "types.h"

#define SYSCALL_NTWRITEFILE         0x08
#define SYSCALL_NTTERMINATEPROCESS  0x2C

NTSTATUS NtWriteFile_SYSCALL(HANDLE FileHandle, HANDLE Event, void* ApcRoutine, void* ApcContext,
                            IO_STATUS_BLOCK* IoStatusBlock, void* Buffer, ULONG Length, void* ByteOffset, ULONG* Key){
    NTSTATUS ret;
    __asm__ volatile (
        "mov %%rcx, %%r10 \n"
        "mov %[id], %%eax \n"
        "syscall \n"
        : "=a"(ret)
        : [id]"i"(SYSCALL_NTWRITEFILE)
        : "rcx", "r10", "r11", "memory"
    );
    return ret;
}