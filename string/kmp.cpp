#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

/*通过计算返回字串T的next数组*/
void get_next(String T, int *next) {
	int i,j;
	i = 1,j = 0;
	next[1] = 0;
	while(i < T[0]) { // T[0]表示串T的长度
		if (j == 0 || T[i] == T[j]) // T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
		{
			++i;
			++j; 
			next[i] = j;
		}
		else {
			j = next[j] // 若字符不相同，则j值回溯
		}
	}
}

/*返回字串T在主串S中第pos个字符之后的位置，若不存在返回0*/
int Index_KMP(String S, String T, int pos) {
	int i = pos; // i用于主串S当前位置下标值，若pos不为1，则从pos位置开始匹配
	int j = 1; // j用于字串T中当前位置下标值
	int next[255];
	get_next(T, next); // 对串T做分析，得到next数组
	while(i <= S[0] && j < T[0]) { // 若i小于S的长度且j小于T的长度时，循环继续
		if (j == 0 || S[i] == T[j]) // 两字母相等则继续 
		{
			++i;
			++j;
		}
		else{ // 指针后退重新开始匹配
			j = next[i]; // j退回合适的位置，i值不变
		}
	}
	if (j > T[0])
	{
		return i-T[0];
	}else{
		return 0;
	}
}

/*求模式串T的next函数修正值并存入数组nextal*/
void get_nextval(String T, int *nextval) {
	int i = 1, j = 0;
	nextval[1] = 0;
	while(i < T[0]) {
		if (j == 0 || T[i] == T[j]) // T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
		{
			++i;
			++j; 
			if (T[i] != T[j]) // 若当前字符与前缀字符不同，则当前的j为nextval在i位置的值
			{
				nextval[i] = j;
			}else { // 若相同，则将前缀字符的nextval值赋值给nextval在i的位置的值
				nextval[i] = nextval[j];
			}
		}
		else{
			j = nextval[j];
		}
	}
}