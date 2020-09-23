#include <stdio.h> 
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <cstddef>
#include <iomanip>
#include <string>


using namespace std;

void showForTask_1_and_2(string showName, int32_t num)
{
	cout << ">>" << showName << "::\n";
	cout << "Unsigned hex: " << hex << (uint16_t)num << endl;
	cout << "Binary x16:   " << bitset<16>(num) << endl;
	cout << "Unsigned dec: " << dec << (uint16_t)num << endl;
	cout << "Signed dec:   " << dec << (int16_t)num << endl;
}

template<typename T> 
void showForTask7(string typeName)
{
	cout << typeName << ":\t" << sizeof(T) << endl;
}


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
	cout << endl << "---TASK 1---" << endl;
	showForTask_1_and_2("X", x);
	cout << endl;
	showForTask_1_and_2("Y", y);
}

/*Найдите и выпишите в отчёт минимальное и максимальное 16-
битное число со знаком и без знака в формах представления (а), (б), (в) и в двоичной
форме (4 числа, каждое из которых представлено в 4 формах).
*/
void task2()
{
	cout << endl << "---TASK 2---" << endl;
	showForTask_1_and_2("Unsigned short max", USHRT_MAX);
	cout << endl;
	showForTask_1_and_2("Signed short max", SHRT_MAX);
	cout << endl;
	showForTask_1_and_2("Unsigned short min", 0);
	cout << endl;
	showForTask_1_and_2("Signed short min", SHRT_MIN);
}

/*Разработайте программу на языке C++, выполняющую над беззнаковыми шестнадцатибитными целыми числами следующие поразрядные операции
(результат должен печататься в десятичной и шестнадцатеричной формах):
– бинарные 𝑥 ∧ 𝑦 (конъюнкция), 𝑥 ∨ 𝑦 (дизъюнкция),
𝑥 ⊕ 𝑦 (сложение по модулю два);
– унарные ¬𝑥 (отрицание),neg(𝑥) (дополнение до двух, 𝑥 + neg(𝑥) = 2разрядность 𝑥);
– 𝑥 ≪ 𝑦 (логический сдвиг влево), 𝑥 ≫ 𝑦 (логический сдвиг вправо)
*/
/*Измените в программе из задания 3 тип переменных на знаковый.
Объясните изменение (или неизменность) результата.
*/
template<typename T> 
void task_3_4(T x, T y, int task)
{
	cout << endl << "---TASK " << task << "---" << endl;
	cout << ">> X&Y::\t dec: " << dec << (T)(x & y) << "\thex: " << hex << (T)(x & y) << endl;
	cout << ">> X|Y::\t dec: " << dec << (T)(x | y) << "\thex: " << hex<< (T)(x | y) << endl;
	cout << ">> X^Y::\t dec: " << dec << (T)(x ^ y) << "\thex: " << hex<< (T)(x ^ y) << endl;
	cout << ">>  ~X::\t dec: " << dec << (T)(~x) << "\thex: " << hex << (T)(~x) << endl;
	cout << ">> neg(X)::\t dec: " << dec << (T)(pow(2,16) - x) << "\thex: " << hex << (T)(pow(2,16) - x) << endl;
	cout << ">> X<<Y::\t dec: " << dec << (T)(x << y) << "\thex: " << hex << (T)(x << y) << endl;
	cout << ">> X>>Y::\t dec: " << dec << (T)(x >> y) << "\thex: " << hex << (T)(x >> y) << endl;
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


template<typename T>
void task6_1(const T &x)
{
	cout << endl << "---TASK 6---" << endl;
	const unsigned char *p = reinterpret_cast<const unsigned char *>(&x);
	cout << "Type: " << typeid(x).name() 
	<< " Value: " << x << endl 
	<< "Size: " << sizeof(x) << endl 
	<< "Dump: " << hex << uppercase << setfill('0');
	for(size_t i = 0; i < sizeof(x); ++i)
	{
		cout << setw(2)<< static_cast<unsigned>(*(p+i)) << " ";
	}
	cout << dec << endl << endl;
 }

template < typename T>
 void task6_2(T * px, int CellCount)
 {
	 const unsigned char* p
		 = reinterpret_cast<const unsigned char*>(px);
	 size_t BytesCount = sizeof(*px) * CellCount;
	
		 cout << "Type: " << typeid(px).name()
		 << " Value: " << px << endl
		 << " Size: " << sizeof(px) << endl
		 << "Dump: " << hex << uppercase << setfill('0');
	
		 for (size_t i = 0; i < BytesCount; ++i)
		 {
		 cout << setw(2) << static_cast<unsigned>(*(p + i)) << " ";
		 }
	 cout << dec << endl << endl;
	 }



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
	showForTask7<char>("char");
	showForTask7<bool>("bool");
	showForTask7<wchar_t>("wchar_t");
	showForTask7<short>("short");
	showForTask7<int>("int");
	showForTask7<long>("long");
	showForTask7<long long>("long long");
	showForTask7<float>("float");
	showForTask7<double>("double");
	showForTask7<long double>("long double");
	showForTask7<size_t>("size_t");
	showForTask7<ptrdiff_t>("ptrdiff_t");
	showForTask7<void*>("void*");
}


int main()
{	
	//task1(-pow(2, 15),pow(2, 15));
	//task2();
	//task_3_4<uint16_t>(0xFFEE,0x0001,3);
	//task_3_4<uint16_t>(0x000E,0x0003,3);
	//task_3_4<int16_t>(0xFFEE,0x0001,4);
	//task_3_4<int16_t>(0x000E,0x0003,4);
	//task5((int16_t)0xF123);
	//task5((uint16_t)0xF123);
	//task6<int64_t>(0x12345678);
	task7();

	
	char* s_1 = (char*)"abcd";
	char* s_2 = (char*)"абвг";

	wchar_t* s_3 = (wchar_t*)"abcd";
	wchar_t* s_4 = (wchar_t*)"абвг";

	task6_1(0x12345678);
	
	task6_2(s_1, 5);
	task6_2(s_2, 5);
	task6_2(s_3, 5);
	task6_2(s_4, 5);
cout << "+++" << (int)'a';

	return 0;
}
