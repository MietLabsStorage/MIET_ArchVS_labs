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
    int minElem;

    asm
    (
    "movl $1, %%eax \n"         // счетчик
    "movl %[a], %%edx \n"       // &a -> edx; edx - min
    "movl (%%edx), %%edx \n"    // *(a+0) -> edx

    "Begin: \n"
    "cmpl %[N], %%eax \n"       //while i != N
    "je End \n"

    "movl %[a], %%ecx \n"                   // &a -> ecx
    "leal (%%ecx, %%eax, 4), %%ecx \n"      // &(a+i*4) -> ecx
    "movl (%%ecx),%%ecx \n"                 // *(a+i) -> ecx

    "cmpl %%edx, %%ecx \n"  // min ? *(a+i)
    "jnbe notMin \n"

    "movl %%ecx, %%edx \n"  // min -> edx

    "notMin: \n"
    "incl %%eax \n"         // i++
    "jmp Begin \n"

    "End: \n"
    "movl %%edx, %[MIN] \n"

    : [MIN]"+m" (minElem)
    : [a]"m"(a), [N]"m"(N)
    : "cc", "%eax", "%edx", "%ecx"
    );

    cout<<"Min element:: "<< minElem;

    return 0;
}
