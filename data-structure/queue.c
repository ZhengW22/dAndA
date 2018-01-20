#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int queue[MAX];
int front = -1;
int rear  = -1;
void insert()
{
    int item;
    if(rear == MAX-1){
        printf("The queue overflow.\n");
    }
    else{
        if(front == -1)
            front++;
        printf("Insert the element in queue: ");
        scanf("%d", &item);
        queue[++rear] = item;
    }
    return;
}
void delete()
{
    if(front == -1 || front > rear){
        printf("The queue is empty.\n");
    }
    else{
        printf("The element deleted from the queue is: %d\n", queue[front++]);
    }
    return;
}
void display(){
    if(front == -1 || front > rear){
        printf("The queue is empty.\n");
    }
    else{
        for(int i=front; i <= rear; i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
    return;
}
int main(void)
{
    insert();
    insert();
    insert();
    delete();
    delete();
    display();
    return 0;
}
