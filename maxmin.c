#include <stdio.h>

int max_element, min_element;

void Maxmin(int arr[], int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max_element = arr[i];
        min_element = arr[i];
        return;
    }
    else if (i == j - 1)
    {
        if (arr[i] > arr[j])
        {
            max_element = arr[i];
            min_element = arr[j];
        }
        else
        {
            max_element = arr[j];
            min_element = arr[i];
        }
        return;
    }
    else
    {
        mid = (i + j) / 2;

        Maxmin(arr, i, mid);
        max1 = max_element, min1 = min_element;
        Maxmin(arr, mid + 1, j);
        // compare between first half and second helf of the array
        if (max1 > max_element)
            max_element = max1;
        if (min1 < min_element)
            min_element = min1;
        return;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    max_element = -111;
    min_element = 999;
    Maxmin(arr, 0, n - 1);
    printf("Maximum element of the array : %d\n", max_element);
    printf("Minumim element of the array : %d", min_element);

    return 0;
}