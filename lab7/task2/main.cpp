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
    "movl $1, %%eax \n"  //counter
    "movl %[a], %%edx \n"  //записываем  адрес? нулевого элемента в edx берем за основу как минимум начальный
    "movl (%%edx), %%edx \n" //записываем значение 

    "Begin: \n"
    "cmpl %[N], %%eax \n"   //while < N
    "je End \n"

    "movl %[a], %%ecx \n"
    "leal (%%ecx, %%eax, 4), %%ecx \n"   // записать адрес следующего элемента массива
    "movl (%%ecx),%%ecx \n" //записать значение

    "cmpl %%edx, %%ecx \n"   //проверка на минимум, если не выполняется, то прыгаем на лейбл и прибавляем счетчик
    "jnbe lable \n"

    "movl %%ecx, %%edx \n" ///если меньше минимума, то записываем новый минимум в edx

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
