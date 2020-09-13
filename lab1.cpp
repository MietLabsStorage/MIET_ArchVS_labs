//CURENT PROBLEMS:
//
//in task1, task2 unwork bitset<16>
//
//iostream unwork with gcc (i use g++ now, but need read about this problem and dance with drums
//
//wtf is neg(x) in task3, task4, task5
//
//i dont done task 6, task8, task9
//
//

#include <stdio.h> 
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

/*Задание 1. Изучите, как интерпретируется одна и та же область памяти, если
она рассматривается как знаковое или беззнаковое число, а также как одно и то
же число записывается в различных системах счисления.
Необходимо сравнить:
а) беззнаковую интерпретацию переменной в шестнадцатеричной форме;
б) беззнаковую интерпретацию в десятичной форме;
в) знаковую интерпретацию в десятичной форме.
Для этого определите и запишите в отчёт десятичное, двоичное (16 бит) и 
шестнадцатеричное представления шестнадцатибитных чисел 𝑥 и 𝑦, 
а также беззнаковую интерпретацию этого представления в десятичном виде.

Для получения различных интерпретаций одного и того же кода в C++ можно
спользовать объединения или оператор reinterpret_cast. 
Шестнадцатеричное и десятичное представление можно получить, используя различные форматы
вывода. Шестнадцатеричный формат вывода не предусматривает знака, то есть
шестнадцатеричное представление знаковой переменной будет соответствовать её
беззнаковой интерпретации.*/
void task1(short x, short y)
{
	//http://cppstudio.com/post/319/
	cout << endl << "---TASK 1---" << endl;
	
	cout << ">>X::\n";
	cout << "Unsigned hex: " << hex << (unsigned short)x << endl;
	//cout << "Binary x16:   " << bitset<16>(x) << endl;
	cout << "Unsigned dec: " << dec << (unsigned short)x << endl;
	cout << "Signed dec:   " << dec << x << endl;
	
	cout << endl;
	
	cout << ">>Y::\n";
	cout << "Unsigned hex: " << hex << (unsigned short)y << endl;
	//cout << "Binary x16:   " << bitset<16>(y).to_string() << endl;
	cout << "Unsigned dec: " << dec << (unsigned short)y << endl;
	cout << "Signed dec:   " << dec << y << endl;
}

/*Найдите и выпишите в отчёт минимальное и максимальное 16-
битное число со знаком и без знака в формах представления (а), (б), (в) и в двоичной
форме (4 числа, каждое из которых представлено в 4 формах).
*/
void task2()
{
	//http://cppstudio.com/cat/309/317/
	cout << endl << "---TASK 2---" << endl;
	
	cout << ">>Unsigned short max::" << endl;
	cout << "Unsigned hex: " << hex << (unsigned short)USHRT_MAX << endl;
	//cout << "Binary x16:   " << bitset<16>(USHRT_MAX) << endl;
	cout << "Unsigned dec: " << dec << (unsigned short)USHRT_MAX << endl;
	cout << "Signed dec:   " << dec << USHRT_MAX << endl;
	
	cout << endl;
	
	cout << ">>Signed short max::" << endl;
	cout << "Unsigned hex: " << hex << (unsigned short)SHRT_MAX << endl;
	//cout << "Binary x16:   " << bitset<16>(SHRT_MAX) << endl;
	cout << "Unsigned dec: " << dec << (unsigned short)SHRT_MAX << endl;
	cout << "Signed dec:   " << dec << SHRT_MAX << endl;
	
	cout << endl;
	
	cout << ">>Unsigned short min::" << endl;
	cout << "Unsigned hex: " << hex << (unsigned short)0 << endl;
	//cout << "Binary x16:   " << bitset<16>(0) << endl;
	cout << "Unsigned dec: " << dec << (unsigned short)0 << endl;
	cout << "Signed dec:   " << dec << 0 << endl;
	
	cout << endl;
	
	cout << ">>Signed short min::" << endl;
	cout << "Unsigned hex: " << hex << (unsigned short)SHRT_MIN << endl;
	//cout << "Binary x16:   " << bitset<16>(SHRT_MIN) << endl;
	cout << "Unsigned dec: " << dec << (unsigned short)SHRT_MIN << endl;
	cout << "Signed dec:   " << dec << SHRT_MIN << endl;
}

