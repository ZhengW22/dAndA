#include <stdio.h>
void merge(int *a, int *b, int low, int mid, int high)
{
    int l1, l2, i;
    for(l1 = low, l2 = mid+1, i = low; l1 <= mid && l2 <=high; i++){
        if(a[l1]<=a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }
    while(l1 <= mid)
        b[i++] = a[l1++];
    while(l2 <= high)
        b[i++] = a[l2++];
    for(i = low; i<=high; i++)
        a[i] = b[i];
}
void mergeSort(int *a, int *b, int low, int high)
{
    int mid;
    if(low < high){
        mid = (low+high)/2;
        mergeSort(a, b, low, mid);
        mergeSort(a, b, mid+1, high);
        merge(a, b, low, mid, high);
    }
    else
        return;
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
    int b[10];
    printSort(a, 10);
    mergeSort(a, b, 0, 9);
    printSort(a, 10);
    return 0;
}
