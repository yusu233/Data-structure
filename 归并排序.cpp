#include<iostream>
using namespace std;
#define MAXSIZE 100

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
void swap(SqList* L, int i, int j) {
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}

//归并操作
//参数：待排序数组、临时数组、左半起点、右半起点、数组终点
void Merge(int A[], int TempA[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;
	int temp = L;
	int Length = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd){
		if (A[L] <= A[R])
			TempA[temp++] = A[L++];
		else
			TempA[temp++] = A[R++];
	}
	while (L <= LeftEnd)
		TempA[temp++] = A[L++];
	while (R <= RightEnd)
		TempA[temp++] = A[R++];
	//将临时数组的值复制到结果数组中
	for (int i = 0; i < Length; i++, RightEnd--)
		A[RightEnd] = TempA[RightEnd];
}

//递归形式的归并排序
void Msort(int A[], int TempA[], int L, int RightEnd) {
	int Center;
	if (L < RightEnd){
		Center = (L + RightEnd) / 2;
		Msort(A, TempA, L, Center);
		Msort(A, TempA, Center + 1, RightEnd);
		Merge(A, TempA, L, Center + 1, RightEnd);
	}
}

void MergeSort(SqList* L) {
	int* TempA = new int[MAXSIZE];
	if (TempA){
		Msort(L->data, TempA, 1, L->length);
			delete[] TempA;
	}
	else
		cout << "空间不足！ ";
}


//非递归形式的归并排序(N为排序元素的个数，length为当前有序子列的长度）
//参数：待排序数组、临时数组、左半起点、右半起点、数组终点
void Merge1(int A[], int TempA[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;
	int temp = L;
	int Length = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TempA[temp++] = A[L++];
		else
			TempA[temp++] = A[R++];
	}
	while (L <= LeftEnd)
		TempA[temp++] = A[L++];
	while (R <= RightEnd)
		TempA[temp++] = A[R++];
}  //相比于递归形式的merge函数，将复制数组的部分放到了MergeSort函数中

void MergePass(int A[], int TempA[], int N, int length) {
	int i;
	for (i = 1;  i <= N - 2 * length;  i += 2 * length)
		Merge1(A, TempA, i, i + length, i + 2 * length - 1);
	//归并最后还剩下一个满的子列和一个不满的子列
	if (i + length <= N)
		Merge1(A, TempA, i, i + length, N);
	else
		for (int j = i; j <= N; j++)
			TempA[j] = A[j];
}

void MergeSort1(SqList* L) {
	int length = 1;  //初始化子序列长度
	int* TempA = new int[MAXSIZE];
	if (TempA) {
		while (length < L->length){
			//为了保证最后的排序结果保存在data数组中，将复制操作成对进行
			MergePass(L->data, TempA, L->length, length);
			length *= 2;
			MergePass(TempA, L->data, L->length, length);
			length *= 2;
		}
		delete[] TempA;
	}
	else
		cout << "空间不足！ ";
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

	MergeSort1(&L);
	print(L);

	return 0;
}