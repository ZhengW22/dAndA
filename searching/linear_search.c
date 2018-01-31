#include <stdio.h>
int search(int *a, int size, int x)
{
    for(int i=0; i<size-1; i++){
        if(a[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int a[] = {1, 3, 5};
    int size = sizeof(a)/sizeof(a[0]);
    int find = 1;
    printf("%d\n", search(a, size, find)+1);
    return 0;
}
