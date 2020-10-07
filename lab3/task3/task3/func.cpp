#include <iostream>
using namespace std;
extern "C" void func (int a, int b)
{
    std::cout << "Function\'s params:\na:: " << a <<"\nb:: "<< b;
}


