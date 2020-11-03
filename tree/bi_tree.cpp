#include<iostream>
#include<cstdlib>

using namespace std;

/*二叉树的二叉链表结点结构定义*/
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/* 
 * 二叉树的前序遍历递归算法
 * 从根节点出发，先左后右
 */
void PreOrderTraverse(BiTree T) {
	if(T == NULL) {
		return;
	}
	cout<<T->data<<" "; // 显示结点数据
	PreOrderTraverse(T->lchild); // 再先序遍历左子树
	PreOrderTraverse(T->rchild); // 最后先序遍历右子树
}

/*
 * 二叉树的中序遍历递归算法
 * 左子树优先，有左则左，无左则右
 */
void InOrderTraverse(BiTree T) {
	if(T == NULL) {
		return;
	}
	InOrderTraverse(T->lchild); // 中序遍历左子树
	cout<<T->data<<" "; // 显示结点数据
	InOrderTraverse(T->rchild); // 最后中序遍历右子树
}

/*
 * 二叉树的中序遍历递归算法
 * 从左到右，先叶子后结点
 */
void PostOrderTraverse(BiTree T) {
	if(T == NULL) {
		return;
	}
	PostOrderTraverse(T->lchild); // 先后序遍历左子树
	PostOrderTraverse(T->rchild); // 再后序遍历右子树
	cout<<T->data<<" "; // 显示结点数据
}

/*
 * 按前序输入二叉树中结点的值
 * #表示空树，构造二叉链表表示二叉树T
 */
void CreateBiTree(BiTree *T) {
	char ch;
	cin>>ch;
	if (ch == '#')
		*T == NULL;
	else {
		*T = (BiTree) malloc (sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&(*T) -> lchild); // 构造左子树
		CreateBiTree(&(*T) -> rchild); // 构造右子树
	}

}