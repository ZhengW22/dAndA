#include <stdio.h>
void insertionSort(int *, int);
void printSort(int *, int);
int main(void)
{
    int a[10] = {3,4,1,45,4,2,1,6,12,99};
    printSort(a, 10);
    insertionSort(a, 10);
    printSort(a, 10);
    return 0;
}
void insertionSort(int a[], int n)
{
    for(int i=1; i<n; i++){
        int key = a[i];
        int j=i-1;
        while(j>=0 && key<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void printSort(int a[], int n)
{
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
