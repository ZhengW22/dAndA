// this file use pointer to pointer.
#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
}Stack;
void initStack(Stack **s)
{
    *s = (Stack*)NULL;
}
int isEmpty(Stack *s)
{
    if(s == (Stack*)NULL)
        return 1;
    return 0;
}
void push(Stack **s, int x)
{
    Stack *p = (Stack*)malloc(sizeof(Stack));
    if(p == (Stack*)NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    p->data = x;
    p->next = *s;
    *s = p;
    // printf("%d\n", (*s)->data);
}
int pop(Stack **s)
{
    if(isEmpty(*s)){
        printf("The stack is empty\n");
        return 0;
    }
    int e = (*s)->data;
    Stack *temp = *s;
    *s = (*s)->next;
    free(temp);
    return e;
}
int top(Stack *s)
{
    return ((s)->data);
}
void insertStack(Stack **s,int x)
{
    if(isEmpty(*s)||x>top(*s)){
        push(s,x);
        return;
    }
    int temp = pop(s);
    insertStack(s, x);
    push(s, temp);
}
void sortStack(Stack **s)
{
    if(!isEmpty(*s)){
        int x = pop(s);
        sortStack(s);
        insertStack(s, x);
    }
}
void printStack(Stack *s)
{
    while(s)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}
int main()
{
    Stack *head;
    initStack(&head);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);
    printStack(head);
    sortStack(&head);
    printStack(head);
    return 0;
}
