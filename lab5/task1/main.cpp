#include <iostream>

using namespace std;

int main()
{
    cout << "a - b = ?" << endl;
    float a = 123456789;
    float b = 123456788;
    cout << "123456789 - 123456788 = " << a-b << endl;

    a = 123456788;
    b = 123456787;
    cout << "123456788 - 123456787 = " << a-b << endl;

    cout << "\n\nRemark" <<
    "\n float 123456789 as int: " << (int)(float)123456789 <<
    "\n float 123456788 as int: " << (int)(float)123456788 <<
    "\n float 123456787 as int: " << (int)(float)123456787 << endl;
    return 0;
}
