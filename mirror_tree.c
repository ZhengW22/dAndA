#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 typedef struct node{
     int data;
     struct node *left;
     struct node *right;
 }Node;

Node *root = NULL;

Node * creatNode(int data)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    if(!tmp){
        printf("Memory allocation failed.\n");
        exit(0);
    }
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void insertTree(int data)
{
    Node *tmp = root;
    if(root == NULL){
        root = creatNode(data);
    }
    else{
        while(1){
            if(data > tmp->data){
                if(!tmp->right){
                    tmp->right = creatNode(data);
                    break;
                }
                else
                    tmp = tmp->right;
            }
            else{
                if(!tmp->left){
                    tmp->left = creatNode(data);
                    break;
                }
                else
                    tmp = tmp->left;
            }
        }
    }
}
void cleanTree(Node *tmp)
{
    if(tmp){
        cleanTree(tmp->left);
        cleanTree(tmp->right);
        if(tmp->left){
            free(tmp->left);
            tmp->left = NULL;
        }
        if(tmp->right){
            free(tmp->right);
            tmp->right = NULL;
        }
    }
    if(tmp == root){
        free(root);
        root = NULL;
    }
}
void mirror(Node *tmp)
{
    Node *tmp1 = NULL;
    if(tmp){
        tmp1 = tmp->left;
        tmp->left = tmp->right;
        tmp->right = tmp1;
        mirror(tmp->left);
        mirror(tmp->right);
    }
}
void printTree(Node *tmp)
{
    if(tmp){
        printf("%d ", tmp->data);
        printTree(tmp->left);
        printTree(tmp->right);
    }
}
int main(void)
{
    insertTree(2);
    insertTree(1);
    insertTree(3);
    printTree(root);
    mirror(root);
    printTree(root);
}
