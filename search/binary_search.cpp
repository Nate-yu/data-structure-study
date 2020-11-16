#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

/*
 * 二分查找
 * @param *a 查找数组
 * @param n 数组长度
 * @param key 查找的值
 */
int Binary_Search(int *a, int n, int key) {
	int low,high,mid;
	low = 1;
	high = n;
	while(low <= high) {
		mid = (low + high) / 2;
		if(key  < a[mid]) {
			high = mid - 1;
		} else if(key > a[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return 0;
}

int main()
{
	int array[11] = {0,1,16,24,35,47,59,62,73,88,99};
	cout<< Binary_Search(array,11,62) << endl;
	return 0;
}