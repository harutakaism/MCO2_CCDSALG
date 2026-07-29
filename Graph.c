#include "Graph.h"


GraphTag *createGraph()
{
    GraphTag *graph = (GraphTag*)malloc(sizeof(GraphTag));
    if (graph == NULL){
        return NULL;
    }
    graph->firstVertex = NULL;
    graph->numVertices = 0;
    
    return graph;
}

VertexNodeTag* findVertex(GraphTag* graph, char *name)
{
    VertexNodeTag *currVertex = graph->firstVertex;

    if (graph == NULL){
        return NULL;
    }
    
    while (currVertex != NULL)
    {
        if (strcmp(currVertex->vertexName, name) == 0)
        {
            return currVertex;
        }
        currVertex = currVertex->nextVertex;
    }

    return NULL;
}

EdgeNodeTag *findEdge(VertexNodeTag *vertex, char *dest)
{
    EdgeNodeTag *currEdge;

    if (vertex == NULL)
    {
        return NULL;
    }

    currEdge = vertex->firstEdge;

    while (currEdge != NULL)
    {
        if (strcmp(currEdge->dest, dest) == 0)
        {
            return currEdge;
        }

        currEdge = currEdge->nextEdge;
    }

    return NULL;
}


void insertSingleEdge(VertexNodeTag *vertex, EdgeNodeTag *edge)
{
    if (vertex->firstEdge == NULL)
    {
        edge->nextEdge = NULL;
        vertex->firstEdge = edge;
    }
    else if (strcmp(edge->dest, vertex->firstEdge->dest) < 0)
    {
        edge->nextEdge = vertex->firstEdge;
        vertex->firstEdge = edge;
    }
    else
    {
        EdgeNodeTag *currEdge = vertex->firstEdge;
        while (!(currEdge->nextEdge == NULL || strcmp(edge->dest, currEdge->nextEdge->dest) < 0))
        {
            currEdge = currEdge->nextEdge;
        }
        edge->nextEdge = currEdge->nextEdge;
        currEdge->nextEdge = edge;
    }
}

void addVertex(GraphTag *graph, char *vertex)
{
    if (findVertex(graph, vertex) != NULL)
    {
        return;
    }
    
    VertexNodeTag *newNode = (VertexNodeTag*)malloc(sizeof(VertexNodeTag));
    strcpy(newNode->vertexName, vertex);
    newNode->firstEdge = NULL;
    newNode->nextVertex = NULL;
    
    if (graph->numVertices == 0)
    {
        graph->firstVertex = newNode;
    }
    else if(strcmp(vertex, graph->firstVertex->vertexName) < 0)
    {
        newNode->nextVertex = graph->firstVertex;
        graph->firstVertex = newNode;
    }
    else
    {
        VertexNodeTag *currVertex = graph->firstVertex;
        while (!(currVertex->nextVertex == NULL || strcmp(vertex, currVertex->nextVertex->vertexName) < 0))
        {
            currVertex = currVertex->nextVertex;
        }
        newNode->nextVertex = currVertex->nextVertex;
        currVertex->nextVertex = newNode;
    }
    graph->numVertices++;
}

void addEdge(GraphTag *graph, char *vertex1, char *vertex2, int weight)
{
    VertexNodeTag *firstVertex = findVertex(graph, vertex1);
    VertexNodeTag *secondVertex = findVertex(graph, vertex2);

    if (firstVertex == NULL || secondVertex == NULL) return;

    EdgeNodeTag *firstEdge = (EdgeNodeTag*)malloc(sizeof(EdgeNodeTag));
    firstEdge->weight = weight;
    strcpy(firstEdge->dest, vertex2);
    EdgeNodeTag *secondEdge = (EdgeNodeTag*)malloc(sizeof(EdgeNodeTag));
    secondEdge->weight = weight;
    strcpy(secondEdge->dest, vertex1);

    insertSingleEdge(firstVertex, firstEdge);
    insertSingleEdge(secondVertex, secondEdge);
}
