#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef int SElementType;
typedef MAXSIZE 100;

/*栈的顺序存储结构*/
typedef struct 
{
	SElementType data[MAXSIZE];
	int top;
}SqStack;

/*插入元素e作为新的栈顶元素*/
bool Push(SqStack *S, SElementType e) {
	if(S->top == MAXSIZE - 1){ // 栈满
		return false;
	}
	S->top++;
	S->data[S->top] = e;
	return true;
}

/*若栈不为空，则删除S的栈顶元素，用e返回其值，并返回true；否则返回false*/
bool Pop(SqStack *S, SElementType *e) {
	if(S->top == -1){ // 空栈
		return false;
	}
	*e = S->data[top]
	S->top--;
	return true;
}