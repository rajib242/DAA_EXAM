#include <stdio.h>
#include <stdlib.h>
int n, c = 1;
int X[18];

int safePlace(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (X[j] == i || abs(j - k) == abs(X[j] - i))
        {
            return 0;
        }
    }
    return 1;
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i] == j)
            {
                printf("Q ");
            }
            else
            {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

void nQueen(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (safePlace(k, i) == 1)
        {
            X[k] = i;
            if (k == n)
            {
                printf("\n\nSolution %d :- \n\n", c++);
                print();
            }
            else
            {
                nQueen(k + 1, n);
            }
        }
    }
}

int main()
{
    printf("\nEnter the number of rows of the chessboard : ");
    scanf("%d", &n);
    nQueen(1, n);
}