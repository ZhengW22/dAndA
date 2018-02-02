#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "stack.h"
#define INFINITY 1000
#define MAX_VERTEX_NUM 20
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
        // printf("%d OK ", i);    
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
        // printf("%d\n", p[i]);
    }
}
void TopologicalSort(ALGraph g)
{
    int indegree[g.vernum];
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
        printf("%d ", n);
        for(Node *p = g.vertices[n].first->next; p; p = p->next){
            int k = p->adjvex;
            if(!(--indegree[k]))
                push(S, k);
        }
    }
    if(count != g.vernum){
        printf("There is a loop.");
    }
    printf("\n");
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
    // printf("OK\n");
    // for(int i=0; i<g.vernum; i++){
    //     printf("%d ", indegree[i]);
    // }
    TopologicalSort(g);
    printf("\n");
    return 0;
}
