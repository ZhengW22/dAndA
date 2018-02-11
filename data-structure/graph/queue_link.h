#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}Node;
typedef struct queue
{
    int count;
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
    q->count = 0;
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
    q->count++;
}
void dequeue(Queue *q)
{
    if(q->head == NULL && q->tail == NULL){
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
    q->count--;
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
int isEmpty(Queue q)
{
    return(q.count==0);
}
int queueFront(Queue q)
{
    return q.head->value;
}
