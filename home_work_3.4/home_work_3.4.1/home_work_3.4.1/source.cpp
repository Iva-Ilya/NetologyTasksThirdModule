#include <iostream>
#include <Windows.h>


int* create_array(int logical_size, int actual_size)
{
	int element{};
	int* array = new int [actual_size];
	for (int i = 0; i < logical_size; i++)
	{
		std::cout << "¬ведите array[" << i << "] = ";
		std::cin >> element;
		array[i] = element;

	}
	return array;
}

void print_array(int* array, int logical_size, int actual_size)
{
	std::cout << "ƒинамический массив: ";
	for (int i = 0; i < actual_size; i++)
	{
		if(i < logical_size)
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

void delete_array(int* array)
{
	delete[] array; // очищаем динамическую пам€ть
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int actual_size{}, logical_size{};
	std::cout << "¬ведите фактичеcкий размер массива: ";
	std::cin >> actual_size;
	std::cout << "¬ведите логический размер массива: ";
	std::cin >> logical_size;

	if (logical_size > actual_size)
	{
		std::cout << "ќшибка! Ћогический размер массива не может превышать фактический!" << std::endl;
	}
	else
	{
		int* array = create_array(logical_size, actual_size);
		print_array(array, logical_size, actual_size);
		delete[] array;
	}
	
	return 0;
}