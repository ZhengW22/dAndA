// this file use head node.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define SUCCESS           0
#define ERR_NO_STACK     -1
#define ERR_EMPTY_STACK  -2
#define ERR_MALLOC_FAIL  -3
typedef struct stack
{
    int data;
    struct stack *next;
}Stack;
Stack * initStack()
{
    Stack *p = (Stack*)malloc(sizeof(Stack));
    if(p == (Stack*)NULL){
        printf("Memory allocation failed.\n");
    }
    p->next = (Stack*)NULL;
    return p;
}
int8_t isEmpty(Stack *s)
{
    return(s->next == (Stack*)NULL);
}
int8_t push(Stack *s, int x)
{
    Stack *p = (Stack*)malloc(sizeof(Stack));
    if(p == (Stack*)NULL){
        return ERR_MALLOC_FAIL;
    }
    if(s == (Stack*)NULL){
        return ERR_NO_STACK;
    }
    p->data = x;
    p->next = s->next;
    s->next = p;
    return SUCCESS;
}
int32_t pop(Stack *s)
{
    if(s == (Stack*)NULL){
        return ERR_NO_STACK;
    }
    if(isEmpty(s)){
        return ERR_EMPTY_STACK;
    }
    Stack *temp = s->next;
    s->next = temp->next;
    int e = temp->data;
    free(temp);
    return e;
}
int32_t top(Stack *s)
{
    return s->next->data;
}
int8_t outStack(Stack *s)
{
    Stack *temp = s->next;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return SUCCESS;
}
int main(void)
{
    Stack *s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    outStack(s);
    int e = top(s);
    printf("%d ", e);
    printf("\n");
}
