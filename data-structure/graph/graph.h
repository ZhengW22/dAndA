#ifndef MGRPH_STRUCT_H
#define MGRPH_STRUCT_H
#include <stdlib.h>

typedef struct m_graph
{
    int n;
    int **matrix;
}M_Graph;
int creatMGraph(size_t n, M_Graph *graph);
void freeMGraph(M_Graph *graph);
void MG_set(M_Graph *graph, int i, int j, int val);
int MG_get(M_Graph *graph, int i, int j);
size_t MG_size(M_Graph *graph);

#endif
