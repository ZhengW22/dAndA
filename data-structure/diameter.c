#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *left, *right;
}Node;
Node * creatNode(int item)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if(!temp){
        exit(0);
    }
    temp->value = item;
    temp->left = temp->right = NULL;
    return temp;
}
Node *root = NULL;
void insert_tree(int item)
{
    // printf("d");
    Node *base = root;
    if(root == NULL){
        root = creatNode(item);
    }
    else{
        while(1){
            if(item > base->value){
                if(!base->right){
                    base->right = creatNode(item);
                    break;
                }
                else{
                    base = base->right;
                }
            }
            else{
                if(!base->left){
                    base->left = creatNode(item);
                    break;
                }
                else{
                    base = base->left;
                }
            }
        }
    }
}
int maximum(int a, int b)
{
    return (a > b? a : b);
}
int height_tree(Node *temp)
{
    int left, right;
    if(!temp){
        return 0;
    }
    left  = height_tree(temp->left);
    right = height_tree(temp->right);
    return (1+maximum(left, right));
}
int diameter_tree(Node *temp)
{
    int depth, left_h, right_h, max;
    if(!temp)
        return 0;
    depth = height_tree(temp->left)+height_tree(temp->right);
    left_h = diameter_tree(temp->left);
    right_h = diameter_tree(temp->right);
    max = maximum(left_h, right_h);
    return maximum(max, depth);
}
void clean_tree(Node *temp)
// this function is very complex and important.
{
    if(temp){
        clean_tree(temp->left);
        clean_tree(temp->right);
        if(temp->left){
            free(temp->left);
            temp->left = NULL;
        }
        if(temp->right){
            free(temp->right);
            temp->right = NULL;
        }
        if(temp == root){
            free(root);
            root = NULL;
        }
    }
}
int main(void)
{
    insert_tree(2);
    insert_tree(1);
    insert_tree(3);
    int h = height_tree(root);
    printf("The height of tree is: %d\n", h);
    h = diameter_tree(root);
    printf("The height of tree is: %d\n", h);    
    clean_tree(root);
    return 0;
}
