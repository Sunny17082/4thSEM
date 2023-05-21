#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int vertex;
    struct Node* next;
};
struct Graph
{
    int numVertices;
    int* visited;
    struct Node** adjLists;
};
struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}
struct Graph* createGraph(int vertex)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertex;
    graph->adjLists = malloc(vertex*sizeof(struct Node));
    graph->visited = malloc(vertex*sizeof(int));
    for(int i=0;i<vertex;i++)
    {
        graph->adjLists[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void printGraph(struct Graph* graph)
{
    for(int v=0;v<graph->numVertices;v++)
    {
        struct Node* temp = graph->adjLists[v];
        printf("%d: ",v);
        while(temp)
        {
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
void DFS(struct Graph* graph, int i)
{
    struct Node* adjList = graph->adjLists[i];
    struct Node* temp = adjList;
    printf("%d ",i);
    graph->visited[i]=1;
    while(temp)
    {
        int j=temp->vertex;
        if(graph->visited[j]==0)
            DFS(graph,j);
        temp=temp->next;
    }
}
int main()
{
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);
    DFS(graph,0);
    return 0;
}
