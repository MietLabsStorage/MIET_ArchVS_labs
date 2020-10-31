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
    "mov %[x], %%eax \n\t"
    "and $-4, %%eax\n\t"
    //"shr $2, %%eax \n\t"
    //"shl $2, %%eax \n\t"
    "neg %%eax \n\t"
    "mov %%eax, %[x]"
    : [x]"+r"(x)
    :
    : "cc", "%eax"
    );

	cout << x << endl;

    return 0;
}
