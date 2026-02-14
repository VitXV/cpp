#include <iostream>
#include <random>
#include <time.h>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");

    int seed = time(NULL);
    srand(seed);
    int mx = 10;

    int n;
    cout << "Введите размер поля (n*n) для генерации спирали из случайных чисел: ";
    cin >> n;
    cout << endl;

    int* A = new int[n * n];

    for (int i = 0; i < n * n - 1; i++)
        A[i] = rand() % mx;

    A[n * n - 1] = 0;

    int swap;
    for (int i = 0; i < n * n - 1; i++)
    {
        for (int j = i + 1; j < n * n - 1; j++)
        {
            if (A[i] > A[j])
            {
                swap = A[i];
                A[i] = A[j];
                A[j] = swap;
            }
        }
    }

    int** field = new int* [n];
    for (int i = 0; i < n; i++)
        field[i] = new int[n];

    for (int j = 0; j < n;j++)
        field[0][j] = A[j];

    int A_packed = n - 1;
    int i = 0, j = n - 1;
    int steps = n - 1;
    int save_i, save_j;
    bool reverse_polarity = false;
    while (A_packed < n* n - 2)
    {
        if (reverse_polarity)
        {
            save_i = i;
            for (;i > save_i - steps;)
            {
                A_packed += 1;
                i -= 1;
                field[i][j] = A[A_packed];
            }
            save_j = j;
            for (;j < save_j + steps;)
            {
                A_packed += 1;
                j += 1;
                field[i][j] = A[A_packed];
            }
            reverse_polarity = false;
            steps -= 1;
        }
        else
        {
            save_i = i;
            for (;i < save_i + steps;)
            {
                A_packed += 1;
                i += 1;
                field[i][j] = A[A_packed];
            }
            save_j = j;
            for (;j > save_j - steps;)
            {
                A_packed += 1;
                j -= 1;
                field[i][j] = A[A_packed];
            }
            reverse_polarity = true;
            steps -= 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << field[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] field[i];

    delete[] field;
    delete[] A;

    return 0;
}