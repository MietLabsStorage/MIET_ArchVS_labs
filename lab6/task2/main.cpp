#include <iostream>

using namespace std;

int main()
{
    double x = 10, y=0;
    double n1 = 1, n3 = 3, n13 = 13;

    asm
    (
    "fldl %[X]\n"

    //"fist %%rax\n"          //аааа, надо типа double-вский x сравнить с 13
    "fcmp %[N13], st(0)\n"      // я не помню как
    "jge less13\n"          // тут должна быть проверка (сопроцессоровская)

                            // if x < 13
    "fldl %[N3]\n"          // 3,   X
    "fdivrp\n"              // x/3
    "fldl %[N1]\n"          // 1,   x/3
    "fsubp\n"               // 1-x/3
    "jmp end_check\n"       // goto end_check


    "less13: \n"            // if x >= 13
    "fldl %[N1]\n"          // 1,   x
    "fsubp\n"                 // 1-x
                            // goto end_check

    "end_check: \n"
    "fstpl %[Y]\n"

    : [Y]"=m"(y)
    : [X]"m"(x), [N1]"m"(n1), [N3]"m"(n3), [N13]"m"(n13)
    : "cc"
    );

    cout << y << endl;
    return 0;
}
