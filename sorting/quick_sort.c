#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *a, int low, int high)
{
    int pivot = a[low];
    while(low<high){
        while(low<high && pivot<=a[high])
            high--;
        a[low] = a[high];
        while(low<high && pivot>=a[low])
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quickSort(int *a, int low, int high)
{
    if(low < high){
        int k = partition(a, low, high);
        quickSort(a, low, k-1);
        quickSort(a, k+1, high);
    }
}

void printSort(int a[], int n)
{
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(void)
{
    int a[10] = {3,4,1,45,4,2,1,6,12,99};
    printSort(a, 10);
    quickSort(a, 0, 9);
    printSort(a, 10);
    return 0;
}
