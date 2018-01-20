#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// there is a question that the return value of peek is char.

typedef struct stack{
    int top;
    unsigned cap;
    int *array;
}Stack;

Stack * createStack(unsigned capacity)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    
    s->top = -1;
    s->cap = capacity;
    s->array = (int*)malloc(capacity * sizeof(int));
    // this is interesting.
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
// dollar symblo 
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
int evaluatePostfix(char *exp)
{
    Stack *s = createStack(strlen(exp));
    for(int i = 0; exp[i]; i++){
        if(isdigit(exp[i])){
            push(s, exp[i]-'0');
        }
        else{
            int val2 = pop(s);
            int val1 = pop(s);
            switch(exp[i]){
                case '*': push(s, val1*val2); break;
                case '/': push(s, val1/val2); break;
                case '+': push(s, val1+val2); break;
                case '-': push(s, val1-val2); break;
            }
        }
    }
    return pop(s);
}
int main(void)
{
    char exp[] = "231*+9-";
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}
