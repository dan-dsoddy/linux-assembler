/*
 * test.c
 * execve /usr/bin/id shellcode tester.. 
 * this is the shellcode test for execve_id1.s
 * I'm a bit old school and use assert to make executable stack
 * compile: gcc test.c -o test -fno-stack-protector
 * dan.dsod@gmail.com
*/


#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/user.h>
#include <assert.h>

#define PAGE_SIZE  0x1000

char code[]=  	"\x6a\x3b\x58\x99\x52\x48\xbf\x2f\x2f\x62\x69\x6e"
		"\x2f\x69\x64\x57\x48\xbf\x2f\x2f\x2f\x2f\x2f"
		"\x75\x73\x72\x57\x54\x5f"
		"\x48\x31\xf6\x0f\x05";


int main(){
        printf("shellcode length: %zu\n",strlen(code));
        int (*func)();
        // we need to make some memory executable to test the shellcode..
        assert(mprotect((void *)((size_t)code & (~(PAGE_SIZE -1 ))), PAGE_SIZE, PROT_EXEC | PROT_READ | PROT_WRITE) == 0);
        func = (int (*)())code;
        (int)(*func)();
        return 0;
}
 

