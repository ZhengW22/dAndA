#include <stdio.h>
#define maxsize 100
#define min(a, b) ((a) < (b)) ? (a) : (b)

typedef struct heap
{
    int a[maxsize];
    int hsize;
} Heap;

Heap h;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapInsert(int data)
{
    h.a[++h.hsize] = data;
    int i = h.hsize;
    while(i > 1 && h.a[i] < h.a[i/2]){
        swap(&h.a[i], &h.a[i/2]);
        i = i/2;
    }
}

void displayHeap()
{
    for(int i = 1; i<= h.hsize; i++)
        printf("%d ", h.a[i]);
    printf("\n");
}

void delHeap()
{
    if (h.hsize == 0){
        printf("The heap is empty.");
        return;
    }
    else if(h.hsize == 1){
        int a = h.a[h.hsize--];
        printf("%d\n", a);
        return;
    }
    else{
        int x = h.a[1];
        h.a[1] = h.a[h.hsize--];
        int i = 1;
        while(2*i <= h.hsize){
            if(2*i+1 <= h.hsize && h.a[i] > min(h.a[2*i], h.a[2*i+1])){
                if(h.a[2*i] > h.a[2*i+1]){
                    swap(&h.a[i], &h.a[2*i+1]);
                    i = 2*i+1;
                }
                else{
                    swap(&h.a[i], &h.a[2*i]);
                    i = 2*i;
                }
            }
            else if(2*i+1 > h.hsize && h.a[i] > h.a[2*i]){
                swap(&h.a[i], &h.a[2*i]);
                break;
            }
            else
                break;
        }
        printf("%d\n", x);
    }
}
int main(void)
{
    h.hsize = 0;
    heapInsert(3);
    heapInsert(2);
    heapInsert(1);
    displayHeap();
    delHeap();
    displayHeap();
}
