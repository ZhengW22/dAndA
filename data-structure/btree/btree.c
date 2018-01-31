#include <stdio.h>
#define MIN_DEGREE 2
#define MAX_N ((MIN_DEGREE*2)-1)
#define MAX_C (MIN_DEGREE*2)
#define MAX_S 20
// typedef int TVal;
typedef struct fileheader
{
    int root;
    int nbNodes;
    int nbVals;
    int height;
}FileHeader;
typedef struct bnode
{
    int vals[MAX_N];
    int childs[MAX_C];
    int nb_n;
}BNode;
typedef struct bstack
{
    int head;
    int adrs[MAX_S];
    BNode nodes[MAX_S];
}BStack;
typedef struct btree
{
    FILE *treeFile;
    FileHeader fileHeader;
    BStack stack;
}BTree;

int bnode_search(int v, int *i, BNode *n);
void bnode_ins(int v, int rc, BNode *n);
void bnode_del(int v, BNode *n);
void inorder(BTree *f, int i);
int btree_find(BTree *bt, int c, int *i, int *j, BNode *buff);
void btree_ins(BTree *bt, int c);
