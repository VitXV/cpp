#include <iostream>
#include <fstream>
#include <cstdio>
#include <chrono>
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

    auto start = chrono::high_resolution_clock::now();

    // С 2007-го года до 2008-го меняется структура данных
    // было YMD	HMS	T	R	El	Az	FI	LG
    // стало "YMD","HMS","R","H","Az","Sh","Dl"
    // Можно проверить, если третий столбец не 'T', значит это формат, который содержит 7 столбцов

    // Файл moon2023.dat содержит данные только до 09.03.2023 16:57:18

    int form=0;

    int i = 0;
    for (char c; file.get(c) && c!='\n'; ) // пропуск первой строчки
    {
        if (i++ == 8)
        {
            if (c != 'T') // Выясняю формат записи в файле
                form = 1;
        }
    }

    double skip; // сюда буду скидывать всё, что мне не нужно

    int date;
    int time;
    double El;

    double prevEl=0;
    int mx = -1000;

    // Переменные для вывода результата
    DateTime moonrise;
    DateTime culmination;
    DateTime moonset;

    int compare1;
    int compare2;
    int CompareResult;

    switch (form)
    {
        case 0:
        {
            file >> skip >> compare1 >> skip >> skip >> skip >> skip >> skip >> skip;
            file >> skip >> compare2 >> skip >> skip >> skip >> skip >> skip >> skip;

            CompareResult = DateTime().IntToTime(compare2).TimeToSeconds() - DateTime().IntToTime(compare1).TimeToSeconds();
            CompareResult = 24 * 3600 / CompareResult; // Количество строк для одного дня 
            //cout << "CompareResult: " << CompareResult;

            file.seekg(0);
            for (char c; file.get(c) && c != '\n'; ); // пропуск первой строчки

            // Экспериментальным путём я выяснил, что в данном типе файла символов в каждой строке около 70. Иногда больше, но 70 - это самое минимальное количество
            const int CHARS_PER_LINE = 70;
            /*
            int mn = 10000;
            int qwe = 0;
            for (char c; file.get(c); qwe++)
            {
                if (c == '\n')
                {
                    if (qwe < mn)
                        mn = qwe;
                    qwe = 0;
                }
            }
            cout << endl << mn;
            */

            DateTime start(dt.getYear(), 1, 1);
            int howMuch = dt - start - 1; // сколько дней мне нужно пропустить, чтобы перейти ближе к необходимому
            if (howMuch <= 0)
                howMuch = 0;
            //cout << endl << "howMuch: " << howMuch;

            // Я хочу пропустить некоторое количество символов
            // (Кол-во_символов_в_строке * Кол-во_строк_в_одном_дне) * кол-во дней

            unsigned long long int totalSkip = (unsigned long long int)CompareResult * howMuch * CHARS_PER_LINE;
            file.seekg(totalSkip, ios::cur);
            file.clear();
            for (char c; file.get(c) && c != '\n';);

            while (file >> date >> time >> skip >> skip >> El >> skip >> skip >> skip) // читаю файл по словам
            {
                //cout << endl << date << " " << time;
                if (date == dt.DateToInt())
                {
                    if (prevEl < 0 && El >= 0)
                        moonrise = moonrise.IntToTime(time);
                    if (prevEl > 0 && El <= 0)
                        moonset = moonset.IntToTime(time);
                    if (El > mx)
                    {
                        mx = El;
                        culmination = culmination.IntToTime(time);
                    }
                }
                prevEl = El;

                if (date == (dt + 1).DateToInt())
                {
                    file.close();
                    break;
                }
            }
            break;
        }
        case 1:
        {
            file >> skip >> compare1 >> skip >> skip >> skip >> skip >> skip;
            file >> skip >> compare2 >> skip >> skip >> skip >> skip >> skip;

            CompareResult = DateTime().IntToTime(compare2).TimeToSeconds() - DateTime().IntToTime(compare1).TimeToSeconds();
            CompareResult = 24 * 3600 / CompareResult; // Количество строк для одного дня 
            //cout << "CompareResult: " << CompareResult;

            file.seekg(0);
            for (char c; file.get(c) && c != '\n'; ); // пропуск первой строчки

            const int CHARS_PER_LINE = 64;
            /*
            int mn = 10000;
            int qwe = 0;
            for (char c; file.get(c); qwe++)
            {
                if (c == '\n')
                {
                    if (qwe < mn)
                        mn = qwe;
                    qwe = 0;
                }
            }
            cout << endl << mn;
            */

            DateTime start(dt.getYear(), 1, 1);
            int howMuch = dt - start - 1; // сколько дней мне нужно пропустить, чтобы перейти ближе к необходимому
            if (howMuch <= 0)
                howMuch = 0;
            //cout << endl << "howMuch: " << howMuch;

            unsigned long long int totalSkip = (unsigned long long int)CompareResult * howMuch * CHARS_PER_LINE;
            file.seekg(totalSkip, ios::cur);
            file.clear();
            for (char c; file.get(c) && c != '\n';);

            while (file >> date >> time >> skip >> El >> skip >> skip >> skip) // читаю файл по словам
            {
                if (date == dt.DateToInt())
                {
                    if (prevEl < 0 && El >= 0)
                        moonrise = moonrise.IntToTime(time);
                    if (prevEl > 0 && El <= 0)
                        moonset = moonset.IntToTime(time);
                    if (El > mx)
                    {
                        mx = El;
                        culmination = culmination.IntToTime(time);
                    }
                }
                prevEl = El;

                if (date == (dt + 1).DateToInt())
                {
                    file.close();
                    break;
                }
            }
            break;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << endl << ReversedOutput(dt) << endl;
    cout << "Moonrise: " << Time(moonrise) << endl;
    cout << "Culmination: " << Time(culmination) << endl;
    cout << "Moonset: " << Time(moonset) << endl;

    cout << endl << "Execution time: " << diff.count() << " seconds" << std::endl;

    return 0;
}
