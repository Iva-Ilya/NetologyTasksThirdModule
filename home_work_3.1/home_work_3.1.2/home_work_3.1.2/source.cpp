#include <iostream>
#include <Windows.h>

int func1(int* any_arr, int& N, int& user_num)
{
	int left = 0;
	int right = N ;
	int middle{};
	int res = N;
	int count = 0;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (middle % 2 == 1)
		{ middle++; }
		if (any_arr[middle] > user_num)
		{
			//res = middle;
			//res--;
			right = middle - 1;
		}
		if (any_arr[middle] < user_num)
		{
			res = middle;
			left = middle + 1;
		}
		if (any_arr[middle] == user_num)
		{
			res = middle;
			break;
		}
		//if (any_arr[middle] == user_num && count == 0)
		//{
		//	res = middle;
		//	//res;
		//	break;
		//}
		count++;
	}
	return res;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int N = 9;
	int arr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int user_num{};

	std::cout << "Введите точку отсчета: ";
	std::cin >> user_num;
	std::cout << "Количество элементов в массиве больших, чем " << user_num << ": " << func1(arr, N, user_num) << std::endl;

	return 0;
}