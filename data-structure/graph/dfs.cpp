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
    for(int i = 0; i<G.n; i++){
        for(int j = 0; j<G.n; j++)
            G.edges[i][j] = 0;
        visited[i] = false;
    }
    for(int i = 0; i<G.e; i++){
        scanf("%d %d %d ", &s, &t, &v);
        G.edges[s][t] = v;
    }
}

void reDFS(MGraph G, int v)
{
    printf("%d ",v);
    visited[v] = true;
    for(int i = 0; i<G.n; i++){
        if(G.edges[v][i] != 0 && visited[i] == false)
            DFS(G, i);
    }
}

void DFS(MGraph G, int v)
{
    stack<int> s;
    printf("%d ", v);
    visited[v] = true;
    s.push(v);
    while(!s.empty()){
        int i = s.top();
        for(int j = 0; j<G.n; j++){
            if(G.edges[i][j] != 0 && visited[j] == false){
                printf("%d ", j);
                visited[j] = true;
                s.push(j);
                break;
            }
            if(j == G.n)
                s.pop();
        }
    }
}
