#include <iostream>
#include <locale>
#include <array>
#include <random> // дл€ генератора случ чисел (см ниже)
#include <Windows.h> // не работает setConsole
using namespace::std;

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int array[101];
	int buf = 0;

	// ¬ариант 1 - зерно из класса random_device из файла <random>
	random_device system_rand;
	int seed = system_rand();

	// ¬ариант 2 - текущее врем€ как зерно
	//int seed = time(NULL);

	srand(seed);
	// «аполн€ем массив случ числами и выводим в консоль
	cout << "Ёлементы случайного массива: " << endl << endl;
	for (int i = 0; i < 100; i++)
	{
		array[i] = rand() % ((100) + 1);
		cout << array[i] << " ";
	}
	// —ортировка пузырьком
	for (int count = 1; count > 0; )
	{
		for (int i = 1; i < 100; i++)
		{			
			if (array[i-1] > array[i])
			{
				buf = array[i - 1];
				array[i - 1] = array[i];
				array[i] = buf;
			}
			count++;
		}
	}
	cout << endl << endl << "Ёлементы отсортированного массива: " << endl << endl;
	for (int j = 0; j < 100; j++)
	{
		cout << array[j] << " ";
	}
}