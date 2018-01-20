#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}Node;
Node *head = (Node*)NULL;
Node *tail = (Node*)NULL;
Node * createNode()
{
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    if(!temp)
        exit(0);
    int item;
    printf("Please your number to the queue: ");
    scanf("%d", &item);
    temp->value = item;
    temp->next = NULL;
    return temp;
}
void enqueue()
{
    if(head == NULL && tail == NULL){
        head = tail = createNode();
    }
    else{
        tail->next = createNode();
        tail = tail->next;
    }
}
void dequeue()
{
    if(head == NULL && tail == NULL){
        printf("The queue is empty.\n");
        return;
    }
    Node *temp = head;
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        head = temp->next;
    }
    free(temp);
}
void printqueue()
{
    if(head == NULL && tail == NULL){
        printf("The queue is empty.\n");
        return;
    }
    Node *temp = head;
    printf("The queue is: ");    
    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
int main(void)
{
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    printqueue();
    dequeue();
    dequeue();
    printqueue();
}
