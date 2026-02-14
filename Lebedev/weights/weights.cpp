#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int W[] = { 100,50,20,10,5,2,1 };
    int n = sizeof(W) / 4;
    int* weights = new int[n];

    for (int i = 0; i < n;i++)
        weights[i] = 0;

    int mx = 0;
    for (int i = 0; i < n;i++)
        mx += W[i];

    int massa = -1;
    while (massa <= 0)
    {
        cout << "¬ведите массу, которую, необходимо взвесить: ";
        cin >> massa;
    }

    int save = massa;
    for (int i = 0; massa > 0 and i < n;i++)
    {
        if (massa / W[i] > 0)
        {
            weights[i]++;
            massa -= W[i];
            i = -1;
        }
    }

    for (int i = 0; i < n;i++)
    {
        if (weights[i] > 0)
            cout << weights[i] << " гир€ весом " << W[i] << endl;
    }

    delete[] weights;
    return 0;
}
