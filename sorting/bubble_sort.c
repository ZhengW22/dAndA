#include <stdio.h>
typedef int bool;
#define true  1
#define false 0

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int a[], int n)
{
    bool swapped;
    for(int i = 0; i<n; i++){
        swapped = false;
        for(int j = 0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

void printSort(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    int a[10] = {3,4,1,45,4,2,1,6,12,99};
    printSort(a, 10);
    bubbleSort(a, 10);
    printSort(a, 10);
    return 0;
}
