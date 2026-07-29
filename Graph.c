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
    VertexNodeTag *currVertex;

    if (graph == NULL){
        return NULL;
    }

    currVertex = graph->firstVertex;
    
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
    VertexNodeTag *newNode;

    if (graph == NULL || vertex == NULL)
    {
        return;
    }

    if (findVertex(graph, vertex) != NULL)
    {
        return;
    }

    newNode = (VertexNodeTag*)malloc(sizeof(VertexNodeTag));

    if (newNode == NULL)
    {
        return;
    }

    strcpy(newNode->vertexName, vertex);
    newNode->firstEdge = NULL;
    newNode->nextVertex = NULL;

    if (graph->numVertices == 0)
    {
        graph->firstVertex = newNode;
    }
    else if (strcmp(vertex, graph->firstVertex->vertexName) < 0)
    {
        newNode->nextVertex = graph->firstVertex;
        graph->firstVertex = newNode;
    }
    else
    {
        VertexNodeTag *currVertex = graph->firstVertex;

        while (!(currVertex->nextVertex == NULL ||
                 strcmp(vertex, currVertex->nextVertex->vertexName) < 0))
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

int getDegree(GraphTag *graph, char *vertex)
{
    VertexNodeTag *foundVertex = findVertex(graph, vertex);
    EdgeNodeTag *currEdge;
    int degree = 0;

    if (foundVertex == NULL)
    {
        return 0;
    }

    currEdge = foundVertex->firstEdge;

    while (currEdge != NULL)
    {
        degree++;

        currEdge = currEdge->nextEdge;
    }

    return degree;
}

int edgeCheck(GraphTag *graph, char *vertex1, char *vertex2)
{
    VertexNodeTag *vertex = findVertex(graph, vertex1);

    if (vertex == NULL)
    {
        return 0;
    }

    return findEdge(vertex, vertex2) != NULL;
}

void printGraph(GraphTag *graph, char *name)
{
    VertexNodeTag *currVertex;
    int first = 1;

    if (graph == NULL)
    {
        return;
    }

    printf("%s = (V,E)\n", name);
    printf("V = {");

    currVertex = graph->firstVertex;

    while (currVertex != NULL)
    {
        if (!first)
        {
            printf(", ");
        }

        printf("%s", currVertex->vertexName);
        first = 0;
        currVertex = currVertex->nextVertex;
    }

    printf("}\n");
    printf("E = {\n");

    currVertex = graph->firstVertex;

    while (currVertex != NULL)
    {
        EdgeNodeTag *currEdge = currVertex->firstEdge;

        while (currEdge != NULL)
        {
            if (strcmp(currVertex->vertexName, currEdge->dest) <= 0)
            {
                printf("(%s, %s, %d),\n",
                       currVertex->vertexName,
                       currEdge->dest,
                       currEdge->weight);
            }

            currEdge = currEdge->nextEdge;
        }

        currVertex = currVertex->nextVertex;
    }

    printf("}\n");
}


