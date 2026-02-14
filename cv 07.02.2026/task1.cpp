#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");

    float a, b;
    char c;

    cout << "Введите два числа и операцию (+, -, *, /) в одну строку: ";
    cin >> a >> b >> c;

    if (c == '+')
        cout << "Результат: " << a + b;
    else if (c == '-')
        cout << "Результат: " << a - b;
    else if (c == '*')
        cout << "Результат: " << a * b;
    else if (c == '/')
        cout << "Результат: " << a / b;
    else
        cout << "Неправильный ввод.";

    return 0;
}