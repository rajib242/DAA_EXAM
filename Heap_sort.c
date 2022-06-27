#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int left_chid = 2 * i + 1;
    int right_chid = 2 * i + 2;

    if (left_chid < n && arr[left_chid] > arr[largest])
    {
        largest = left_chid;
    }
    if (right_chid < n && arr[right_chid] > arr[largest])
    {
        largest = right_chid;
    }
    if (largest != i)
    {
        Swap(&arr[i], &arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    // Build the max-Heap from the given tree
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        Swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}

void PrintArray(int arr[], int n)
{
    printf("after sorting the array will be : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the numer of elements of the array (Minimum 1 element) : ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    HeapSort(arr, n);
    PrintArray(arr, n);
}