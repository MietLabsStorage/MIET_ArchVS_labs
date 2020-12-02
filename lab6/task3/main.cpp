#include <iostream>

using namespace std;

int main()
{
    int i, first, second, current;
    int N;
    cout << "Fibonacci numbers\n";
    cout << "Write N: ";
    cin >> N;
    asm
    (
    "xor %[I], %[I]\n"      // i = 0

    "begin_iteration: \n"   // loop begin
    "addl $1, %[I]\n"       //i++

    "cmpl $1, %[I]\n"       // ..
    "je if1\n"              // if i = 1 goto if1
    "cmpl $2, %[I]\n"       // ..
    "je if2\n"              // if i = 2 goto if2
    "jmp ifMore\n"          // goto ifMore

    "if1:\n"                // ..
    "movl $1, %[C]\n"       // cur = 1
    "jmp compare\n"         // goto compare

    "if2:\n"                // ..
    "movl $1, %[C]\n"       // cur = 1
    "movl %[C], %[S]\n"     // sec = cur = 1
    "jmp compare\n"         // goto compare

    "ifMore:\n"             // ..
    "movl %[S], %[F]\n"     // fst = sec
    "movl %[C], %[S]\n"     // sec = cur
    "movl %[F], %[C]\n"     // cur = fst
    "addl %[S], %[C]\n"     // cur += sec

    "compare: \n"           // ..
    "cmpl %[I], %[N]\n"     // i ? N
    "jne begin_iteration\n"  // i <> N

    : [I]"+r"(i), [F]"+r"(first), [S]"+r"(second), [C]"+r"(current)
    : [N]"r"(N)
    : "cc"
    );
    //cout << "C: " << current << endl;
    //cout << "S: " << second << endl;
    //cout << "F: " << first << endl;
    //cout << "I: " << i << endl;
    //cout << "N: " << N << endl;
    cout << N << "th num is " << current;
    return 0;
}
