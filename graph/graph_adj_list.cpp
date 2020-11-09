#include<iostream>
#include<cstdlib>

using namespace std;

/*边表结点*/
typedef struct EdgeNode
{
	int adjvex; // 邻接点域，存储该顶点对应的下标
	int weight; // 用于存储权值
	struct int *next; // 链域，用于指向下一个 邻接点
}EdgeNode;

/*顶点表结点*/
typedef struct VertexNode
{
	char data; // 顶点域，用于存储顶点信息
	EdgeNode *firstedge; // 边表头指针
}VertexNode,AdjList[100];

/*无向图的邻接表存储结构*/
typedef struct 
{
	AdjList adjList; 
	int numVertexes,numEdges; // 图中当前顶点数和边数
}GraphAdjList;

/*建立图的邻接表结构*/
void CreateALGraph(GraphAdjList *G) {
	int i,j,k;
	EdgeNode *e;
	cout<<"please input numVertexes and numEdges: "<<endl;
	cin>>G->numVertexes>>G->numEdges;
	// 读取顶点信息，建立顶点表
	for(i = 0; i < G->numVertexes; i++) {
		cin>>adjList[i].data; // 输入顶点信息
		G->adjList[i].firstedge = NULL; // 将边表置为空表
	}
	// 建立边表
	for(k = 0; k < G->numEdges; k++) {
		cin>>"please input edge's (vi,vj): "<<endl;
		cin>>i>>j;
		e = (EdgeNode *)malloc(sizeof(EdgeNode)); // 生成边表结点
		e->adjvex = j; // 邻接序号为j
		e->next = G->adjList[i].firstedge; // 将e指针指向当前顶点指向的结点
		G->adjList[i].firstedge = e; // 将当前顶点的指针指向e
		e = (EdgeNode *)malloc(sizeof(EdgeNode)); // 生成边表结点
		e->adjvex = i; // 邻接序号为i
		e->next = G->adjList[j].firstedge; // 将e指针指向当前顶点指向的结点
		G->adjList[j].firstedge = e; // 将当前顶点的指针指向e
	}
}