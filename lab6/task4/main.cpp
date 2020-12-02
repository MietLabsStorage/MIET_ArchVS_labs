#include <iostream>

using namespace std;

int main()
{
    int i;
    const double epsilon = 0.2;
    double sum;
    const double n1=1;
    const double n2=-2;
    double current;
    cout << "Sum of series" << endl;
    asm
    (
    "xor %[I], %[I]\n"              // i = 0
    "fldl %[N2]\n"                  //-2
    "fldl %[N1]\n"                  //sum=1, -2
    "fldl %[N1]\n"                  //cur=1, sum=1, -2

    "begin_iteration: \n"           //loop begin
    "addl $1, %[I]\n"               //i++
    "fdiv %%st(2), %%st(0) \n"      //cur=cur/(-2), sum, -2
    "fxch\n"                        //sum, cur, -2
    "fadd %%st(1)\n"                //sum+=cur, cur, -2
    "fxch\n"                        //cur, sum, -2


    //"cmpl %[E], %%st(0)\n"        its unwork now because double not int
    //"jne end_check\n"

    //"fstpl %[C]\n"
    //"jmp end_check\n"

    "cmpl $3, %[I]\n"
    "jne begin_iteration\n"         //jump in loop

    "end_check: \n"                 // label end_check
    "fstpl %[C]\n"
    "fstpl %[S]\n"
    //доочистить при завершении программы
    : [I]"+r"(i), [S]"=m"(sum), [C]"=m"(current)
    : [E]"m"(epsilon), [N1]"m"(n1), [N2]"m"(n2)
    : "cc"
    );
    cout << "Iterations: " << i << endl;
    cout << "Last elem: " << current << endl;
    cout << "Sum: " << sum << endl;
    return 0;
}
