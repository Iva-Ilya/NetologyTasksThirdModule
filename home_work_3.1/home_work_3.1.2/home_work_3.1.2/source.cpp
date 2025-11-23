#include <iostream>
#include <Windows.h>

int countElementsGreaterThan(int* sorted_arr, int size, int num) {
    int left = 0;
    int right = size - 1; 
    int result_index = size;  //Если все элементы ≤ num, возвращаем size

    while (left <= right) 
    {  
        int middle = left + (right - left) / 2;  

        if (sorted_arr[middle] > num) 
        {
            // Элемент > num, но может есть меньшие элементы
            result_index = middle;
            right = middle - 1;
        }
        else 
        {
            // Элемент ≤ num, ищем в правой части
            left = middle + 1;
        }
    }

    // Количество элементов, больших чем num = size - result_index
    return size - result_index;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 9;
    int arr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int user_num{};

    std::cout << "Введите точку отсчета: ";
    std::cin >> user_num;

    int count = countElementsGreaterThan(arr, size, user_num);
    std::cout << "Количество элементов в массиве больших, чем " << user_num << ": " << count << std::endl;

    return 0;
}