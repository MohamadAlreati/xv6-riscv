### Theoritical Questions for assignment 1:
NOT FOR SUBMISSION


1. Q: How does calling a system call differ from calling a regular function?
How does it work?


A: calling a regular function, is done by a direct jump (jal/call) to another address within the same processs' address space, while staying in user mode, with no privilege change, callign a system call, first the user program inserts the sys call number in reg a7, and then calls the ecall instruction, which traps the cpu into kernel mode, the kernel saves the user state (trap frame), dispaches to the correct handler via the syscall table, executes with full kernel privileges, then returns to the user mode. 

2. Q: How are parameters passed to the system call function? How is the
return value returned to userspace?


A: the user program puts the arguments into regesters a0-a5 (according to syscall.c/argraw()), then calls the ecall instruction wich saves traps into kernel mode and saves the calling program's trap frame, the kernel reads the arguments for the syscall from the trapframe, and when the returned value is ready, it gets passed to the calling program by placing it in the a0 entry of the trapframe.

3. Q: What is the purpose of the usys.pl file?


A: the file contains a Perl subroutine, which runs at build time and generates an assymbly file called, usys.S, which cantains an entry for each syscall, when a program jumps to this entry, it execues the following: inserts SYS_"the name of the sys call" to a7, then calls the ecall instructoin and returns.

4. Q: What is struct proc and where is it defined? Why do we need it?
Does a real-world operating system have a similar structure?


A: the proc struc, is the program side of the PCB (Process Control Block), it's defined in the header file proc.h, we need it because the kernel needs it because it needs to keep track of the different processes states, since it represents an entry in the process table, so real-word OS contains a similar structure (task_struct in Linux).

5. Q: How much memory does our program use before and after the allocation?


A: memsize before alloc: 16384 bytes
memsize after alloc: 81920 bytes


6. Q: What is the difference between the memory size before and after
the release?


A: memsize after alloc: 81920 bytes
memsize after free: 81920 bytes

7. Q: Try to explain the difference before and after release. What could cause this difference? (Advanced: look at the implementation of
malloc and free).


A: the syscall that increases the size of the heap of the process, is sbrk, which is called in the function morecore, but free on the other hand, while it successfully frees the block (and returns it back to theinternal free blocks list), it has no contrary syscall for sbrk, so the OS will not be aware of this change in the process heap size.  