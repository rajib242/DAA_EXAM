#include <bits/stdc++.h>
using namespace std;
int b[100];
int display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}
int merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            b[k] = A[i];
            i++;
            k++;
        }
        else
        {
            b[k] = A[j];
            j++;
            k++;
        }
    }

    if (i > mid)
    {
        while (j <= high)
        {
            b[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = A[i];
            i++;
            k++;
        }
    }

    for (k = low; k <= high; k++)
    {
        A[k] = b[k];
    }
}
int mergesort(int A[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
int main()
{
    int n;
    cout << "Size of the Array" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the" << n << "Array -- > " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    mergesort(A, 0, n - 1);
    display(A, n);
}
