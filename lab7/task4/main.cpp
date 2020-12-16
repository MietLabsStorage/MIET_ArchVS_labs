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
    long long N;
    cout << "Size of b:: ";
    cin>> N;
    struct Pair* b = new struct Pair[N] ;
    cout<<"Key:: ";
    long long k = 0;
    cin >> k;
    for (int i = 0; i < N; i++)
    {
        b[i].key = rand() % 3 + k;
        b[i].value = rand() % 100 / 3.0;
        cout << "{" << b[i].key << "; " << b[i].value << "} ";
    }
    cout << endl;
    double Min = -1;
    long long f = 0;
    asm (
    "mov $0, %%rax \n"

    "Begin: \n"
    "cmp %[N], %%rax \n" //если   N = rax перейти по метке(выйти из цикла)
    "je searchMin \n"

    "mov %[b], %%rcx \n"
    "lea (%%rcx, %%rax, 8), %%rcx \n"
    "lea (%%rcx, %%rax, 8), %%rcx \n"  //перемещаемся к след структуре для сравнения ключа
    "mov (%%rcx),%%rcx \n"


    "cmp %[K], %%rcx \n"  //если ключ извне равен ключу в структуре, то переходим по метке
    "je lable \n"

    "inc %%rax \n" //увеличиваем счетчик и прыгаем в начало цикла
    "jmp Begin \n"

    "lable: \n"
    "mov %[b], %%rcx \n"
    "lea (%%rcx, %%rax, 8), %%rcx \n"
    "lea 8(%%rcx, %%rax, 8), %%rcx \n" //берем адрес вещественного числа
    "fldl (%%rcx) \n"  //кладем в стек
    "inc %%rax \n" //увеличиваем счетчик цикла
    "add $1, %[F]\n" //увеличиваем счетчик количества элементов в стеке
    "jmp Begin \n" //переходим в начало цикла




    "searchMin: \n"
    "cmp $0, %[F]\n"  //сравниваем количество чисел в стеке с 0
    "je noKeys\n"

    "cycle:\n"
    "cmp $1, %[F]\n"  //сравниваем количество чисел в стеке с 1
    "je minKey\n"

    "add $-1, %[F]\n"   //вычитаем 1 из счетчика количества элементов в стеке
    "fcomi %%st(1), %%st(0)\n"//сравниваем числа, лежащие на верхушке стека
    "jbe compare\n"//  st(0) < st(1)
    "fstpl %[MIN]\n"
    "jmp cycle\n"
    "compare:\n"
    "fxch\n"        //меняем местами st(1) st(0)  ( всегда на вершину стека кладем наименьший из 2 ух элементов на)
    "fstpl %[MIN]\n" //выталкиваем st(0)
    "jmp cycle\n"// возващаемся в начало цикла

    "minKey:\n"
    "fstpl %[MIN]\n"

    "noKeys:\n"

    : [MIN]"=m" (Min), [F]"+r"(f)
    : [b]"m"(b), [N]"m"(N), [K]"m"(k)
    : "cc", "%rax", "%rcx", "%rdx"
    );

    /*if(Min == -1){
        cout<<"\nNo key = "<<k<<" elements\n";
    }
    else{
        cout<<"\nMinimum:"<<Min<<endl;
    }*/
    cout << Min << endl;

    return 0;
}
