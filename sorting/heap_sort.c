#include <stdio.h>
#include <stdlib.h>
typedef struct minHeap
{
    int size;
    int *array;
}Minheap;
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void minHeapify(Minheap *heap, int index)
{
    int smallest = index;
    int left  = (index<<1)+1;
    int right = (index+1)<<1;
    if(left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;
    if(right < heap->size && heap->array[right] < heap->array[smallest]){
        smallest = right;
    }
    if(smallest != index){
        swap(&heap->array[smallest], &heap->array[index]);
        minHeapify(heap, smallest);
    }
}
Minheap * creatAndBuildHeap(int *array, int size)
{
    int i;
    Minheap *heap = (Minheap*)malloc(sizeof(Minheap));
    heap->size = size;
    heap->array = array;
    for(i = (heap->size-2)/2; i>=0; i--)
        minHeapify(heap, i);
    return heap;
}
void heapSort(int *a, int size)
{
    Minheap *heap = creatAndBuildHeap(a, size);
    while(heap->size > 1)
    {
        swap(&heap->array[0], &heap->array[--heap->size]);
        minHeapify(heap, 0);
    }
}
void printSort(int a[], int n)
{
    for(int i=n-1; i>=0; i--){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(void)
{
    int a[10] = {3,4,1,45,4,2,1,6,12,99};
    printSort(a, 10);
    heapSort(a, 10);
    printSort(a, 10);
    return 0;
}
