// Lab_7_3.cpp
// < Мальський Назар  >
// Лабораторна робота № 7.3.
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 17
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int n, int i);
void Sort(int** a, const int n);
int first(int** a, int rowCount, int colCount, int i, int j, int colNumber, int rowNumber);
int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = "; cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    int Low = 16;
    int High = 97;
    Create(a, n, Low, High, 0, 0);
    Print(a, n, 0);
    Sort(a, n);
    Print(a, n, 0);
    cout << first(a,n,n,0,0,-1,0);

}
void Create(int** a, const int n, const int Low, const int High, int i, int j)
{
    if (i < n)
    {
        Create(a, n, Low, High, i + 1, j);

        if (j < n)
        {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, n, Low, High, i, j + 1);
        }
    }



}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}
void Print(int** a, const int n, int i)
{
    PrintRow(a, i, n, 0);
    if (i < n - 1)
        Print(a, n, i + 1);
    else
        cout << endl;
}

void Change(int** a, const int row, const int col, const int colCount)
{
    int tmp;
    tmp = a[row][col];
    a[row][col] = a[row + 1][col + 1];
    a[row + 1][col + 1] = tmp;
}
void Sort(int** a, const int n)
{
    for (int f = 0; f < n - 1; f++)
        for (int f = 0; f < n - 1; f++)
            if (a[f][f] > a[f + 1][f + 1])
                Change(a, f, f, n);
}
int first(int** a, int rowCount, int colCount, int i, int j, int colNumber, int rowNumber)
{
   
    if (int i = 0)
    {
        if (i < colCount && i++)
        {
            colNumber = -1;
            if (colNumber == -1)
            {
                for (int j = 0; j < rowCount; j++)
                {
                    if (a[j][i] == 0)
                        colNumber = i;
                }
            }
            if (colNumber != 0)
            {
                rowNumber = i;
                return rowNumber;
            }
        }
    }
}