#include<iostream>
#include<cstdio>
using namespace std;

typedef int QElementType;
typedef MAXSIZE 100;

// 循环队列的顺序存储结构
typedef struct 
{
	QElementType data[MAXSIZE];
	int font; // 头指针
	int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;

/*初始化一个空队列*/
bool InitQueue(SqQueue *Q) {
	Q -> font = 0;
	Q -> rear = 0;
	return true;
}

/*求队列的长度*/
int QueueLength(SqQueue Q) {
	return (Q.rear-Q.font+MAXSIZE) % MAXSIZE;
}

/*若队列未满，则插入元素e作为新的队列元素*/
bool EnQueue(SqQueue *Q, QElementType e) {
	if ((Q->rear+1) % MAXSIZE == Q->font) // 队列满的判断
	{
		return false;
	}

	Q->data[Q->rear] = e; // 将e赋值给对尾
	Q->rear = (Q->rear + 1) % MAXSIZE; // rear指针向后移动一位

	return true;
}

/*若队列不空，则删除对头元素，用e返回*/
bool DeQueue(SqQueue *Q, QElementType *e) {
	if (Q->font == Q->rear) // 判断队列是否为空
	{
		return false;
	}

	*e = Q->data[Q->font];
	Q->font = (Q->font+1) % MAXSIZE;
	return true;
}