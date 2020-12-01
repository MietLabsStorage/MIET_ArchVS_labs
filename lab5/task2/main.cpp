#include <iostream>

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
    "fldl %[X]\n"       //0.9*X*X,    X
    "faddp \n"          //0.9*X*X+X
    "fcos\n"            //cos(0.9*X*X+X)
    "f2xm1\n"   //2^cos(0.9*X*X+X)-1
    "fld1\n"    //2^cos(0.9*X*X+X)-1, 1
    "faddp\n"   //2^cos(0.9*X*X+X)
    "fstpl %[Y]\n"      //Y=cos(0.9*X*X+X), stack FPU is empty
    :[Y]"=m"(y)
    :[X]"m"(x), [A]"m"(a)
    :
    );
    cout.precision(8);
    cout << "cos(" << x << "+" << "0.9*" << x << "*" << x << ")=" << y;
}
