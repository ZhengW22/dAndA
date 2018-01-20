#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;

int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return (root->height);
    }
}

void heightUpdate(Node *tmp)
{
    int left_height = height(tmp->left);
    int right_height = height(tmp->right);
    if (left_height > right_height)
        tmp->height = left_height + 1;
    else
        tmp->height = right_height + 1;
}

int getBalance(Node *tmp)
{
    if (tmp == NULL)
    {
        return 0;
    }
    else
    {
        return (height(tmp->left) - height(tmp->right));
    }
}

Node *RightRotate(Node *tmp)
{
    Node *a = tmp;
    Node *b = tmp->left;
    a->left = b->right;
    b->right = a;
    heightUpdate(a);
    heightUpdate(b);
    return b;
}
Node *LeftRotate(Node *tmp)
{
    Node *a = tmp;
    Node *b = tmp->right;
    a->right = b->left;
    b->left = a;
    return b;
}
Node *LeftRightRotate(Node *tmp)
{
    Node *a = tmp;
    Node *b = tmp->left;
    a->left = LeftRotate(b);
    return RightRotate(a);
}
Node *RightLeftRotate(Node *tmp)
{
    Node *a = tmp;
    Node *b = tmp->right;
    a->right = RightRotate(b);
    return LeftRotate(a);
}
Node *creatNode(int data)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    if(!tmp){
        printf("Memory allocation failed.\n");
        return 0;
    }
    tmp->data = data;
    tmp->height = 0;
    tmp->left = tmp->right = NULL;
    return tmp;
}
Node *insertTree(Node *tmp, int data)
{
    if(tmp == NULL){
        tmp = creatNode(data);
    }
    else{
        if(data < tmp->data){
            tmp->left = insertTree(tmp->left, data);
            if(getBalance(tmp) == 2 && getBalance(tmp->left) == 1)
                tmp = RightRotate(tmp);
            else if(getBalance(tmp) == 2 && getBalance(tmp->left) == -1)
                tmp = LeftRightRotate(tmp);
        }
        else{
            tmp->right = insertTree(tmp->right, data);
            if(getBalance(tmp) == -2 && getBalance(tmp->right) == -1)
                tmp = LeftRotate(tmp);
            else if(getBalance(tmp) == -2 && getBalance(tmp->right) == 1)
                tmp = RightLeftRotate(tmp);
        }
        heightUpdate(tmp);
    }
    return tmp;
}
Node * inorder_successor(Node *tmp)
{
    Node *t = tmp->right;
    while(t->left != NULL){
        t = t->left;
    }
    return t;
}
Node * deleteNode(Node *tmp, int data)
{
    if(tmp == NULL){
        return NULL;
    }
    if(data < tmp->data){
        tmp->left = deleteNode(tmp->left, data);
        if(getBalance(tmp) == 2 && getBalance(tmp->left) == 1)
            tmp = RightRotate(tmp);
        else if(getBalance(tmp) == 2 && getBalance(tmp->left) == -1)
            tmp = LeftRightRotate(tmp);
        heightUpdate(tmp);
    }
    else if(data > tmp->data){
        tmp->right = deleteNode(tmp->right, data);
        if(getBalance(tmp) == -2 && getBalance(tmp->right) == -1)
            tmp = LeftRotate(tmp);
        else if(getBalance(tmp) == -2 && getBalance(tmp->left) == 1)
            tmp = RightLeftRotate(tmp);
        heightUpdate(tmp);
    }
    else{
        if(tmp->left && tmp->right){
            tmp->data = inorder_successor(tmp)->data;
            tmp->right = deleteNode(tmp->right, tmp->data);
        }
        else{
            Node *tmp2 = tmp;
            tmp = tmp->left ? tmp->left : tmp->right;
            free(tmp2);
        }
    }
    return tmp;
}
void preorder(Node *tmp)
{
    if(tmp){
        printf("%d ", tmp->data);
        preorder(tmp->left);
        preorder(tmp->right);
    }
}
void inorder(Node *tmp)
{
    if(tmp){
        inorder(tmp->left);
        printf("%d ", tmp->data);
        inorder(tmp->right);
    }
}
void postorder(Node *tmp)
{
    if(tmp){
        postorder(tmp->left);
        postorder(tmp->right);
        printf("%d ", tmp->data);
    }
}
int searchTree(int x)
{
    Node *tmp = root;
    while(tmp){
        if(x < tmp->data)
            tmp = tmp->left;
        else if(x > tmp->data)
            tmp = tmp->right;
        else{
            return 1;
        }
    }
    return 0;
}
int main(void)
{
    root = insertTree(root, 1);
    root = insertTree(root, 2);
    root = insertTree(root, 3);
    root = insertTree(root, 4);
    preorder(root);
    printf("\n");
    root = deleteNode(root ,2);
    preorder(root);
    printf("\n");
}
