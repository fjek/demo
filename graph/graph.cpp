#include<iostream>

#define MAX_VEX_NUM 100

typedef int VextexType;

typedef struct EdgeNode
{
    int adjvex; // 
    int weight; // weight
    struct EdgeNode* next;
} EdgeNode;

typedef struct 
{
    VextexType data; // data field
    EdgeNode *firstedge; // point to edge
}VextexNode,AdjList[MAX_VEX_NUM];

typedef struct
{
    AdjList adjList;
    int numNode;
    int numEdge;
}ALGraph;
