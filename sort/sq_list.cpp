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