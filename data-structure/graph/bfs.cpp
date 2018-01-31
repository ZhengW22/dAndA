#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#define MAX 100
using namespace std;

typedef struct
{
    int edges[MAX][MAX];
    int n;
    int e;
}MGraph;

bool visited[MAX];

void creatMGraph(MGraph &G)
{
    int s, t, v;
    for(int i=0; i<G.n; i++){
        for(int j=0; j<G.n; j++)
            G.edges[i][j] = 0;
        visited[i] = false;
    }
    for(int i=0; i<G.e; i++){
        int s, t, v;
        scanf("%d %d %d ", &s, &t, &v);
        G.edges[s][t] = v;
    }
}

void BFS(MGraph G, int v)
{
    queue<int> q;
    printf("%d ", v);
    visited[v] = true;
    q.push(v);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(int j = 0; j<G.n; j++){
            if(G.edges[i][j] != 0 && visited[j] == false){
                printf("%d ", j);
                visited[j] = true;
                q.push(j);
            }
        }
    }
}
