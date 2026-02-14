#include <iostream>
#include <locale.h>
using namespace std;

bool isVowel(char c)
{
    char Vowels[] = { 'a','e','i','o','u' };
    for (int i{0}; i<(sizeof(Vowels)/sizeof(Vowels[0])); i++)
        if (c==Vowels[i])
            return true;
    return false;
}

int main()
{
    setlocale(LC_ALL,"Russian");

    char line[41];
    cout << "Введите слово на английском языке: ";
    cin.getline(line, 41);

    int l=0,v=0; // длина слова и кол-во гласных букв
    for (int i{0}; *(line+i); i++)
    {
        l++;
        if (isVowel(line[i]))
            v++;
    }

    cout << "Гласных букв: " << v << endl<< "Согласных букв: " << l-v;

    return 0;
}