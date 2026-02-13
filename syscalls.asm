section .text
global ntWriteFile_syscall
global getPEB

ntWriteFile_SYSCALL:
    mov r10, rcx
    mov rax, 0x08
    syscall
    ret


getPEB:
	mov rax, gs:[0x60]
    ret
