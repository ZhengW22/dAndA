#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    long num;
    struct node *ptr;
};
typedef struct node Node;
void ListInit(Node *head)
{
    Node *temp;
    Node *tail;
    tail = head;
    char *c;
    char *endptr;
    int n;
    scanf("%s", c);
    // scanf("%d", &n);
    while(*c !='0'){
        temp = (Node *)malloc(sizeof(Node));
        temp->num = strtol(c, &endptr, 10);
        tail->ptr = temp;
        tail = temp;
        scanf("%s", c);
    }
    tail->ptr = NULL;
}
void ListOut(Node *head)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = head->ptr;
    while(temp != NULL){
        printf("%ld ", temp->num);
        temp = temp->ptr;
    }
    printf("\n");
}
int main(void){
    Node *head = (Node *)malloc(sizeof(Node));
    ListInit(head);
    ListOut(head);
}
