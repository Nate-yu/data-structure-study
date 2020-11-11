#include<iostream>

using namespace std;

/*图的存储结构*/
typedef struct 
{
	char vexs[100]; // 顶点表
	int arc[100][100]; // 邻接矩阵，可以看作边表
	int numVertexes,numEdges; // 图中的顶点数和边数
}MGraph;

bool visited[100]; // 访问标志的数组

/*邻接矩阵的深度优先递归算法*/
void DFS(MGraph G, int i) {
	int j;
	visited[i] = true;
	cout<<G.vexs[i]<<" "; // 打印顶点
	for(j = 0; j < G.numVertexes; j++) {
		if (G.arc[i][j] == 1 && !visited[j])
		{
			DFS(G,j); // 对未访问的邻接顶点递归调用
		}
	}

}

/*邻接矩阵的深度遍历操作*/
void DFSTraverse(MGraph G) {
	int i;
	for(i = 0; i < G.numVertexes; i++) {
		visited[i] = false; // 初始化所有顶点状态都是未访问过状态
	}
	for(i = 0; i < G.numVertexes; i++) {
		// 对未访问过的顶点调用DFS，若是连通图则只会执行一次
		if(!visited[i]) {
			DFS(G,i);
		}
	}
}
