#include <stdio.h>
void selectionSort(int a[], int n)
{
    int min, tmp;
    for(int i = 0; i<n-1; i++){
        min = i;
        for(int j = i+1; j<n; j++){
            if(a[min] > a[j])
                min = j;
        }
        if(min != i){
            tmp = a[min];
            a[min] = a[i];
            a[i] = tmp;
        }
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
    selectionSort(a, 10);
    printSort(a, 10);
    return 0;
}
