#include <stdio.h> 
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>

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
void task1(int32_t x,int32_t y)
{
	//http://cppstudio.com/post/319/
	cout << endl << "---TASK 1---" << endl;
	
	cout << ">>X::\n";
	cout << "Unsigned hex: " << hex << (uint16_t)x << endl;
	cout << "Binary x16:   " << bitset<16>(x) << endl;
	cout << "Unsigned dec: " << dec << (uint16_t)x << endl;
	cout << "Signed dec:   " << dec << (int16_t)x << endl;
	
	cout << endl;
	
	cout << ">>Y::\n";
	cout << "Unsigned hex: " << hex << (uint16_t)y << endl;
	cout << "Binary x16:   " << bitset<16>(y) << endl;
	cout << "Unsigned dec: " << dec << (uint16_t)y << endl;
	cout << "Signed dec:   " << dec << (int16_t)y << endl;
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
	cout << "Unsigned hex: " << hex << (uint16_t)USHRT_MAX << endl;
	cout << "Binary x16:   " << bitset<16>(USHRT_MAX) << endl;
	cout << "Unsigned dec: " << dec << (uint16_t)USHRT_MAX << endl;
	cout << "Signed dec:   " << dec << (int16_t)USHRT_MAX << endl;
	
	cout << endl;
	
	cout << ">>Signed short max::" << endl;
	cout << "Unsigned hex: " << hex << (uint16_t)SHRT_MAX << endl;
	cout << "Binary x16:   " << bitset<16>(SHRT_MAX) << endl;
	cout << "Unsigned dec: " << dec << (uint16_t)SHRT_MAX << endl;
	cout << "Signed dec:   " << dec << (int16_t)SHRT_MAX << endl;
	
	cout << endl;
	
	cout << ">>Unsigned short min::" << endl;
	cout << "Unsigned hex: " << hex << (uint16_t)0 << endl;
	cout << "Binary x16:   " << bitset<16>(0) << endl;
	cout << "Unsigned dec: " << dec << (uint16_t)0 << endl;
	cout << "Signed dec:   " << dec << (int16_t)0 << endl;
	
	cout << endl;
	
	cout << ">>Signed short min::" << endl;
	cout << "Unsigned hex: " << hex << (uint16_t)SHRT_MIN << endl;
	cout << "Binary x16:   " << bitset<16>(SHRT_MIN) << endl;
	cout << "Unsigned dec: " << dec << (uint16_t)SHRT_MIN << endl;
	cout << "Signed dec:   " << dec << (int16_t)SHRT_MIN << endl;
}

/*Разработайте программу на языке C++, выполняющую над беззнаковыми шестнадцатибитными целыми числами следующие поразрядные операции
(результат должен печататься в десятичной и шестнадцатеричной формах):
– бинарные 𝑥 ∧ 𝑦 (конъюнкция), 𝑥 ∨ 𝑦 (дизъюнкция),
𝑥 ⊕ 𝑦 (сложение по модулю два);
– унарные ¬𝑥 (отрицание),neg(𝑥) (дополнение до двух, 𝑥 + neg(𝑥) = 2разрядность 𝑥);
– 𝑥 ≪ 𝑦 (логический сдвиг влево), 𝑥 ≫ 𝑦 (логический сдвиг вправо)
*/
void task3(int32_t x, int32_t y)
{
	cout << endl << "---TASK 3---" << endl;
	cout << ">> X&Y::\t dec: " << dec << (uint16_t)(x & y) << "\thex: " << hex << (uint16_t)(x & y) << endl;
	cout << ">> X|Y::\t dec: " << dec << (uint16_t)(x | y) << "\thex: " << hex<< (uint16_t)(x | y) << endl;
	cout << ">> X^Y::\t dec: " << dec << (uint16_t)(x ^ y) << "\thex: " << hex<< (uint16_t)(x ^ y) << endl;
	cout << ">>  ~X::\t dec: " << dec << (uint16_t)(~x) << "\thex: " << hex << (uint16_t)(~x) << endl;
	cout << ">> neg(X)::\t dec: " << dec << (uint16_t)(pow(2,16) - x) << "\thex: " << hex << (uint16_t)(pow(2,16) - x) << endl;
	cout << ">> X<<Y::\t dec: " << dec << (uint16_t)(x << y) << "\thex: " << hex << (uint16_t)(x << y) << endl;
	cout << ">> X>>Y::\t dec: " << dec << (uint16_t)(x >> y) << "\thex: " << hex << (uint16_t)(x >> y) << endl;
}

/*Измените в программе из задания 3 тип переменных на знаковый.
Объясните изменение (или неизменность) результата.
*/
void task4(int32_t x, int32_t y)
{
	cout << endl << "---TASK 4---" << endl;
	cout << ">> X&Y::\t dec: " << dec << (int16_t)(x & y) << "\thex: " << hex << (int16_t)(x & y) << endl;
	cout << ">> X|Y::\t dec: " << dec << (int16_t)(x | y) << "\thex: " << hex<< (int16_t)(x | y) << endl;
	cout << ">> X^Y::\t dec: " << dec << (int16_t)(x ^ y) << "\thex: " << hex<< (int16_t)(x ^ y) << endl;
	cout << ">>  ~X::\t dec: " << dec << (int16_t)(~x) << "\thex: " << hex << (int16_t)(~x) << endl;
	cout << ">> neg(X)::\t dec: " << dec << (int16_t)(pow(2,16) - x) << "\thex: " << hex << (int16_t)(pow(2,16) - x) << endl;
	cout << ">> X<<Y::\t dec: " << dec << (int16_t)(x << y) << "\thex: " << hex << (int16_t)(x << y) << endl;
	cout << ">> X>>Y::\t dec: " << dec << (int16_t)(x >> y) << "\thex: " << hex << (int16_t)(x >> y) << endl;
}

/*
Разработайте программу на языке C++ (или
дополните программу из задания 3), которая расширяет шестнадцатибитное представление числа 𝑥 до тридцатидвухбитного, рассматривая числа как
– знаковые (signed);
– беззнаковые (unsigned).
*/
void task5(int16_t x)
{
	cout << endl << "---TASK 5---" << endl;
	cout << (int16_t)x << " -> " << dec << "dec: " << (int32_t)x << hex << "  hex: " << (int32_t)x << endl;
}
void task5(uint16_t x)
{
	cout << endl << "---TASK 5---" << endl;
	cout << (uint16_t)x << " -> " << dec << "dec: " << (uint32_t)x << hex << "  hex: " << (uint32_t)x << endl;
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
	task1(-pow(2, 15),pow(2, 15));
	task2();
	task3(0xFFEE,0x0001);
	task3(0x000E,0x0003);
	task4(0xFFEE,0x0001);
	task4(0x000E,0x0003);
	task5((int16_t)0xF123);
	task5((uint16_t)0xF123);
	
	task7();

	return 0;
}
