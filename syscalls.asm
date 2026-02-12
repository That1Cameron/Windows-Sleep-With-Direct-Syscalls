section .text
global NtWriteFile_syscall

NtWriteFile_SYSCALL:
    mov r10, rcx
    mov eax, 0x08
    syscall
    ret
