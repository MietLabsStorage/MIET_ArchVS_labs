#include <iostream>

using namespace std;

template <typename T>
T task_a(T x){
    int mod = 4;
    T res = x % mod;
    return res;
}

template <typename T>
T task_b (T x){
    static int res = 0;
    res = x * x;
    return res;
}

template <typename T>
T task_c(T x){
    int res;
    if (x >= 0)
        res = 13;
    else
        res = 7;
    return res;
}
int main()
{
    int x = 8;
    int  y = task_b(x);
    return 0;
}
