#include <iostream>
#include <fstream>
#include <cstdio>
#include "DateTime.h"

using namespace std;
int main()
{
    DateTime dt;
    char NoF[18]; // Name of File
    ifstream file;

    while (true) // Попытка открыть файл
    {
        try
        {
            cout << "Enter dd.mm.yyyy: ";
            cin >> ReversedInput(dt);
            snprintf(NoF, sizeof(NoF),"Moon/moon%d.dat", dt.getYear());
            file.open(NoF);
            if (!file.is_open())
                throw Exception();
            cout << NoF << endl;
            break;
        }
        catch (const Exception& e)
        {
            cout << endl << "Wrong input or file doesnt exist, try again" << endl;
        }
    }

    // Есть проблема, с 2007-го года до 2008-го меняется структура данных
    // было YMD	HMS	T	R	El	Az	FI	LG
    // стало "YMD","HMS","R","H","Az","Sh","Dl"
    // Можно проверить, если третий столбец не 'T', значит это формат, который содержит 7 столбцов

    int form=0;

    int i = 0;
    for (char c; file.get(c); ) // пропуск первой строчки
    {
        if (i++ == 8)
        {
            if (c != 'T')
                form = 1;
        }
        if (c == '\n')
            break;
    }

    double skip; // мусорка, туда буду скидывать всё, что мне не нужно

    int date;
    int time;
    double El;

    double prevEl=0;
    int mx = -1000;

    // Переменные для вывода результата
    DateTime moonrise;
    DateTime culmination;
    DateTime moonset;

    switch (form)
    {
    case 0:
    {
        while (file >> date >> time >> skip >> skip >> El >> skip >> skip >> skip) // читаю файл по словам
        {
            if (date == dt.DateToInt())
            {
                if (prevEl < 0 && El > 0)
                    moonrise = moonrise.IntToTime(time);
                if (prevEl > 0 && El < 0)
                    moonset = moonset.IntToTime(time);
                if (El > mx)
                {
                    mx = El;
                    culmination = culmination.IntToTime(time);
                }
            }
            prevEl = El;
        }
        break;
    }
    case 1:
    {
        while (file >> date >> time >> skip >> El >> skip >> skip >> skip) // читаю файл по словам
        {
            if (date == dt.DateToInt())
            {
                if (prevEl < 0 && El > 0)
                    moonrise = moonrise.IntToTime(time);
                if (prevEl > 0 && El < 0)
                    moonset = moonset.IntToTime(time);
                if (El > mx)
                {
                    mx = El;
                    culmination = culmination.IntToTime(time);
                }
            }
            prevEl = El;
        }
        break;
    }
    }

    cout << endl << ReversedOutput(dt) << endl;
    cout << "Moonrise: " << Time(moonrise) << endl;
    cout << "Culmination: " << Time(culmination) << endl;
    cout << "Moonset: " << Time(moonset) << endl;

    return 0;
}
