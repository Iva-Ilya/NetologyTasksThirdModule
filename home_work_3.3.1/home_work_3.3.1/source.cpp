#include <iostream>
#include <Windows.h>

// Функция создания массива
int* create_array(int size_array)
{
    int* new_array = new int[size_array];  
    for (int i = 0; i < size_array; i++)
    {
        new_array[i] = 0;  
    }
    return new_array;
}

void mergeSort(int* a_array, int first, int last)
{
    if (last - first < 1)  
    {
        return;
    }

    if (last - first == 1)  
    {
        if (a_array[first] > a_array[last])
        {
            int c = a_array[first];
            a_array[first] = a_array[last];
            a_array[last] = c;
        }
        return;
    }

    int mid = first + (last - first) / 2;
    mergeSort(a_array, first, mid);
    mergeSort(a_array, mid + 1, last);

    int size = last - first + 1;
    int* temp = create_array(size);  

    int b1 = first;
    int e1 = mid;      
    int b2 = mid + 1;
    int e2 = last;

    int i = 0;

    while (b1 <= e1 && b2 <= e2)
    {
        if (a_array[b1] <= a_array[b2])
        {
            temp[i] = a_array[b1];
            ++b1;
        }
        else
        {
            temp[i] = a_array[b2];
            ++b2;
        }
        ++i;
    }

    // Копируем оставшиеся элементы из первой части
    while (b1 <= e1)
    {
        temp[i] = a_array[b1];
        ++b1;
        ++i;
    }

    // Копируем оставшиеся элементы из второй части
    while (b2 <= e2)
    {
        temp[i] = a_array[b2];
        ++b2;
        ++i;
    }

    // Копируем отсортированные элементы обратно в исходный массив
    for (int j = 0; j < size; ++j)
    {
        a_array[first + j] = temp[j];  
    }

    delete[] temp;  
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n{};
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    int* a = create_array(n);

    // Заполняем массив случайными числами
    std::cout << "Исходный массив:\n";
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        std::cout << a[i] << "\t";
    }
    std::cout << "\n";

    mergeSort(a, 0, n - 1);

    std::cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << "\n";

    delete[] a; 

    return 0;
}