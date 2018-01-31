#include "graph.h"

int creatMGraph(size_t n, M_Graph *graph)
{
    graph->n = n;
    graph->matrix = malloc(n*sizeof(*graph->matrix));
    // this is very important.
    if(graph->matrix == NULL)
        return -1;
    for(int i=0; i<n; i++){
        graph->matrix[i] = calloc(n, sizeof(**graph->matrix));
        // this is also very important.
        if(graph->matrix[i] == NULL){
            graph->n = i;
            freeMGraph(graph);
            return -1;
        }
    }
    return 0;
}

 void freeMGraph(M_Graph *graph)
 {
     for(int i=0; i<graph->n; i++){
         free(graph->matrix[i]);
     }
     free(graph->matrix);
     graph-> n = 0;
 }

void MG_set(M_Graph *graph, int i, int j, int val)
{
    graph->matrix[i][j] = val;
}

int MG_get(M_Graph *graph, int i, int j)
{
    return graph->matrix[i][j];
}

size_t MG_size(M_Graph *graph)
{
    return graph->n;
}
