#include<stdio.h>
#include <stdlib.h>
#define MAX_VEX_NUM 100

typedef int NodeType;

// Edge struct of Graph
typedef struct Edge
{
    int src;    // start node of edge
    int dest;   // end node of edge
    int weight; // weight of edge
} Edge;

// Node struct of Graph
typedef struct Vextex
{
    int data; // data field
    NodeType weight;
    struct Vextex *next; // point to next node
} Vextex;

// 图的数据结构
typedef struct ALGraph
{
    int numVertices;  // number of node
    int numEdges;     // number of edge
    Vextex **adjList; // 邻接表，用于存储每个顶点的邻居顶点
} ALGraph;

// create new node
Vextex *createVertex(int data, int weight)
{
    Vextex *vextex = (Vextex *)malloc(sizeof(Vextex));
    vextex->data = data;
    vextex->weight = weight;
    vextex->next = NULL;
    return vextex;
}

// create a graph (actually will create a adjlist)
ALGraph *createALGraph(int numVextex)
{
    ALGraph *graph = (ALGraph *)malloc(sizeof(ALGraph));
    graph->numVertices = numVextex;
    graph->adjList = (Vextex **)malloc(numVextex * sizeof(Vextex*));

    // initialize adjlist
    for (int i = 0; i < numVextex; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}


// 开始画图
void addEdge(ALGraph *graph, int src, int dest, int weight)
{
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    // 创建新的顶点
    Vextex *vextex = (Vextex *)malloc(sizeof(Vextex));
    // 添加节点
    vextex->next = graph->adjList[src];
    graph->adjList[src] = vextex;
}

// 打印图的邻接表
void printAdjList(ALGraph *graph)
{
    printf("Graph:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        Vextex* vexptr  = graph->adjList[i];
        printf("vertex %d: ", i);
        while(vexptr != NULL)
        {
            printf("(%d, weight: %d) ", vexptr->data, vexptr->weight);
            vexptr = vexptr->next;
        }
        printf("\n");
    }
}

// 深度优先遍历 -- 递归
void dfs_recusive(ALGraph* graph) 
{
    
    for (int i=0;i<graph->numVertices;i++) {
        
    }
}

// 深度优先遍历 -- 非递归
void dfs(ALGraph* graph) 
{

}

// 广度优先遍历 -- 递归
void bfs_recusive(ALGraph* graph) 
{
    
}

// 广度优先遍历 -- 非递归
void bfs(ALGraph* graph) 
{

}


int main() {
    ALGraph* graph = createALGraph(5) ;

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 4, 5);

    printAdjList(graph);
    return 0;
}
