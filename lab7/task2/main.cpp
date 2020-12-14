#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    int N = 0;
    cout << "Size of array:: ";
    cin >> N;
    int* a = new int[N];
    cout << "Array:: ";
    for(int i = 0; i < N; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    int minElem = a[0];
    asm
    (
    "movl $1, %%eax \n"
    "movl %[a], %%edx \n"
    "movl (%%edx), %%edx \n"

    "Begin: \n"
    "cmpl %[N], %%eax \n"
    "je End \n"

    "movl %[a], %%ecx \n"
    "leal (%%ecx, %%eax, 4), %%ecx \n"
    "movl (%%ecx),%%ecx \n"

    "cmpl %%edx, %%ecx \n"
    "jnbe lable \n"

    "movl %%ecx, %%edx \n"

    "lable: \n"
    "incl %%eax \n"
    "jmp Begin \n"

    "End: \n"
    "movl %%edx, %[MIN] \n"

    : [MIN]"+m" (minElem)
    : [a]"m"(a), [N]"m"(N)
    : "cc", "%eax", "%edx", "%ecx"
    );

    cout<<"Min element:: "<<minElem;

    return 0;
}
