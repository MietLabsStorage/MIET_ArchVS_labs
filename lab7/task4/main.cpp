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
    cin >> N;
    if(N <= 0){
        cout << "Arr cant be less or equal zero-size";
        return 0;
    }
    struct Pair* b = new struct Pair[N] ;
    cout<<"Key:: ";
    int k = 0;
    cin >> k;
    for (int i = 0; i < N; i++)
    {
        b[i].key = rand() % 3 + k;
        b[i].value = rand() % 100 / 3.0;
        cout << "{" << b[i].key << "; " << b[i].value << "} " << endl;
    }
    cout << endl;
    double minElem = -1;
    int f = 0; // count of structs with key == K
    asm (
    "mov $0, %%eax \n"      // счетчик

    "Begin: \n"
    "cmp %[N], %%eax \n"    // while i != N
    "je searchMin \n"

    "mov %[b], %%ecx \n"                // &b -> ecx
    "lea (%%ecx, %%eax, 8), %%ecx \n"   //
    "lea (%%ecx, %%eax, 8), %%ecx \n"   // &(b+i*16) -> ecx
    "mov (%%ecx),%%ecx \n"              // *(b+i) -> ecx

    "cmp %[K], %%ecx \n"    // if k == ecx goto lable
    "je lable \n"

    "inc %%eax \n"          // i++
    "jmp Begin \n"

    "lable: \n"
    "mov %[b], %%ecx \n"                // &b -> ecx
    "lea (%%ecx, %%eax, 8), %%ecx \n"   //
    "lea 8(%%ecx, %%eax, 8), %%ecx \n"  // &(b+i*16).key
    "fldl (%%ecx) \n"                   // &(b+i*16).key -> st(0)
    "inc %%eax \n"                      // i++
    "add $1, %[F]\n"                    // F++
    "jmp Begin \n"



    "searchMin: \n"
    "cmp $0, %[F]\n"  // if st is empty
    "je noKeys\n"

    "cycle:\n"
    "cmp $1, %[F]\n"  // if in st only 1 element
    "je minKey\n"

    "add $-1, %[F]\n"           // F--
    "fcomi %%st(1), %%st(0)\n"  // st(1) ? st(0)
    "jbe compare\n"             // if st(0) < st(1) goto compare
    "fstpl %[MIN]\n"            // st(0) -> MIN
    "jmp cycle\n"
    "compare:\n"
    "fxch\n"                    // swap st(0) and st(1)
    "fstpl %[MIN]\n"            // st(0) -> MIN
    "jmp cycle\n"

    "minKey:\n"
    "fstpl %[MIN]\n"            // st(0) -> MIN

    "noKeys:\n"

    : [MIN]"=m"(minElem), [F]"+r"(f)
    : [b]"m"(b), [N]"m"(N), [K]"m"(k)
    : "cc", "%eax", "%ecx"
    );

    cout << "Min element by key=" << k << ":: ";
    if(minElem != -1){
        cout << minElem;
    }
    else{
        cout << "is not exist";
    }

    return 0;
}
