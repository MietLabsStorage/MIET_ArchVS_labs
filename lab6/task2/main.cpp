#include <iostream>

using namespace std;

int main()
{
    double x = 10, y=0;
    double n1 = 1, n3 = 3, n13 = 13;

    asm
    (
    "fldl %[X]\n"           // x
    "fldl %[N3]\n"          // 3,   X
    "fdivrp\n"              // x/3
    "fldl %[N1]\n"          // 1,   x/3
    "fsubp\n"               // 1-x/3
    "fldl %[X]\n"           // x,  1-x/3
    "fldl %[N1]\n"          // 1,   x,  1-x/3
    "fsubp\n"               // 1-x, 1-x/3
    "fldl %[X]\n"           // x, 1-x, 1-x/3
    "fldl %[N13]\n"         // 13, x, 1-x, 1-x/3
    "fsubp\n"               // 13-x, 1-x, 1-x/3
    "fcmovnbe %st(1), %st(0)\n"

    //"end_check: \n"
    "fstpl %[Y]\n"

    : [Y]"=m"(y)
    : [X]"m"(x), [N1]"m"(n1), [N3]"m"(n3), [N13]"m"(n13)
    : "cc"
    );

    cout << y << endl;
    return 0;
}
