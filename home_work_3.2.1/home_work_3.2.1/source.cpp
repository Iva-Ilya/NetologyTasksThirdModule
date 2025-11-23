#include <iostream>
#include <Windows.h>

int fibonacci(int number)
{
	// std::cout << number << std::endl;										// Only for debug
	if (number == 0)
		return 0;
	if (number == 1)
		return 1;
	return fibonacci(number - 2) + fibonacci(number - 1);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number{};
	std::cout << "¬ведите число: " << std::endl;
	std::cin >> number;
	// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987 - значение чисел ‘ибоначи
	// 0, 1, 2, 3, 4, 5, 6,  7,  8,  9,  10,  11, 12, 13,  14,  15,  16 - пор€дковый номер
	std::cout << std::endl;
	for (int i = 0; i <= number; i++)
	{ std::cout << fibonacci(i) << " "; }

	return 0;
}