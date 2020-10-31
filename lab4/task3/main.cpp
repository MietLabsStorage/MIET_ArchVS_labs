#include <iostream>
using namespace std;
int main()
{
    int x ;
	cout << "Operation: x % 4 - x \n";
	cout << "Please, enter x:\n";
	cin >> x;

	cout << x  <<  " % 4 - " << x << " = " << endl;
    asm
    (
    "and $-4, %[x]\n\t"
    "neg %[x]\n\t"
    : [x]"+r"(x)
    :
    : "cc"
    );

	cout << x << endl;

    return 0;
}
