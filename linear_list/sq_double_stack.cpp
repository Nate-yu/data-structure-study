#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef int SElementType;
typedef MAXSIZE 100;

/*两栈共享空间结构*/
typedef struct 
{
	SElementType data[MAXSIZE];
	int top1; // 栈1栈顶指针
	int top2; // 栈2栈顶指针
}SqDoubleStack;

/*将元素e压入栈*/
bool Push(SqDoubleStack *S, SElementType e, int stackNumber) {
	// 栈满，无法添加新元素
	if(S->top1 + 1== S -> top2) {
		return false;
	}
	// 栈1有元素进栈
	if(stackNumber == 1) {
		S->data[++S->top1] = e; // 若栈1则先top1+1后给数组元素赋值
	} 
	// 栈2有元素进栈
	else if(stackNumber == 2) {
		S->data[--S->top2] = e; // 若栈2则先top2-1后给数组元素赋值
	}
	return true;
}

/*若栈不空，则删除S的栈顶元素，用e返回其值*/
bool Pop(SqDoubleStack *S, SElementType *e, int stackNumber) {
	if (stackNumber == 1)
	{
		if(S->top1 == -1) { // 说明栈1已经是空栈，溢出
			return false;
		}
		*e = S->data[S->top1--]; // 将栈1的栈顶元素出栈
	}
	else if(stackNumber == 2) {
		if(S->top2 = MAXSIZE) { // 说明栈2已经是空栈，溢出
			return false;
		}
		*e = S->data[S->top2++];
	}
	return true;
}