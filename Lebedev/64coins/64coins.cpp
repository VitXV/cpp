#include <iostream>
#include <random>
#include <time.h>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int seed = time(NULL);
    srand(seed);

    cout << endl << "На шахматной доске лежат монеты. 0 = орёл, 1 = решка." << endl << endl;

    int field[64];
    for (int i = 0; i < 8;i++)
    {
        for (int j = 0; j < 8;j++)
        {
            field[i * 8 + j] = rand() % 2;
            cout << field[i * 8 + j] << " ";
        }
        cout << endl;
    }
    int r = rand() % 64;

    cout << endl << "Тюремщик указал вам на монету, лежащую в " << (r + 1) / 8 + 1 << "-й строке и " << r % 8 + 1 << "-м столбце." << endl;
    cout << "Вы можете перевернуть любую из монет или не переворачивать вовсе. Ваши действия?" << endl << "Укажите номер строки и стобца. Напишите -1 -1, если не хотите ничего менять." << endl;

    int sum;
    int mod = 1;
    int w1[] = { 0,0,0,0,0,0 };
    for (int n = 1;n <= 6;n++)
    {
        sum = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (((i * 8 + j) & 1 * mod) == 1 * mod and field[i * 8 + j] == 1)
                    sum += 1;
            }
        }
        w1[6 - n] = sum % 2;
        mod *= 2;
    }

    mod = 32;
    sum = 0;
    for (int i = 0;i < 6;i++)
    {
        sum = sum + w1[i] * mod;
        mod /= 2;
    }
    int tip = sum ^ r;

    if (sum == r)
        cout << "Подсказка. В данной ситуации не нужно переворачивать монеты." << endl;
    else
        cout << "Подсказка. Нужно перевернуть монету, находящуюся в " << tip / 8 + 1 << "-й строке и " << tip % 8 + 1 << "-м столбце" << endl;

    int chz[] = { 0,0 };
    cin >> chz[0] >> chz[1];
    if (chz[0] == -1 and chz[1] == -1)
        chz[0] = chz[1];
    else
        field[(chz[0] - 1) * 8 + chz[1] - 1] = (field[(chz[0] - 1) * 8 + chz[1] - 1] + 1) % 2;

    mod = 1;
    int w2[] = { 0,0,0,0,0,0 };
    for (int n = 1;n <= 6;n++)
    {
        sum = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (((i * 8 + j) & 1 * mod) == 1 * mod and field[i * 8 + j] == 1)
                    sum += 1;
            }
        }
        w2[6 - n] = sum % 2;
        mod *= 2;
    }
    mod = 32;
    sum = 0;
    for (int i = 0;i < 6;i++)
    {
        sum = sum + w2[i] * mod;
        mod /= 2;
    }

    if (sum != r)
    {
        cout << endl << "Rest in peace...";
        return 0;
    }
    else
    {
        cout << "Какая удача!! Вы спасены!!!";
        return 1;
    }
}