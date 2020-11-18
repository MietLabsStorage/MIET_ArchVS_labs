#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    volatile const double a = 0.9;
    double x;
    volatile double y;
    cout << "cos(x+0.9*x*x)=?" << endl;
    cout << "Write x: ";
    cin >> x;
    asm
    (                   //st(0)     st(1)
    "fldl %[X]\n"       //X
    "fmull %[X]\n"      //X*X
    "fmull %[A]\n"      //0.9*X*X
    "fldl %[X]\n"       //2*X*X,    X
    "faddp \n"           //2*X*X+X
    "fcos\n"            //cos(2*X*X+X)
    "fstpl %[Y]\n"      //Y=cos(2*X*X+X), ���� FPU ����
    :[Y]"=m"(y)
    :[X]"m"(x), [A]"m"(a)
    :"cc"
    );
    cout << "cos(" << x << "+" << "0.9*" << x << "*" << x << ")=" << y;
}
