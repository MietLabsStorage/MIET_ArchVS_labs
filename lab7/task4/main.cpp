#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Pair{
    int key;
    double value;
};

int main()
{
    srand(time(0));
    int N;
    cout << "Size of b:: ";
    cin>> N;
    struct Pair* b = new struct Pair[N] ;
    cout<<"Key:: ";
    int k = 0;
    cin >> k;
    for (int i = 0; i < N; i++)
    {
        b[i].key = rand() % 3 + k;
        b[i].value = rand() % 100 / 3.0;
        cout << "{" << b[i].key << "; " << b[i].value << "} ";
    }
    cout << endl;
    double Min = -1;
    asm (
    "movl $0, %%eax \n"

    "Begin: \n"
    "cmpl %[N], %%eax \n" //счетчик
    "je ExitNM \n"

    "movl %[b], %%ecx \n"
    "leal (%%ecx, %%eax, 8), %%ecx \n"
    "leal (%%ecx, %%eax, 8), %%ecx \n"  //пеемещаемя к след структуе
    "movl (%%ecx),%%ecx \n"

    "cmpl %[K], %%ecx \n"  //сраниваем ключ
    "je lable \n"
    "incl %%eax \n"

    "jmp Begin \n"

    "lable: \n" 
    "movl %[b], %%ecx \n"
    "leal (%%ecx, %%eax, 8), %%ecx \n"
    "leal 8(%%ecx, %%eax, 8), %%ecx \n"
    //"movl (%%ecx),%%ecx \n"
    //"movl %%ecx, %[Min] \n"
    //"fldl %[Min] \n"
    "fldl (%%ecx) \n"  //пихаем в стек
    "incl %%eax \n"
    //-----------------------—

    "BeginSearchMin: \n"
    "cmpl %[N], %%eax \n"
    "je ExitHM \n"
    "movl %[b], %%ecx \n"
    "leal (%%ecx, %%eax, 8), %%ecx \n"
    "leal (%%ecx, %%eax, 8), %%ecx \n"
    "movl (%%ecx),%%ecx \n"

    "cmpl %[K], %%ecx \n"
    "jne CONTINUESEARCH \n"

    "movl %[b], %%ecx \n"
    "leal (%%ecx, %%eax, 8), %%ecx \n"
    "leal 8(%%ecx, %%eax, 8), %%ecx \n"
    //"movl (%%ecx),%%ecx \n"
    "fldl (%%ecx) \n"
    "push %%ax \n"
    "fcom \n"
    "fnstsw \n"
    //"fstpl %[Min] \n"
    "sahf \n"
    "pop %%ax \n"
    "jc CHANGEMIN \n"

    "fstpl %[Min] \n"
    "jmp CONTINUESEARCH \n"

    "CHANGEMIN: \n"
    "fxch \n"
    "fstpl %[Min] \n"

    "CONTINUESEARCH: \n"
    "incl %%eax \n"
    "jmp BeginSearchMin \n"

    "ExitHM: \n"
    "fstpl %[Min] \n"

    "ExitNM: \n"
    : [Min]"+m" (Min)
    : [b]"m"(b), [N]"m"(N), [K]"m"(k)
    : "cc", "%eax", "%ecx"
    );

    if(Min == -1){
        cout<<"\nNo key = "<<k<<" elements\n";
    }
    else{
        cout<<"\nMinimum:"<<Min<<endl;
    }

    return 0;
}
