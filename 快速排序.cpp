#include<iostream>
using namespace std;
#define MAXSIZE 100
#define CUTOFF 7  //决定使用快排还是插入排序的阈值

struct SqList {
	int data[MAXSIZE + 1];
	int length;
};

//结构体初始化函数
void initSqList(SqList* L) {
	for (int i = 0; i <= MAXSIZE; i++)
		L->data[i] = 0;
	L->length = 0;
}

//插入元素（从下标1开始存储数据）
void insert(SqList* L, int data) {
	L->data[1 + L->length++] = data;
}

//打印数组
void print(SqList L) {
	for (int i = 1; i <= L.length; i++)
		cout << L.data[i] << endl;
}

//交换元素
void swap(int* L, int i, int j) {
	int temp = L[i];
	L[i] = L[j];
	L[j] = temp;
}

//直接插入排序算法
void InsertSort(int* L, int Left, int Right) {
	int j;
	for (int i = Left + 1; i <= Right; i++) {
		if (L[i] < L[i - 1]) {
			int temp = L[i];
			for (j = i - 1; L[j] > temp; j--)
				L[j + 1] = L[j];
			L[j + 1] = temp;
		}
	}
}

//主元选取
int Median3(int A[], int Left, int Right) {
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		swap(A, Left, Center);
	if (A[Left] > A[Right])
		swap(A, Left, Right);
	if (A[Center] > A[Right])
		swap(A, Center, Right);
	//A[Left] <= A[Center] <= A[Right]
	swap(A, Center, Right - 1);
	//将pivot藏到右边，只需要考虑A[Left + 1]---A[Right - 2]
	return A[Right - 1];
}

//快排
void QuickSort(int A[], int Left, int Right) {
	if (Right - Left >= CUTOFF) {
		int Pivot = Median3(A, Left, Right);
		int i = Left, j = Right - 1;
		for (; ; ) {
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			//当集合中的元素值等于pivot时，依然做交换，保证最后主元位于集合的中间位置
			if (i < j)
				swap(A, i, j);
			else
				break;
		}
		swap(A, i, Right - 1);
		QuickSort(A, Left, i - 1);
		QuickSort(A, i + 1, Right);
	}
	else
		InsertSort(A, Left, Right);
}

void Quick(SqList* L) {
	QuickSort(L->data, 1, L->length);
}

int main() {
	SqList L;
	initSqList(&L);
	insert(&L, 12);
	insert(&L, 9);
	insert(&L, 1);
	insert(&L, 10);
	insert(&L, 5);
	insert(&L, 8);
	insert(&L, 11);
	insert(&L, 3);
	insert(&L, 7);
	insert(&L, 13);
	insert(&L, 4);
	insert(&L, 6);
	insert(&L, 14);
	insert(&L, 2);

	print(L);
	cout << endl;

	Quick(&L);
	print(L);

	return 0;
}