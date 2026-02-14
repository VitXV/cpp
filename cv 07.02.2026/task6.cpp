#include <iostream>
#include <locale.h>
using namespace std;

bool isinM(char m, char* M, int c) // наличие элемента m в массиве M, длины c
{
    for (int i{0}; i<c; i++)
    {
        if (M[i] == m)
            return true;
    }
    return false;
}

int main()
{
    setlocale(LC_ALL,"Russian");

    int c;
    char line[41];

    cout << "Введите слово: ";
    cin.getline(line, 41);

    c = 0;
    for (int i{0}; *(line+i); i++)
        c++;

    char* M1 = new char[c];
    for (int i{0}; i<c; i++)
        M1[i] = ' ';
    
    int na = 0;
    for (int i{0}; i<c; i++)
    {
        if (isinM(line[i], M1, c))
            continue;
        else
        {
            M1[na] = line[i];
            na++;
        }
    }

    cout << "Введите второе слово: ";
    cin.getline(line, 41);

    c = 0;
    for (int i{0}; *(line+i); i++)
        c++;

    char* M2 = new char[c];
    for (int i{0}; i<c; i++)
        M2[i] = ' ';
    
    int nb = 0;
    for (int i{0}; i<c; i++)
    {
        if (isinM(line[i], M2, c))
            continue;
        else
        {
            M2[nb] = line[i];
            nb++;
        }
    }

    int nc = 0;
    for (int i{0}; i<na; i++)
    {
        for (int j{0}; j<nb; j++)
        {
            if (isinM(M1[i], M2, nb))
            {
                nc++;
                break;
            }
        }
    }

    float T = nc / (float)(na + nb - nc);
    cout << "Коофицент похожести равен: " << (int)(T*10000)/10000.0;

    delete[] M1;
    delete[] M2;
    return 0;
}