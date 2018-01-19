#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

typedef struct dataitem
{
    int data;
    int key;
}DataItem;
DataItem *hashArray[SIZE];
DataItem *dummyItem;
DataItem *item;

int hashCode(int key)
{
    return key % SIZE;
}

void insertHash(int key, int data)
{
    DataItem *item = (DataItem *)malloc(sizeof(DataItem));
    item->data = data;
    item->key = key;
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex] != -1){
        hashIndex++;
        hashIndex = hashIndex%SIZE;
    }
    hashArray[hashIndex] = data;
}
DataItem * deleteHash(DataItem *item)
{
    int key = item->key;
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL){
        if(hashArray[hashIndex]->key == key){
            DataItem *tmp = hashArray[hashIndex];
            hashArray[hashIndex] = dummyItem;
            return tmp;
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}
DataItem * search(int key)
{
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex]){
        if(hashArray[hashIndex]->key == key){
            return hashArray[hashIndex];
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}
void display()
{
    for(int i = 0; i < SIZE; i++){
        if(hashArray[i])
            printf("(%d, %d) ", hashArray[i]->key, hashArray[i]->data);
        else
            printf("~~ ");
    }
    printf("\n");
}
int main(void)
{
    dummyItem = (DataItem*)malloc(sizeof(DataItem));
    dummyItem->data = -1;
    dummyItem->key  = -1;
    
}
