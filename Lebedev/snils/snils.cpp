#include <iostream>
using namespace std;

int main()
{
    char SNILS[16];
    cout << "Enter SNILS (XXX-XXX-XXX XX): ";
    cin.getline(SNILS,16);
    
    int CtrlSum[3] = {};
    int CtrlSumCheck = 0;
    int CtrlSumk = 9;
    for (int i = 0; *(SNILS + i); i++)
    {
        if (SNILS[i] == '-')
            continue;
        else if (SNILS[i] == ' ')
        {
            for (int j = 0;j < 3;j++)
                CtrlSum[j] = (int)(SNILS[i + j + 1] - 48);
            break;
        }
        else
        {
            CtrlSumCheck += ((int)SNILS[i]-48) * CtrlSumk;
            CtrlSumk-=1;
        }
    }
    int cs = 0;
    int k = 1;
    for (int i = 2;i >=0;i--)
    {
        if (CtrlSum[i] != -48)
        {
            cs += CtrlSum[i] * k;
            k *= 10;
        }
            
    }

    if (CtrlSumCheck % 101 == cs)
        cout << "True";
    else
        cout << "False";

    return 0;
}