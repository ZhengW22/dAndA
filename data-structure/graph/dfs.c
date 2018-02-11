#include "stack.h"
#include <stdio.h>
#define bool int
#define true 1
#define false 0
#define MAX 100
int count = 0;
typedef struct mgraph
{
    int edges[MAX][MAX];
    int n;
    int e;
}MGraph;

bool visited[MAX];

void creatMGraph(MGraph *g)
{
    int a, b;
    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            g->edges[i][j] = 0;
        }
        visited[i] = false;
    }
    for(int i=0; i<g->e; i++){
        scanf("%d %d", &a, &b);
        g->edges[a][b] = 1;
        g->edges[b][a] = 1;
    }
}
void DFS(MGraph g, int v)
{
    Stack *s = createStack();
    printf("%d ",v);
    visited[v] = true;
    push(s, v);
    int i, j;
    int tmp;
    while(!isEmpty(s)){
        getTop(s, &i);
        for(j=0; j<g.n; j++){
            if(g.edges[i][j]!=0&&visited[j]==false){
                printf("%d ", j);
                visited[j] = true;
                push(s, j);
                break;
            }
        }
        if(j==g.n) pop(s, &tmp);
    }
    printf("\n");
    for(int i=0; i<g.n; i++){
        if(visited[i]==false) DFS(g, i);
    }
}
int main(void)
{
    MGraph g;
    scanf("%d %d", &(g.n), &(g.e));
    creatMGraph(&g);
    DFS(g, 0);
    return 0;
}
