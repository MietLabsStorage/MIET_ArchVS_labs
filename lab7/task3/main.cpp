#include <iostream>
#include <typeinfo>

using namespace std;

const int ARR_SIZE = 10;

struct Pair{
    int key;
    double value;
};

int main()
{
    struct Pair b[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++){
        b[i].key = i*i;
        b[i].value = i/3.0;
        cout << "{" << b[i].key << "; " << b[i].value << "} ";
    }
    cout << endl << endl;

    cout << "Size of struct Pair:: " << sizeof(struct Pair) << endl;
    cout << "Size of key in struct Pair:: " << sizeof(b[0].key) << endl;
    cout << "Size of value in struct Pair:: " << sizeof(b[0].value) << endl;
    cout << endl;


    for(int i = 0; i < ARR_SIZE; i++){
        cout << "Adress of b[" << i << "]:: \t" << &b[i] << endl;
        cout << "Adress of b[" << i << "].key:: \t" << &b[i].key << endl;
        cout << "Adress of b[" << i << "].value:: \t" << &b[i].value << endl;
        cout << endl;
    }

    cout << "Size of array array int[" << ARR_SIZE << "]:: " << sizeof(b) <<endl;
    cout << endl;


    cout << "Adress of beginning of array:: " << b << endl;
    for(int i = 0; i < ARR_SIZE; i++){
        //cout << "Key of " << i << "-th element:: " << *(b.key+i) <<endl;
        //cout << "Value of " << i << "-th element:: " << *(b.value+i) <<endl;
    }

    return 0;
}
