#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));
    long long N = 0;
    cout << "Size of array:: ";
    cin >> N;
    long long* a = new long long[N];
    cout << "Array:: ";
    for(int i = 0; i < N; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    long long minElem = a[0];

    asm
    (
    "mov $1, %%rax \n"  //counter
    "mov %[a], %%rdx \n"  //записываем  адрес нулевого элемента в rdx, берем за основу как минимум начальный

    "mov (%%rdx), %%rdx \n" //разыменовываем адрес, лежащий в rdx, и помещаем его значение в rdx

    "Begin: \n"
    "cmp %[N], %%rax \n"   //while  != N
    "je End \n"

    "mov %[a], %%rcx \n" //записываем адрес нулевого элемента в rcx
    "lea (%%rcx, %%rax, 8), %%rcx \n"   // записываем в rcx  указатель на i элемент
    "mov (%%rcx),%%rcx \n" //разыменовываем значение i  элемента

    "cmp %%rdx, %%rcx \n"   //сравниваем минимум со значением  i элемента (если  i элемент больше текущего минимального)
    "jnbe notMin \n"

    "mov %%rcx, %%rdx \n" //если текущий минимум больше i элемента, то перезаписываем текущий минимальный элемент

    "notMin: \n"
    "inc %%rax \n" //увеличиваем i на 1 и переходим к следующей итерации
    "jmp Begin \n"

    "End: \n"
    "mov %%rdx, %[MIN] \n"

    : [MIN]"+m" (minElem)
    : [a]"m"(a), [N]"m"(N)
    : "cc", "%rax", "%rdx", "%rcx"
    );

    cout<<"Min element:: "<< minElem;

    return 0;
}