/*Разработайте программу на языке C++, выполняющую над беззнаковыми шестнадцатибитными целыми числами следующие поразрядные операции
(результат должен печататься в десятичной и шестнадцатеричной формах):
– бинарные 𝑥 ∧ 𝑦 (конъюнкция), 𝑥 ∨ 𝑦 (дизъюнкция),
𝑥 ⊕ 𝑦 (сложение по модулю два);
– унарные ¬𝑥 (отрицание),neg(𝑥) (дополнение до двух, 𝑥 + neg(𝑥) = 2разрядность 𝑥);
– 𝑥 ≪ 𝑦 (логический сдвиг влево), 𝑥 ≫ 𝑦 (логический сдвиг вправо)
*/
void task3(unsigned short x, unsigned short y)
{
	cout << endl << "---TASK 3---" << endl;
	cout << ">> X^Y::\t dec: " << dec << (unsigned short)(x & y) << "\thex: " << hex << (unsigned short)(x & y) << endl;
	cout << ">> XvY::\t dec: " << dec << (unsigned short)(x | y) << "\thex: " << hex<< (unsigned short)(x | y) << endl;
	cout << ">> X^Y::\t dec: " << dec << (unsigned short)(x ^ y) << "\thex: " << hex<< (unsigned short)(x ^ y) << endl;
	cout << ">>  ~X::\t dec: " << dec << (unsigned short)(~x) << "\thex: " << hex << (unsigned short)(~x) << endl;
	//cout << ">>neg(X)::\t dec: " << dec <<  << "\thex: " << hex <<  << endl;
	cout << ">> X<<Y::\t dec: " << dec << (unsigned short)(x << y) << "\thex: " << hex << (unsigned short)(x << y) << endl;
	cout << ">> X>>Y::\t dec: " << dec << (unsigned short)(x >> y) << "\thex: " << hex << (unsigned short)(x >> y) << endl;
}

/*Измените в программе из задания 3 тип переменных на знаковый.
Объясните изменение (или неизменность) результата.
*/
void task4(signed short x, signed short y)
{
	cout << endl << "---TASK 4---" << endl;
	cout << ">> X^Y::\t dec: " << dec << (signed short)(x & y) << "\thex: " << hex << (signed short)(x & y) << endl;
	cout << ">> XvY::\t dec: " << dec << (signed short)(x | y) << "\thex: " << hex<< (signed short)(x | y) << endl;
	cout << ">> X^Y::\t dec: " << dec << (signed short)(x ^ y) << "\thex: " << hex<< (signed short)(x ^ y) << endl;
	cout << ">>  ~X::\t dec: " << dec << (signed short)(~x) << "\thex: " << hex << (signed short)(~x) << endl;
	//cout << ">>neg(X)::\t dec: " << dec <<  << "\thex: " << hex <<  << endl;
	cout << ">> X<<Y::\t dec: " << dec << (signed short)(x << y) << "\thex: " << hex << (signed short)(x << y) << endl;
	cout << ">> X>>Y::\t dec: " << dec << (signed short)(x >> y) << "\thex: " << hex << (signed short)(x >> y) << endl;
}

/*
Разработайте программу на языке C++ (или
дополните программу из задания 3), которая расширяет шестнадцатибитное представление числа 𝑥 до тридцатидвухбитного, рассматривая числа как
– знаковые (signed);
– беззнаковые (unsigned).
*/
void task5(signed short x)
{
	cout << endl << "---TASK 5---" << endl;
	cout << (signed short)x << " -> " << dec << "dec: " << (signed int)x << hex << "  hex: " << (signed int)x << endl;
}
void task5(unsigned short x)
{
	cout << endl << "---TASK 5---" << endl;
	cout << (unsigned short)x << " -> " << dec << "dec: " << (unsigned int)x << hex << "  hex: " << (unsigned int)x << endl;
}

/*
task 6
*/



/*При помощи оператора sizeof выясните, сколько байтов
занимают переменные следующих типов: char, bool, wchar_t, short, int,
long, long long, float, double, long double, size_t, ptrdiff_t,
void*. Результаты оформите в отчёте в виде таблицы, указывая для каждого типа
его назначение.
Для выполнения единообразных действий над переменными различных типов
используются макросы препроцессора C или шаблоны C++.
Проверьте, соответствуют ли размеры типов современному стандарту C++
*/
void task7()
{
	cout << endl << "---TASK 7---" << endl;
	cout << "char:        " << sizeof(char) << endl;
	cout << "bool:        " << sizeof(bool) << endl;
	cout << "wchar_t:     " << sizeof(wchar_t) << endl;
	cout << "short:       " << sizeof(short) << endl;
	cout << "int:         " << sizeof(int) << endl;
	cout << "long:        " << sizeof(long) << endl;
	cout << "long long:   " << sizeof(long long) << endl;
	cout << "float:       " << sizeof(float) << endl;
	cout << "double:      " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	cout << "size_t:      " << sizeof(size_t) << endl;
	cout << "ptrdiff_t:   " << sizeof(ptrdiff_t) << endl;
	cout << "void*:       " << sizeof(void*) << endl;
}

/*
*/

int main()
{
	short x = (-1)*pow(2, 15);
	short y = pow(2, 15);
	
	task1(x,y);
	task2();
	task3(0xFFEE,0x0001);
	task3(0x000E,0x0003);
	task4(0xFFEE,0x0001);
	task4(0x000E,0x0003);
	task5((signed short)0xF123);
	task5((unsigned short)0xF123);
	
	task7();

	return 0;
}