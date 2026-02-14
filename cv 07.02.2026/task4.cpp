#include <iostream>
#include <random>
#include <time.h>
#include <locale.h>
using namespace std;

float fpart(double x)
{
    return abs(x - (int)x) * 10000;
}

int main()
{
    setlocale(LC_ALL,"Russian");

    int seed = time(NULL);
    srand(seed);

    cout << "Случайно сгенерированные дробные числа от -100 до 100" << endl;

    double Nums[10];
    for (int i{0}; i < 10; i++)
    {
        Nums[i] = rand() % 201 - 100 + (rand() % 10000) / 10000.0; //до 4-х знаков после запятой
        cout << Nums[i] << endl;
    }

    double save;
    for (int i{0}; i<10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (fpart(Nums[j]) < fpart(Nums[i]))
            {
                save = Nums[i];
                Nums[i] = Nums[j];
                Nums[j] = save;
            }
        }
    }

    cout << endl << "Эти же числа, сортированные по возрастанию дробной части" << endl;
    for (int i{0}; i<10; i++)
        cout << Nums[i] << endl;

    return 0;
}