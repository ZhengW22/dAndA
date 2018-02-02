#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdint.h>
#define SUCCESS           0
#define ERR_NO_LIST      -1
#define ERR_EMPTY_LIST   -2
#define ERR_MALLOC_FAIL  -3
struct node{
    int adjvex;
    struct node *next;
};
typedef struct node Node;
int checkSpace(Node *e)
{
    return(e == (Node*)NULL);
}
int initList(Node *head)
{
    int x;
    Node *tail = head;
    Node *temp;
    scanf("%d", &x);
    while(x != -1){
        temp = (Node*)malloc(sizeof(Node));
        if(checkSpace(temp)){
            return ERR_MALLOC_FAIL;
        }
        temp->adjvex = x;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
        scanf("%d", &x);
    }
    return SUCCESS;
}
int insertList(Node *head, int n, int x)
{
    if(head->next == (Node*)NULL){
        return ERR_EMPTY_LIST;
    }
    Node *tail = head;
    for(int i=0; i<n-1; i++){
        tail = tail->next;
        if(tail->next == (Node*)NULL){
            break;
        }
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    if(checkSpace(temp)){
        return ERR_MALLOC_FAIL;
    }
    temp->adjvex = x;
    temp->next = tail->next;
    tail->next = temp;
    return SUCCESS;
}
int removeList(Node *head, int n, Node *e)
{
    if(head->next == (Node*)NULL){
        return ERR_EMPTY_LIST;
    }
    Node *tail = head;
    for(int i=0; i<n-1; i++){
        tail = tail->next;
        if(tail->next->next == (Node*)NULL){
            break;
        }
    }
    Node *temp = tail->next;
    e = temp;
    tail->next = temp->next;
    free(temp);
    return SUCCESS;
}
int sortList(Node *head)
{
    return SUCCESS;
}
int outList(Node *head)
{
    if(head == (Node*)NULL){
        return ERR_NO_LIST;
    }
    if(head->next == (Node*)NULL){
        return ERR_EMPTY_LIST;
    }
    Node *temp;
    temp = head->next;
    while(temp != (Node*)NULL){
        printf("%d ", temp->adjvex);
        temp = temp->next;
    }
    printf("\n");
    return SUCCESS;
}
