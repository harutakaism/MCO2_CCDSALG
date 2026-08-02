#include "MST.h"

#define INF 1000000000

int findVertexIndex(VertexNodeTag *vertices[], int count, char *name){
    int i;

    for(i = 0; i < count; i++){
        if(strcmp(vertices[i]->vertexName, name) == 0){
            return i;
        }
    }

    return -1;
}

GraphTag *minimumSpanningTree(GraphTag *graph){
    GraphTag *mst;
    VertexNodeTag *vertices[256];
    VertexNodeTag *currVertex;
    int key[256];
    int parent[256];
    int used[256];
    int count = 0;
    int i, step;

    if(graph == NULL){
        return NULL;
    }
    mst = createGraph();
    if(mst == NULL){
        return NULL;
    }

    currVertex = graph->firstVertex;

    while(currVertex != NULL && count < 256)
    {
        vertices[count] = currVertex;
        addVertex(mst, currVertex->vertexName);
        key[count] = INF;
        parent[count] = -1;
        used[count] = 0;
        count++;
        currVertex = currVertex->nextVertex;
    }

    if(count == 0){
        return mst;
    }

    key[0] = 0;

    for(step = 0; step < count; step++){
        int u = -1;
        int smallest = INF;
        EdgeNodeTag *currEdge;

        for(i = 0; i < count; i++){
            if(!used[i] && key[i] < smallest)
            {
                smallest = key[i];
                u = i;
            }
        }

        if(u == -1){
            for(i = 0; i < count; i++)
            {
                if(!used[i])
                {
                    u = i;
                    key[i] = 0;
                    break;
                }
            }
        }

        used[u] = 1;

        if(parent[u] != -1){
            addEdge(mst,
                    vertices[parent[u]]->vertexName,
                    vertices[u]->vertexName,
                    key[u]);
        }

        currEdge = vertices[u]->firstEdge;

        while(currEdge != NULL){
            int v = findVertexIndex(vertices, count, currEdge->dest);

            if(v != -1 && !used[v])
            {
                if(currEdge->weight < key[v])
                {
                    key[v] = currEdge->weight;
                    parent[v] = u;
                }
                else if(currEdge->weight == key[v] && parent[v] != -1 &&
                        strcmp(vertices[u]->vertexName,
                               vertices[parent[v]]->vertexName) < 0)
                {
                    parent[v] = u;
                }
            }

            currEdge = currEdge->nextEdge;
        }
    }

    return mst;
}
