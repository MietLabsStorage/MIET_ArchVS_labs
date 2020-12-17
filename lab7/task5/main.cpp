#include <iostream>

using namespace std;

int main()
{
    int N;
    cout << "Fibbonachi arr size:: ";
    cin >> N;
    if(N <= 0){
        cout << "Arr cant be less or equal zero-size";
        return 0;
    }
    int i;
    int first, second;
    int* arr = new int[N];

    asm
    (
    "xorl %[I], %[I]\n"     // счетчик

    "begin_iteration: \n"
    "cmpl $0, %[I]\n"       // if i == 0
    "je if1\n"              // goto if1
    "cmpl $1, %[I]\n"       // if i == 1
    "je if2\n"              // goto if2
    "jmp ifMore\n"          // goto ifMore

    "if1:\n"                            // ..
    "movl $1, %[S]\n"                   // sec = 1
    "movl %[S], (%[ARR], %[I], 4)\n"    // arr[i] = sec
    "jmp compare\n"                     // goto compare

    "if2:\n"                            // ..
    "movl $1, %[S]\n"                   // sec = 1
    "movl %[S], %[F]\n"                 // fst = sec = 1
    "movl %[S], (%[ARR], %[I], 4)\n"    // arr[i] = sec
    "jmp compare\n"                     // goto compare

    "ifMore:\n"                         // ..
    "addl %[F], %[S]\n"                 // sec = sec + fst
    "subl %[S], %[F]\n"                 // fst = fst - sub
    "negl %[F]\n"                       // fst = -fst
    "movl %[S], (%[ARR], %[I],4)\n"     // arr[i] = sec

    "compare:\n"
    "addl $1, %[I]\n"                   //i++
    "cmpl %[I], %[N]\n"                 // i ? N
    "jne begin_iteration\n"             // i <> N

    : [I]"+r"(i), [F]"+r"(first), [S]"+r"(second)
    : [N]"r"(N), [ARR]"r"(arr)
    : "cc", "memory"
    );

    cout << "Fibbonachi arr:: ";
    for(int j = 0; j < N; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
    return 0;
}
