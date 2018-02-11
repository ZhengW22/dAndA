#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "stack.h"
#define INFINITY 1000
#define MAX_VERTEX_NUM 20
#define FAIL   0
typedef struct vNode
{
    // int date;
    Node *first;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct alGraph
{
    AdjList vertices;
    int vernum, arcnum;
}ALGraph;

void FindInDegree(ALGraph g, int *p)
{
    int n;
    Node *q;
    for(int i=0; i<g.vernum; i++){
        n = 0;
        for(int j=0; j<g.vernum; j++){
            q = g.vertices[j].first->next;
            while(q != (Node*)NULL){
                if(q->adjvex == i){
                    ++n;
                    break;
                }
                q = q->next;
            }
        }
        p[i] = n;
    }
}
int TopologicalSort(ALGraph g, Stack *t, int *ve)
{
    int indegree[g.vernum];
    for(int i=0; i<g.vernum; i++){
        ve[i] = 0; 
    }
    FindInDegree(g, indegree);
    Stack *S = (Stack*)malloc(sizeof(Stack));
    initStack(S);
    for(int i=0; i<g.vernum; i++){
        if(!indegree[i])
            push(S, i);
    }
    int count = 0;
    int n;
    while(!isEmpty(S)){
        pop(S, &n);
        count++;
        push(t, n);
        for(Node *p = g.vertices[n].first->next; p; p = p->next){
            int k = p->adjvex;
            if(!(--indegree[k]))
                push(S, k);
            if(ve[n]+p->data > ve[k])
                ve[k] = ve[n]+p->data;
        }
    }
    if(count != g.vernum){
        printf("There is a loop.\n");
        return FAIL;
    }
    return SUCCESS;
}

int CriticaPath(ALGraph g, Stack *t, int *ve, int *vl)
{
    if(!TopologicalSort(g, t, ve))
        return FAIL;
    for(int i=0; i<g.vernum; i++){
        vl[i] = ve[g.vernum-1];
    }
    int n;
    while(!isEmpty(t)){
        pop(t, &n);
        for(Node *p = g.vertices[n].first->next; p; p = p->next){
            int k = p->adjvex;
            if(vl[n] > vl[k] - p->data)
                vl[n] = vl[k] - p->data;
        }
    }
    for(int i = 0; i<g.vernum; i++){
        
    }
}

int main(void)
{
    ALGraph g;
    scanf("%d %d", &g.vernum, &g.arcnum);
    for(int i=0; i<g.vernum; i++){
        g.vertices[i].first = (Node*)malloc(sizeof(Node));
        g.vertices[i].first->adjvex = i;
        g.vertices[i].first->next = (Node*)NULL;
    }
    for(int i=0; i<g.vernum; i++){
        initList(g.vertices[i].first);
    }
    TopologicalSort(g);
    printf("\n");
    return 0;
}
