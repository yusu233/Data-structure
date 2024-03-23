#include<iostream>
using namespace std;

//简单的顺序表查找
int Sequential_Search(int* a, int n, int key) {
	//为了与第二种查找方式下标统一，数组从下标1开始存储
	for (int i = 1; i <= n; i++){
		if (a[i] == key)
			return i;
	}
	return 0;
}

//使用哨兵节点的顺序表查找
int Sequential_Search2(int* a, int n, int key) {
	a[0] = key;
	int i = n;
	while (a[i] != key)
		i--;
	return i;
}

