#include<stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int start = low;
    int end = high;
  
    if(start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }

        while(a[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
        
            swap(&a[start], &a[end]);
        }
    }

    swap(&a[low], &a[end]);
    return end;
}
void QuickSort(int arr[], int low, int high){
    if(low < high){
        int p = partition(arr,low,high);
        QuickSort(arr,low,p-1);
        QuickSort(arr,p+1,high);
    }
}
void display(int arr[], int n){
    printf("after sorting the array will be : \n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the numer of elements of the array : ");
    scanf("%d", & n);
    printf("Enter the elements of the array: ");
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", & arr[i]);
    QuickSort(arr,0,n-1);
    display(arr,n);
    return 0;
}
