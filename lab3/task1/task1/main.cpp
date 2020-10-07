#include <iostream>
#include <math.h>
#include <string>
using namespace std;

extern "C" int fun1(int x);

int main()
{
    for(int i = 0; i < 30; i++)
    {
        cout << "x: " << i << "\tC++:  " << (i%4-i) << "\tAsm: " << fun1(i) << endl;
    }

    return 0;
}



