#include <iostream>
#include <typeinfo>

using namespace std;

const int ARR_SIZE = 10;

int main()
{
    int a[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++){
        a[i] = i*i;
    }

    cout << "Size of int:: " << sizeof(int) << endl;
    cout << endl;


    for(int i = 0; i < ARR_SIZE; i++){
        cout << "Size of a[" << i << "]:: " << sizeof(a[i]) << endl;
    }
    cout << endl;


    for(int i = 0; i < ARR_SIZE; i++){
        cout << "Adress of a[" << i << "]:: " << &a[i] << endl;
    }
    cout << endl;


    cout << "Size of array array int[" << ARR_SIZE << "]:: " << sizeof(a) <<endl;
    cout << endl;


    cout << "Adress of beginning of array:: " << a << endl;
    for(int i = 0; i < ARR_SIZE; i++){
        cout << "Value of " << i << "-th element:: " << *(a+i) <<endl;
    }

    return 0;
}
