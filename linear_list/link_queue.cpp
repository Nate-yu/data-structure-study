#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef int QElementType;
typedef MAXSIZE 100;

// 结点结构
typedef struct QNode
{
	QElementType data;
	struct QNode *next;
}QNode, *QueuePtr;

// 队列的链表结构
typedef struct 
{
	QueuePtr font,rear; // 对尾指针
}LinkQueue;

/*入队操作*/
bool EnQueue(LinkQueue *Q, QElementType e) {
	QueuePtr s = (QueuePtr) malloc (sizeof(QNode));
	if (!s) // 存储分配失败
	{
		exit(OVERFLOW);
		return false;
	}
	s->data = e; 
	s->next = NULL;

	Q->rear->next = s; // 把拥有e的新结点s赋值给原队尾结点的后继
	Q->rear = s; // 把当前的s设置尾队尾结点，rear指针指向s
	return true;
}

/*出队操作*/
bool DeQueue(LinkQueue *Q, QElementType e) {
	QueuePtr p;
	if(Q->font == Q->rear)
		return false;
	p = Q->font->next; // 将欲删除的队头结点暂存给p
	*e = p->data;
	Q->font->next = p->next; // 将原队头结点后继p->next赋值给头结点后继
	if(Q->rear == p) // 若队头是队尾，则删除后将rear指向头结点
		Q->rear = Q->font;
	free(p);
	return true;
}