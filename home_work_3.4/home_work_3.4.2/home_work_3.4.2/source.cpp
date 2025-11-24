#include <iostream>
#include <Windows.h>


int* create_array(int logical_size, int actual_size)
{
	int element{};
	int* array = new int[actual_size];
	for (int i = 0; i < logical_size; i++)
	{
		std::cout << "Введите array[" << i << "] = ";
		std::cin >> element;
		array[i] = element;

	}
	return array;
}

void increase_size_array(int*& array, int& actual_size)
{
	int* new_array = new int[actual_size * 2];
	for (int i = 0; i < actual_size; i++)
	{
		new_array[i] = array[i];
	}
	delete[] array;
	array = new_array;
	actual_size = actual_size * 2;
}

void print_array(int* array, int logical_size, int actual_size)
{
	for (int i = 0; i < actual_size; i++)
	{
		if (i < logical_size)
		{
			std::cout << array[i] << " ";
		}
		else
		{
			std::cout << "_" << " ";
		}
	}
	std::cout << "\n";
}

void append_to_dynamic_array(int*& array, int& logical_size, int& actual_size)
{
	int element{};
	std::cout << "Введите элемент для добавления: ";
	std::cin >> element;
	while(element)
	{
		if (logical_size == actual_size)
		{
			increase_size_array(array, actual_size);
			array[logical_size] = element;
			logical_size++;
			std::cout << "Динамический массив: ";
			print_array(array, logical_size, actual_size);
		}
		else if (logical_size < actual_size)
		{
			array[logical_size] = element;
			logical_size++;
			std::cout << "Динамический массив: ";
			print_array(array, logical_size, actual_size);
		}
		std::cout << "Введите элемент для добавления: ";
		std::cin >> element;
	}
	std::cout << "Спасибо! Ваш массив: ";
	print_array(array, logical_size, actual_size);
}

void delete_array(int* array)
{
	delete[] array; // очищаем динамическую память
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int actual_size{}, logical_size{};
	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> actual_size;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logical_size;

	if (logical_size > actual_size)
	{
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
	}
	else
	{
		int* array = create_array(logical_size, actual_size);
		std::cout << "Динамический массив: ";
		print_array(array, logical_size, actual_size);
		append_to_dynamic_array(array, logical_size, actual_size);
		delete[] array;
	}

	return 0;
}