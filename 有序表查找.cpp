#include<iostream>
using namespace std;

//二分查找
int Binary_Search(int a[], int n, int value) {
	int left = 0, right = n;

	//左闭右闭形式
	while (left <= right) {	
		int middle = (left + right) / 2;
		if (a[middle] < value){
			left = middle + 1;
		}
		else if (a[middle] > value) {
			right = middle - 1;
		}
		else{
			return middle;
		}
	}
	return 0;
}

//插值查找
int Interpolation_Search(int a[], int n, int value) {
	int left = 0, right = n;
	int len = sizeof(a);
	//左闭右闭形式
	while (left <= right) {
		int middle = left + (value - a[left]) / (a[right] - a[left]) * (right - left);
		if (a[middle] < value) {
			left = middle + 1;
		}
		else if (a[middle] > value) {
			right = middle - 1;
		}
		else {
			return middle;
		}
	}
	return 0;
}

//斐波那契查找
//生成斐波那契数列
#define MAXSIZE 10
void Fibonacci(int* f) {
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < MAXSIZE; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
}

int Fibonacci_Search(int a[], int n, int value, int f[]) {
	int right = n - 1;
	int left = 0;
	int middle, k = 0;
	//寻找最接近且大于等于数组a的斐波那契数列的下标
	while (n > f[k] - 1){
		k++;
	}
	//将a补满至斐波那契数列中对应数量的大小
	for (int i = n; i < f[k] - 1; i++){
		a[i] = a[n];
	}
	while (left <= right){
		middle = left + f[k - 1] - 1;
		if (a[middle] < value){
			left = middle + 1;
			k = k - 2;
		}
		else if (a[middle] > value){
			right = middle - 1;
			k = k - 1;
		}
		else{
			if (middle <= n)
				return middle;
			else return n;
		}
	}
	return 0;
}

int main() {
	int a[10] = {1, 16, 24, 35, 47, 59, 62, 73, 88, 99 };
	int f[MAXSIZE];
	Fibonacci(f);
	for (int i = 0; i < MAXSIZE; i++){
		cout << f[i] << " ";
	}
	cout << Fibonacci_Search(a, 10, 59, f);
	return 0;
}