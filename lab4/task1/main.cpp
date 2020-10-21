#include <iostream>
using namespace std;
int main()
{
	unsigned int a;
    unsigned int b;
    unsigned int c = 0;
	cout << "Operation a + b (unsigned)\n";
	cout << "Please, enter number a:\n";
	cin >> a;
	cout << "Please, enter number b:\n";
	cin >> b;

	cout << a << " + " << b << " = ";
	asm
	(
        "movl %[a],%[c]\n\t"
		"addl %[b],%[c]"
		: [c]"+r" (c)
        : [a]"r" (a), [b]"r"(b)
		: "cc"
	);

	asm goto
	(
		"jc %l1"
		:: [c]"r" (c)
		: "cc"
		: carry
	);

	cout << c << "\t Answer is right"<< endl;
	return 0;

    carry:
	cout << c << "\t Answer is incorrect"<< endl;
	return 0;
}
