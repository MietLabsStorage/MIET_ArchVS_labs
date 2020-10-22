#include <iostream>
using namespace std;
int main()
{
	unsigned int a;
    unsigned int b;
    unsigned int c;
	cout << "Operation a + b (unsigned)\n";
	cout << "Please, enter number a:\n";
	cin >> a;
	cout << "Please, enter number b:\n";
	cin >> b;

	cout << a << " + " << b << " = ";
	asm
	(
        "mov %[a],%[c]\n\t"
		"add %[b],%[c]"
		: [c]"+r" (c)
        : [a]"r" (a), [b]"r"(b)
		: "cc"
	);

	asm goto
	(
		"jc %l0"
		::
		: "cc"
		: carry
	);

	cout << c << "\t Answer is right"<< endl;
	return 0;

    carry:
	cout << c << "\t Answer is incorrect"<< endl;
	return 0;
}
