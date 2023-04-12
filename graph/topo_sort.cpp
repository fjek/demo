#include <iostream>
#include <queue>
#include <list>
using namespace std;

#define MAX_VERTEX_NUM 20
#define VertexType int // 顶点数据的类型
#define InfoType int   // 图中弧或者边包含的信息的类型

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nexarc;
    InfoType *info;
} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int vexNum,arcNum;
    int kind;
}ALGraph;


class Graph
{

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool topoSort();
};

Graph::Graph(int count)
{
    this->count = count;

    adj = new list<int>[count];
    indegree_list = new int[count];
    for (int i = 0; i < count; i)
    {
        indegree_list[i] = 0;
    }
}

void Graph::addEdge(int v, int w){
    adj[v].push}

Graph::~Graph()
{
    delete[] adj;
    delete[] indegree_list;
}