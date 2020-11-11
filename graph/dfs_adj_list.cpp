#include<iostream>
#include<cstdlib>

using namespace std;

/*边表结点*/
typedef struct EdgeNode
{
	int adjvex; // 邻接点域，存储该顶点对应的下标
	int weight; // 用于存储权值
	struct EdgeNode *next; // 链域，用于指向下一个 邻接点
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

bool visited[100]; // 访问标志的数组

/*邻接表的深度优先递归算法*/
void DFS(GraphAdjList GL,int i) {
	EdgeNode *p;
	visited[i] = true;
	cout<<GL->adjList[i].data;

	p = GL->adjList[i].firstedge;
	while(p){
		if(!visited[p->adjvex]) {
			DFS(GL, p->adjvex); // 对未访问的邻接顶点递归调用
		}
		p = p->next;
	}

}

/*邻接表的深度遍历操作*/
void DFSTraverse(GraphAdjList GL) {
	int i;
	for(i = 0; i < GL->numVertexes; i++) {
		visited[i] = false; // 初始化所有顶点状态都是未访问过状态
	}
	for(i = 0; i < GL->numVertexes; i++) {
		// 对未访问过的顶点调用DFS，若是连通图则只会执行一次
		if(!visited[i]) {
			DFS(GL,i);
		}
	}
}