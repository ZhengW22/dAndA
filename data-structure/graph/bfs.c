#include "queue_link.h"
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
void BFS(MGraph g, int v)
{
	Queue *q=creatQueue();
	printf("%d ", v);
	visited[v] = true;
	enqueue(q, v);
	int i, j;
	while(!(isEmpty(*q))){
		i = queueFront(*q);
		for(j=0; j<g.n; j++){
			if(g.edges[i][j]!=0&&visited[j]==false){
				printf("%d ", j);
				visited[j]=true;
				enqueue(q, j);
			}
		}
		if(j==g.n) dequeue(q);
	}
	printf("\n");
	for(int j=0; j<g.n; j++){
		if(visited[j]==false) BFS(g, j);
	}
}
int main(void)
{
    MGraph g;
    scanf("%d %d", &(g.n), &(g.e));
    creatMGraph(&g);
    BFS(g, 0);
    return 0;
}
