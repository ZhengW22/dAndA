#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE         100
#define STACKINCREMENT          10
#define SUCCESS                 0
#define ERR_NO_STACK            -1
#define ERR_NO_EMPTY_OR_FULL    -2
#define ERR_MALLOC_FAIL         -3

typedef struct stack{
    int  top;
    int  capacity;
    int* array;
} Stack;

int initStack(Stack *s)
// this is the most complex function.
{

    s->top = -1;
    s->capacity = STACK_INIT_SIZE;
    s->array = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
    if(s->array == (int*)NULL){
        return ERR_MALLOC_FAIL;
    } 
    return SUCCESS;
}

Stack* createStack()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    // if(s==(Stack*)NULL){
        // return ;
    // }
    s->top = -1;
    s->capacity = STACK_INIT_SIZE;
    s->array = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
    // if(s.array==(int*)NULL){
        // return ERR_MALLOC_FAIL;
    // }
    return s;
}

int isEmpty(Stack *s)
{
    return (s->top == -1);
}

int isFull(Stack *s)
{
    return (s->top == (s->capacity-1));
}

int push(Stack *s, int e)

{
    if(isFull(s)){
        return ERR_NO_EMPTY_OR_FULL;
    }
    s->array[++s->top] = e;
    return SUCCESS;
}

int pop(Stack *s, int *e)
{
    if(isEmpty(s)){
        return ERR_NO_EMPTY_OR_FULL;
    }
    *e = s->array[s->top--];
    return SUCCESS;
}

int getTop(Stack *s, int *e)
{
    if(s->array == (int*)NULL){
        return ERR_NO_STACK;
    }
    if(isEmpty(s)){
        return ERR_NO_EMPTY_OR_FULL;
    }
    *e = s->array[s->top];
    return SUCCESS;
}
