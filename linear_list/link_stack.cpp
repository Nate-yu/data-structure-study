#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef int SElementType;
typedef MAXSIZE 100;

typedef struct StackNode
{
	SElementType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr; // 声明结点时用StackNode，声明指针时用LinkStackPtr

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

/*插入元素e为新的栈顶元素*/
bool Push(LinkStack *S, SElementType e) {
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top; // 把当前的栈顶元素赋值给新结点的直接后继
	S->top = s; // 将新结点s赋值给栈顶指针
	S->count++;
	return true;
}

/*若栈不为空，则删除栈顶元素*/
bool Push(LinkStack *S, SElementType e) {
	LinkStackPtr p;
	if (StackEmpty(*S))
	{
		return false;
	}
	*e = S->top->data;
	p = S->top; // 将栈顶元素赋值给p
	S->top = S->top->next; // 使得栈顶指针下移一位，指向后一结点
	free(p);
	S->count--;
	return true;
}

bool StackEmpty(LinkStack *S) {
	if(S->top != null) {
		return false;
	}
	return true;
}