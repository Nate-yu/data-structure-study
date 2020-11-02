#include<iostream>

using namespace std;
#define MAX_TREE_SIZE 100


/*树的双亲表示法结点结构定义*/

/*结点结构*/
typedef struct PNode
{
	int data; // 结点数据
	int parent; // 双亲位置
}PTNode;

/*树结构*/
typedef struct 
{
	PTNode nodes[MAX_TREE_SIZE]; // 结点数组
	int r,n; // 根的位置和结点数
}PTree;

/*树的孩子表示法结构定义*/

/*孩子结点*/
typedef struct CTNode
{
	int child;
	struct CTNode *next;
} *ChildPtr;

/*表头结构*/
typedef struct 
{
	int data;
	ChildPtr firstchild;
}CTBox;

/*树结构*/
typedef struct 
{
	CTBox nodes[MAX_TREE_SIZE]; // 结点数组
	int r,n; // 根的位置和结点数
}CTree;

