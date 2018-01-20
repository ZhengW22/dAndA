#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack{
    int top;
    unsigned cap;
    int *array;
}Stack;
Stack * creatStake(unsigned capacity)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s==(Stack*)NULL)
        exit(0);
    s->top = -1;
    s->cap = capacity;
    s->array = (int*)malloc(capacity*sizeof(int));
    if(!s->array)
        exit(0);
    return s;
}
int isEmpty(Stack *s)
{
    return (s->top == -1);
}
char peek(Stack *s)
{
    return (s->array[s->top]);
}
char pop(Stack *s)
{
    if(!isEmpty(s)){
        return (s->array[s->top--]);
    }
    return '$';
}
void push(Stack *s, char op)
{
    s->array[++s->top] = op;
}
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');

}
int Prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int main(void)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    printf("%d\n", s->cap);
    return 0;
}
