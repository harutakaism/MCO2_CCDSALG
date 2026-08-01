#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct EdgeNode {
    char dest[257];
    int weight;
    struct EdgeNode *nextEdge;
} EdgeNodeTag;

typedef struct VertexNode {
    char vertexName[257];
    EdgeNodeTag *firstEdge;
    struct VertexNode *nextVertex;
} VertexNodeTag;

typedef struct Graph {
    VertexNodeTag *firstVertex;
    int numVertices;
} GraphTag;


GraphTag *createGraph();
VertexNodeTag* findVertex(GraphTag* graph, char *name);
void insertSingleEdge(VertexNodeTag *vertex, EdgeNodeTag *edge);
void addVertex(GraphTag *graph, char *vertex);
void addEdge(GraphTag *graph, char *vertex1, char *vertex2, int weight);
int getDegree(GraphTag *graph, char *vertex);
int edgeCheck(GraphTag *graph, char *vertex1, char *vertex2);
void printGraph(GraphTag *graph, char *name);
