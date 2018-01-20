#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define STACK_INIT_SIZE         100
#define STACKINCREMENT          10
#define SUCCESS                 0
#define ERR_NO_STACK            -1
#define ERR_NO_EMPTY_OR_FULL    -2
#define ERR_MALLOC_FAIL         -3

typedef struct stack{
    int32_t  top;
    int8_t   capacity;
    int32_t* array;
} Stack;

int8_t initStack(Stack *s)
// this is the most complex function.
{

    s->top = -1;
    s->capacity = STACK_INIT_SIZE;
    s->array = (int32_t*)malloc(STACK_INIT_SIZE * sizeof(int32_t));
    if(s->array == (int32_t*)NULL){
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
    s->array = (int32_t*)malloc(STACK_INIT_SIZE * sizeof(int32_t));
    // if(s.array==(int32_t*)NULL){
        // return ERR_MALLOC_FAIL;
    // }
    return s;
}

int8_t isEmpty(Stack *s)
{
    return (s->top == -1);
}

int8_t isFull(Stack *s)
{
    return (s->top == (s->capacity-1));
}

int8_t push(Stack *s, int32_t e)

{
    if(isFull(s)){
        return ERR_NO_EMPTY_OR_FULL;
    }
    s->array[++s->top] = e;
    return SUCCESS;
}

int8_t pop(Stack *s, int32_t *e)
{
    if(isEmpty(s)){
        return ERR_NO_EMPTY_OR_FULL;
    }
    *e = s->array[s->top--];
    return SUCCESS;
}

int8_t getTop(Stack *s, int32_t *e)
{
    if(s->array == (int32_t*)NULL){
        return ERR_NO_STACK;
    }
    if(isEmpty(s)){
        return ERR_NO_EMPTY_OR_FULL;
    }
    *e = s->array[s->top];
    return SUCCESS;
}

int main()
{
    Stack* s = createStack();
    int32_t* e;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    getTop(s, e);
    printf("%d\n", *e);
    pop(s, e);
    printf("%d\n", *e);
    getTop(s, e);
    printf("%d\n", *e);
}
