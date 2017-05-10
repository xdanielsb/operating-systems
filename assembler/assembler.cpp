#include <iostream>
 
extern "C" int func();
// the definition of func is written in assembly language
asm(".globl func\n\t"
    ".type func, @function\n\t"
    "func:\n\t"
    ".cfi_startproc\n\t"
    "movl $7, %eax\n\t"
    "ret\n\t"
    ".cfi_endproc");
 
int main()
{
    int n = func();
    // extended inline assembly
    asm ("leal (%0,%0,4),%0"
         : "=r" (n)
         : "0" (n));
    std::cout << "7*5 = " << n << std::endl; // flush is intentional
 
    // standard inline assembly
    asm ("movq $60, %rax\n\t" // the exit syscall number on Linux
         "movq $2,  %rdi\n\t" // this program returns 2
         "syscall");
}
