#include <iostream>
#include <math.h>
#include <string>
using namespace std;

extern "C" unsigned int fun1(unsigned int x);

int main()
{
    for(unsigned int i = 0; i < 30; i++)
    {
        cout << "x: " << i << "\tC++:  " << (i%4-i) << "\tAsm: " << fun1(i) << endl;
    }

    return 0;
}
