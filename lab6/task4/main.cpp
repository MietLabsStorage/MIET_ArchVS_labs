#include <iostream>

using namespace std;

int main()
{
    int i;
    const double epsilon = 0.001;
    double sum;
    const double n1=1;
    const double n2=-2;
    double current;
    double tempCurrent;
    cout << "Sum of series" << endl;
    asm
    (
    "xor %%edx, %%edx\n"            //i = 0
    "fldl %[N2]\n"                  //-2
    "fldl %[N1]\n"                  //sum=1, -2
    "fldl %[N1]\n"                  //cur=1, sum=1, -2

    "begin_iteration: \n"           //loop begin
    "addl $1, %%edx\n"              //i++
    "fdiv %%st(2), %%st(0) \n"      //cur=cur/(-2), sum, -2
    "fxch\n"                        //sum, cur, -2
    "fadd %%st(1)\n"                //sum+=cur, cur, -2
    "fxch\n"                        //cur, sum, -2

    "fstl %[TEMP]\n"                //cur, sum, -2
    "fldl %[TEMP]\n"                //temp=cur, cur, sum, -2
    "fabs\n"                        //abs(temp), cur, sum, -2
    "fldl %[E]\n"                   //eps, temp, cur, sum, -2
    "fsubp\n"                       //eps-temp, cur, sum, -2
    "ftst\n"                        //eps-temp ? 0
    "fstsw\n"                       //store flags
    "sahf\n"                        //load flags
    "fstpl %[TEMP]\n"               //cur, sum, -2
    "jnb end_check\n"

    "cmpl $1000, %%edx\n"
    "jne begin_iteration\n"         //jump in loop

    "end_check: \n"                 // label end_check
    "movl %%edx, %[I]\n"
    "fstpl %[C]\n"
    "fstpl %[S]\n"
    "fstpl %[TEMP]\n"

    : [I]"=r"(i), [S]"=m"(sum), [C]"=m"(current), [TEMP]"=m"(tempCurrent)
    : [E]"m"(epsilon), [N1]"m"(n1), [N2]"m"(n2)
    : "cc"
    );
    cout << "Eps: " << epsilon << endl;
    cout << "Iterations: " << i << endl;
    cout << "Last elem: " << current << endl;
    cout << "Sum: " << sum << endl;
    return 0;
}

