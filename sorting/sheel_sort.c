// this has some difficulties.
#include <stdio.h>
void shellSort(int a[], int n)
{
    int tmp, j;
    for(int gap = n/2; gap>0; gap/=2){
        for(int i = gap; i<n; i++){
            tmp = a[i];
            for(j = i; j>=gap; j-=gap){
                if(tmp < a[j-gap])
                    a[j] = a[j-gap];
                else
                    break;
            }
            a[j] = tmp;
            // this is the pen of God.
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
    shellSort(a, 10);
    printSort(a, 10);
    return 0;
}
