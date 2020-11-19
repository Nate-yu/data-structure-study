#include<iostream>
#include<cstdlib>

using namespace std;

#define MAXSIZE 10
typedef struct 
{
	int r[MAXSIZE+1]; // 用于存储要排序的数组，r[0]用作哨兵或临时变量
	int length; // 记录顺序表的长度
}SqList;

/*交换L中数组r的下标为i和j的值*/
void swap(SqList *L,int i,int j) {
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*初级冒泡*/
void BubbleSort0(SqList *L) {
	for(int i = 1; i < L->length; i++) {
		for(int j = i+1; j <= L->length; j++) {
			if (L->r[i] > L->r[j]) 
			{
				swap(L,i,j);
			}
		}
	}
}

/*正版冒泡*/
void BubbleSort(SqList *L) {
	for(int i = 1; i < L->length; i++) {
		for(int j = L->length-1; j >= i; j++) { 
			if (L->r[j] > L->r[j+1]) 
			{
				swap(L,j,j+1);
			}
		}
	}
}

/*优化冒泡*/
void BubbleSort2(SqList *L) {
	bool flag = true;
	for(int i = 1; i < L->length && flag; i++) { //若flag为ture则退出循环
		flag =  false; // 初始为false
		for(int j = L->length-1; j >= i; j++) { 
			if (L->r[j] > L->r[j+1]) 
			{
				swap(L,j,j+1);
				flag = true; // 若有数据交换，则flag为ture
			}
		}
	}
}