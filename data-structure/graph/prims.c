#include <limits.h>
#include <stdio.h>
#define INFINITY 1000
#define MAX_VERTEX_NUM 20
typedef struct mgraph
{
    // int vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //权值
    int verxnum, arcnum; //vernum 顶点数, arcnum 弧数
}MGraph;
typedef struct closeSelf
{
    int adjvex;
    int lowcost;
}closeSelf;

int minself(closeSelf *p, MGraph g)
{
    int k = INFINITY;
    int j = -1;
    for(int i=0; i<g.verxnum; ++i){
        if(k>p[i].lowcost && p[i].lowcost != 0){
            k = p[i].lowcost;
            j = i;
            // printf("%d\n", i);
        }
    }
    return j;
}
void Prim(MGraph g, int u)
{
    closeSelf closeedge[g.verxnum];
    int k = u;
    for(int i=0; i<g.verxnum; i++){
        if(i != k){
            closeedge[i].adjvex = u; //让所有的边都指向u边
            closeedge[i].lowcost = g.arcs[k][i];
        }
    }
    closeedge[k].lowcost = 0;
    for(int i=1; i<g.verxnum; ++i){
        k = minself(closeedge, g);
        printf("%d ", k);
        closeedge[k].lowcost = 0;
        for(int j=0; j<g.verxnum; ++j){ //这个循环是神来之笔
            if(g.arcs[k][j] < closeedge[j].lowcost){
                closeedge[j].adjvex = k;
                closeedge[j].lowcost = g.arcs[k][j];
            }
        }
    }
    printf("\n");
}
int main(void)
{
    MGraph g;
    g.verxnum = 6;
    g.arcnum = 10;
    for(int i=0; i<g.verxnum; i++){
        for(int j=0; j<g.verxnum; j++){
            g.arcs[i][j] = INFINITY;
        }
    }
    printf("%d\n", g.arcs[0][0]);
    g.arcs[0][1] = 6;
    g.arcs[0][2] = 1;
    g.arcs[0][3] = 5;
    g.arcs[1][2] = 5;
    g.arcs[1][4] = 3;
    g.arcs[2][3] = 5;
    g.arcs[2][4] = 6;
    g.arcs[2][5] = 4;
    g.arcs[3][5] = 2;
    g.arcs[4][5] = 6;
    Prim(g, 0);
    return 0;
}
