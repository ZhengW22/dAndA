#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

static Node *root = NULL;

Node * creatNode(int value)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = value;
    tmp->left = tmp->right = NULL;
    return tmp;
}
void insertTree(int value)
{
    Node *tmp = root;
    if(root == NULL){
        root = creatNode(value);
    }
    else{
        while(1){
            if(value > tmp->data){
                if(!tmp->right){
                    tmp->right = creatNode(value);
                    break;
                }
                else
                    tmp = tmp->right;
            }
            else{
                if(!tmp->left){
                    tmp->left = creatNode(value);
                    break;
                }
                else
                    tmp = tmp->left;
            }
        }
    }
}
int min(int left_h, int right_h)
{
    return (left_h > right_h) ? right_h : left_h;
}
int min_depth(Node *tmp)
{
    if(!tmp)
        return 0;
    if(!tmp->left && !tmp->right)
        return 1;
    if(!tmp->left)
        return min_depth(tmp->right)+1;
    if(!tmp->right)
        return min_depth(tmp->left)+1;
    return min(min_depth(tmp->left), min_depth(tmp->right))+1;
}
int main()
{
  int ctr, num_nodes, value,min;
  printf("Enter number of nodes\n");
  scanf("%d",&num_nodes);
  for (ctr = 0; ctr < num_nodes; ctr++)
  {
     printf("Enter values\n");
     scanf("%d",&value);
     insertTree(value);
  }
  min = min_depth(root);
  printf("minimum depth = %d\n",min);
}
