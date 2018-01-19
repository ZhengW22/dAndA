#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node * creatNode(int data)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    if(!tmp){
        printf("Memory allocation failed.");
        exit(0);
    }
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}
Node * insertTree(Node **tmp, int data)
{
    if(*tmp == NULL)
        *tmp = creatNode(data);
    else if((*tmp)->data > data)
        (*tmp)->left = insertTree(&(*tmp)->left, data);
    else
        (*tmp)->right = insertTree(&(*tmp)->right, data);
    // printf(" d ");
    return *tmp;        
}
void printTree(Node *tmp)
{
    if(tmp == NULL)
        return;
    printf("%d ", tmp->data);
    printTree(tmp->left);
    printTree(tmp->right);
}
int searchTree(Node *tmp, int data)
{
    if(tmp == NULL)
        return 0;
    if(tmp->data == data)
        return 1;
    else if(tmp->data > data)
        return searchTree(tmp->left, data);
    else
        return searchTree(tmp->right, data);
}
Node * deleteTree(Node *tmp)
{
    if(tmp == NULL)
        return NULL;
    deleteTree(tmp->left);
    deleteTree(tmp->right);
    free(tmp);
    return NULL;
}
Node * deleteNode(Node *tmp, int data)
{
    if(tmp == NULL){
        printf("Not found.\n");
    }
    if(tmp->data == data)
        tmp = deleteTree(tmp);
    else if(tmp->data > data)
        tmp->left = deleteNode(tmp->left, data);
    else
        tmp->right = deleteNode(tmp->right, data);
    return tmp;
}
int heightTree(Node *tmp)
{
    if(tmp == NULL)
        return 0;
    else{
        int left_h = heightTree(tmp->left);
        int right_h = heightTree(tmp->right);
        if(left_h > right_h)
            return (left_h+1);
        else
            return (right_h+1);
    }
}
int main(void)
{
    Node *root = NULL;
    insertTree(&root, 1);
    insertTree(&root, 2);
    insertTree(&root, 3);
    int h = heightTree(root);
    printf("The height of tree is: %d\n", h);
    int b = searchTree(root, 4);
    printf("%d\n", b);
    deleteTree(root);
    return 0;
}
