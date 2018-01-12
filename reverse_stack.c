#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int data;
    struct stack *next;
}Stack;
int isEmpty(Stack *s)
{
    return(s == (Stack*)NULL);
}
void push(Stack **s, int x)
{
    Stack *temp = (Stack*)malloc(sizeof(Stack));
    if(temp == (Stack*)NULL){
        printf("Memory allocation failed.\n");
        exit(0);
    }
    temp->data = x;
    temp->next = *s;
    *s = temp;
}
int pop(Stack **s)
{
    if(isEmpty(*s)){
        printf("Stack overflow.\n");
        exit(0);
    }
    Stack *temp = *s;
    int e = temp->data;
    *s = (*s)->next;
    free(temp);
    return e;
}
void outStack(Stack *s)
{
    Stack *temp = s;
    while(temp!=(Stack*)NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertAtBottom(Stack **s, int x)
{
    if(isEmpty(*s))
        push(s, x);
    else{
        int temp = pop(s);
        insertAtBottom(s, x);
        push(s, temp);
    }
}
void reverse(Stack **s)
{
    if(!isEmpty(*s)){
        int temp = pop(s);
        reverse(s);
        insertAtBottom(s, temp);
    }
}
int main(void)
{
    Stack *s = NULL;
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    outStack(s);
    // pop(&s);
    // int e = pop(&s);
    // printf("%d\n", e);
    reverse(&s);
    outStack(s);
    return 0;
}
