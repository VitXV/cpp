#include <iostream>
#include <random>
#include <time.h>
#include <math.h>
#include <iomanip>
using namespace std;

struct Point
{
    int x, y;
};

int n;
double mn = 1000;
Point* Connect;

double len(Point* pts, int ptRed, int ptBlue);

void shift(Point* pts, int index, int n);

void back(Point* pts, int index, int n);

void iterations(Point* pts, int n, int c, double distance);

int main()
{
    int seed = time(NULL);
    srand(seed);

    n = -1;
    while (n <= 0)
    {
        cout << "Enter n: ";
        cin >> n;
    }

    Point* pts = new Point[2*n];

    cout << endl;

    for (int i=0; i<n; i++)
    {
        pts[i].x = rand() % 21 - 10;
        pts[i].y = rand() % 21 - 10;

        cout << "r ";
        cout << setw(3) << pts[i].x << " ";
        cout << setw(3) << pts[i].y << " ";
        cout << endl;
    }

    cout << endl;

    for (int i=n; i < 2*n; i++)
    {
        pts[i].x = rand() % 21 - 10;
        pts[i].y = rand() % 21 - 10;

        cout << "b ";
        cout << setw(3) << pts[i].x << " ";
        cout << setw(3) << pts[i].y << " ";
        cout << endl;
    }

    Connect = new Point[n];

    iterations(pts, n, 0, 0);

    cout << endl;
    cout << "Min sum of distances = " << mn << endl;
    cout << endl << "Connections: " << endl;
    for (int i=0; i<n; i++)
    {
        cout << "r " << setw(3) << pts[i].x << " " << setw(3) << pts[i].y;
        cout << "        ";
        cout << "b " << setw(3) << Connect[i].x << " " << setw(3) << Connect[i].y;
        cout << endl;
    }

    delete[] pts;
    delete[] Connect;
    return 0;
}

double len(Point* pts, int ptRed, int ptBlue)
{
    return sqrt(pow(pts[ptBlue].x - pts[ptRed].x, 2) + pow(pts[ptBlue].y - pts[ptRed].y, 2));
}

void shift(Point* pts, int index, int n) //переставляет элемент в конец массива и сдвигает все оставшиеся влево
{
    Point buffer = pts[index];
    for (int i=0; i < 2*n - index - 1; i++)
    {
        pts[index+i] = pts[index+i + 1];
    }
    pts[2*n - 1] = buffer;
}

void back(Point* pts, int index, int n)
{
    Point buffer = pts[2*n - 1];
    for (int i = 2*n - 1; i>index; i--)
    {
        pts[i] = pts[i - 1];
    }
    pts[index] = buffer;
}

void iterations(Point* pts, int n, int c, double distance)
{
    for (int i = 0; i < n - c; i++)
    {
        double l = len(pts, c, n + i);
        shift(pts, n + i, n);
        if (c == n - 1)
        {
            //cout << distance+l << " ";
            if (distance + l < mn)
            {
                mn = distance + l;
                for (int j = 0; j < n; j++)
                    Connect[j] = pts[n + j];
            }
        }
        iterations(pts, n, c + 1, distance + l);
        back(pts, n + i, n);
    }
}