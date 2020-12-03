#include <iostream>

using namespace std;
// x/2 if x%2=0
// 3x+1 if x%2<>0
int main()
{
    int x, f;
    cout << "if x%2=0 then f=x/2 else f=3x+1\n";
    cout << "write x: ";
    cin >> x;
    asm
    (
    /*"movl %[X], %%eax\n"  // ..
    "movl %[X], %%ecx\n"    // ..
    "and $-2, %%eax\n"      // ..
    "sub %%eax, %%ecx\n"    // x%2*/

    "movl %[X], %%eax\n"    // ..
    "bt $0, %%eax\n"        // последний бит в числе определяет четность, bt - заносит в CF заданный бит из регистра

    "jae zero_equal\n"      // if (x%2) == 0 goto zero_equal

    "movl %[X], %%eax\n"    // ..
    "imull $3, %%eax\n"     // ..
    "add $1, %%eax\n"       // ..
    "movl %%eax, %[F]\n"    // f = 3x+1
    "jmp end_check\n"       // goto end_check

    "zero_equal:\n"         // label zero_equal
    "movl %[X], %%eax\n"    // ..
    "shrl $1, %%eax\n"      // ..
    "movl %%eax, %[F]\n"    // f = x/2

    "end_check: \n"         // label end_check
    : [F]"+r"(f)
    : [X]"r"(x)
    : "cc"
    );

    cout << "f = " << f << endl;
    return 0;
}
