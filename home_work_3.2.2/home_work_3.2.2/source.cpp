#include <iostream>
#include <Windows.h>

int fibonachi(int n, int prev2, int prev1) 
{
    // std::cout << number << std::endl;										// Only for debug
    if (n == 0) {
        return prev2;
    }

    if (n == 1) {
        return prev1;
    }

    return fibonachi(n - 1, prev1, prev2 + prev1);
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
    {  std::cout << fibonachi(i, 0, 1) << " "; }

    return 0;
}