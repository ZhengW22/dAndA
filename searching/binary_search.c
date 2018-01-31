#include <stdio.h>
int binarySearch(int *a, int l, int r, int x)
{
    while(l <= r){
        int mid = l+(r-1)/2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] < x)
            l = mid+1;
        else
            r = mid-1;    
    }
    return -1;
}
int reBinarySearch(int *a, int l, int r, int x)
{
    if(r >= 1){
        int mid = l+(r-1)/2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] < x)
            return reBinarySearch(a, mid+1, r, x);
        else
            return reBinarySearch(a, l, mid-1, x);
    }
    return -1;
}

int main(void)
{
    int a[] = {1, 3, 5, 7, 9};
    int size = sizeof(a)/sizeof(a[0]);
    int find = 3;
    printf("%d\n", binarySearch(a, 0, size-1, find)+1);
    return 0;
}
