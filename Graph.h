#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct EdgeNode {
    char dest[256];
    int weight;
    EdgeNodeTag *nextEdge;
} EdgeNodeTag;

typedef struct VertexNode {
    char vertexName[256];
    EdgeNodeTag *firstEdge;
    struct VertexNode *nextVertex;
} VertexNodeTag;

typedef struct Graph {
    VertexNodeTag *firstVertex;
    int numVertices;
} GraphTag;


GraphTag *createGraph();
void addVertex(GraphTag *graph, char *vertex);
void addEdge(GraphTag *graph, char *vertex1, char *vertex2, int weight);
