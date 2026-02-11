# Windows-Sleep-With-Direct-Syscalls
I have put together a sleep binary implemented with direct Windows syscalls through inline asm to avoid using the win32 api or the C standard library.
This experiemnt was inspired by [this project](https://youtu.be/IbibjkI1kIs?si=UUizI0Dt8HO7Xdyp) but implemented for Windows. 


## Windows System calls 

The windows systemcall architecture is a bit different so I decided to forgo the idea of arg count based syscall wrappers and make functions that wrapped specific syscalls. This was designed to run on specifically x86-64 Windows 11 24H2 as the Windows syscall numbers are subject to change from one OS version to another (sometimes changing from minor versons like NtAlertResumeThread going from 110 to 111 in versions Windows 11 23H2 to Windows 11 24H2 . . .).

The Win32API, user32.dll and more specifically ntdll.dll exsist as wrappers/abstractions so that microsoft can change the system call without breaking existing products, my opinion could go either way on that design philosophy.


## Refrances
### General project inspiration
* https://nullprogram.com/blog/2016/01/31/
* https://youtu.be/IbibjkI1kIs?si=UUizI0Dt8HO7Xdyp
### inline assembly guide i used for g++
* https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#toc6
### Windows syscalls and documentation
* https://j00ru.vexillium.org/syscalls/nt/64/
* https://learn.microsoft.com/en-us/cpp/build/x64-calling-convention?view=msvc-170
* https://ntdoc.m417z.com/ntwritefile (not just for ntwritefile)
