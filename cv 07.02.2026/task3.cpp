#include <iostream>
#include <fstream>
using namespace std;

const int LN_LIMIT = 81;

void clearline(char* word, int k)
{
    for (int i{0}; i<k; i++)
        word[i] = ' ';
}

int main()
{
    char word[LN_LIMIT];
    char mxword[LN_LIMIT];

    clearline(word, LN_LIMIT);
    clearline(mxword, LN_LIMIT);

    int k = 0;
    int mx = 0;

    ifstream file("words.txt");
    for (char c; file.get(c);)
    {
        if (c == 10)
        {
            if (k >= mx)
            {
                mx = k;
                for (int i{0}; i<k; i++)
                    mxword[i] = word[i];
            }
            clearline(word, k);
            k = 0;
            continue;
        }
        word[k] = c;
        k++;
    }

	file.close();

    for (int i{0}; i < LN_LIMIT; i++)
        cout << mxword[i];

    return 0;
}