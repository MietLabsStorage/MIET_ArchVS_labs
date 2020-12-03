#include <iostream>

using namespace std;

int main()
{
    double x, y;
    double n1 = 1, n3 = 3, n13 = 13;
    cout << "if x<13 then y=1-x/3 else y=1+x\n";
    cout << "write x: ";
    cin >> x;
    asm
    (
    "fldl %[X]\n"           // x
    "fldl %[N13]\n"         // 13,   X
    "fsubrp\n"              // x-13
    "ftst\n"                // x-13 ? 0
    "fstsw\n"               // store flags
    "sahf\n"                // load flsgs
    "fstpl %[Y]\n"          // stack is emty
    "jnb else\n"

    "fldl %[X]\n"           // x
    "fldl %[N3]\n"          // 3,  x
    "fdivrp\n"              // x/3
    "fldl %[N1]\n"          // 1,   x/3
    "fsubp\n"               // 1-x/3
    "jmp finally\n"

    "else:\n"
    "fldl %[X]\n"           // x
    "fldl %[N1]\n"          // 1, x
    "faddp\n"               // 1+x

    "finally:\n"
    "fstpl %[Y]\n"          // stack is emty

    : [Y]"=m"(y)
    : [X]"m"(x), [N1]"m"(n1), [N3]"m"(n3), [N13]"m"(n13)
    :
    );

    cout << y << endl;
    return 0;
}
