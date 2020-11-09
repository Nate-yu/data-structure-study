#include<iostream>

using namespace std;

/*图的存储结构*/
typedef struct 
{
	char vexs[100]; // 顶点表
	int arc[100][100]; // 邻接矩阵，可以看作边表
	int numVertexes,numEdges; // 图中的顶点数和边数
}MGraph;

/*建立无向网图的邻接矩阵表示*/
void CreateMGraph(MGraph *G) {
	int i,j,k,w;
	cout<<"please input the numVertexes and numEdges: "<<endl;
	cin>>G->numVertexes>>G->numEdges;
	// 读入顶点信息，建立顶点表
	for (i = 0; i < G->numVertexes; ++i)
	{
		cin>>G->vexs[i];
	}
	for (i = 0; i < G->numVertexes; ++i)
	{
		for (j = 0; i < numVertexes; ++j)
		{
			// 邻接矩阵初始化
			G->arc[i][j] = 65535;
		}
	}

	for(k = 0; k < G->numEdges; k++) {
		cout<<"please input edge's (vi,vj) and weight w: "<<endl;
		cin>>i>>j>>w;
		G->arc[i][j] = w;
		G->arc[i][j] = G->arc[j][i]; // 无向图对称
	}
}