#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define SUCCESS           0
#define ERR_NO_LIST      -1
#define ERR_EMPTY_LIST   -2
#define ERR_MALLOC_FAIL  -3
struct node{
    int num;
    struct node *next;
};
typedef struct node Node;
int8_t checkSpace(Node *e)
{
    return(e == (Node*)NULL);
}
int8_t initList(Node *head)
{
    int x;
    Node *tail = head;
    Node *temp;
    scanf("%d", &x);
    while(x != 0){
        temp = (Node*)malloc(sizeof(Node));
        if(checkSpace(temp)){
            return ERR_MALLOC_FAIL;
        }
        temp->num = x;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
        scanf("%d", &x);
    }
    return SUCCESS;
}
int8_t insertList(Node *head, int n, int x)
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
    temp->num = x;
    temp->next = tail->next;
    tail->next = temp;
    return SUCCESS;
}
int8_t removeList(Node *head, int n, Node *e)
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
int8_t sortList(Node *head)
{
    return SUCCESS;
}
int8_t outList(Node *head)
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
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
    return SUCCESS;
}
int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    Node *e = (Node*)malloc(sizeof(Node));
    head->next = (Node*)NULL;
    initList(head);
    // printf("%d\n", head->next->num);
    removeList(head, 5, e);
    insertList(head, 5, 3);
    outList(head);
    return 0;
}
