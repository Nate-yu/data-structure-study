#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef int ElementType;

typedef struct Node
{
	ElementType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

/*返回L中第i个元素的值*/
ElementType GetElem(LinkList *L, int i) {
	int j;
	ElementType e;
	LinkList p;
	p = (*L)->next; // 让p指向链表L的第一个结点
	j = 1; // 计数器
	while(p && j < i) { // 当p不为空且计数器j没有等于i时
		p = p->next;
		++j;
	}
	if (!p || j > i) // 第i个结点不存在
		return 0;
	e = p->data;
	return e;
}

/*在L中第i个结点位置之前插入新的数据元素e，L的长度加1*/
bool ListInsert(LinkList *L, int i, ElementType e) {
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return false;
	s = (LinkList)malloc(sizeof(Node)); // 生成新结点
	s->data = e;

	/*开始插入新结点*/
	s->next = p->next; // 将p的后继结点赋值给s的后继
	p->next = s; // 将s赋值给p的后继
	return true;
}

/*删除L的第i个结点，并用e返回其值，L的长度减1*/
bool ListDelete(LinkList *L, int i) {
	LinkList p,q;
	int j;
	p = *L;
	j = 1;
	while(p->next && j < i) { // 遍历寻找第i-1个结点
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return false;
	
	/*开始删除第i个结点*/
	q = p->next; 
	p->next = q->next; // 将q的后继结点赋值给p的后继
	free(q);
	return true;
}

/*随机产生n个元素的值，建立带表头结点的单链线性表L（头插法,栈）*/
void CreateListHead(LinkList *L,int n) {
	LinkList p;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL; // 建立一个带头结点的单链表
	for(int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node)); // 生成新结点
		p->data = rand()%100+1; // 随机生成100以内的数字
		p->next = (*L)->next; // 将L的后继结点（头结点）赋值给p（新结点）的后继
		(*L)->next = p; // 插入到表头
	}
}

/*随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法,队列）*/
void CreateListTail(LinkList *L, int n) {
	LinkList p,tail;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	tail = *L; // tail为指向尾部的结点
	for(int i = 0; i < n; i++) {
		p = (Node *) malloc(sizeof(Node));
		p->data = rand() % 100 +1;
		tail->next = p; // 将表尾终端结点的指针指向新结点
		tail = p; // 将当前的新结点定义为表尾终端结点
	}
	tail->next = NULL; // 循环结束后，将当前结点的指针域置空，表示当前链表结束
}

/*单链表的整表删除*/
bool ClearList(LinkList *L) {
	LinkList p,q;
	p = (*L)->next; // p指向第一个结点
	while(p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return true;
}

/*单链表的整表打印*/
void ListPrint(LinkList *L) {
	LinkList p = *L;
	int j = 1;
	while(p->next) {
		p = p->next;
		cout<<p->data<<" ";
		++j;
	}
}

int main() 
{
	LinkList *L;
	L = (LinkList*)malloc(sizeof(Node));
	int n;
	cout<<"Please input the size of the linklist that you want to create: ";
	cin>>n;

	/*单链表的初始化（用尾插法建立单链表）*/
	CreateListTail(L,n);
	cout<<"The linklist: "<<endl;
	ListPrint(L);
	cout<<endl;

	/*测试GetElem函数*/
	cout<<"Please input the number: ";
	int i;
	cin>>i;
	cout<<"The "<<i<<"th element is: ";
	cout<<GetElem(L,i)<<endl;

	
	return 0;
}