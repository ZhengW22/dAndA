#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}Node;
typedef struct queue
{
    Node *head;
    Node *tail;
}Queue;
Node * createNode(int item)
{
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    if(!temp)
        exit(0);
    temp->value = item;
    temp->next = NULL;
    return temp;
}
Queue* creatQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->head = (Node*)NULL;
    q->tail = (Node*)NULL;
    return q;
}
void enqueue(Queue *q, int item)
{
    if(q->head == NULL && q->tail == NULL){
        q->head = q->tail = createNode(item);
    }
    else{
        q->tail->next = createNode(item);
        q->tail = q->tail->next;
    }
}
void dequeue(Queue *q)
{
    if(q->head == NULL && q->tail == NULL){
        printf("The queue is empty.\n");
        return;
    }
    Node *temp = q->head;
    if(q->head == q->tail){
        q->head = NULL;
        q->tail = NULL;
    }
    else{
        q->head = temp->next;
    }
    free(temp);
}
void printqueue(Queue *q)
{
    if(q->head == NULL && q->tail == NULL){
        printf("The queue is empty.\n");
        return;
    }
    Node *temp = q->head;
    printf("The queue is: ");    
    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
int main(void)
{
    Queue *q = creatQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    printqueue(q);
    enqueue(q, 3);
    printqueue(q);
    dequeue(q);
    printqueue(q);
    return 0;
}
