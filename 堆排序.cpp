#include<iostream>
using namespace std;
#define MAXSIZE 10000

struct SqList {
	int data[MAXSIZE + 1];
	int length;
};

//结构体初始化函数
void initSqList(SqList* L) {
	for (int i = 1; i <= MAXSIZE; i++)
		L->data[i] = 0;
	L->length = 0;
}

//插入元素
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

//构建最大堆
void HeapAdjust(SqList* L, int s, int length) {
	int temp = L->data[s];
	for (int child = 2 * s; child <= length; child *= 2){
		//寻找左右孩子中较大的一个
		if (child < length && L->data[child] < L->data[child + 1])
			child++;
		if (temp >= L->data[child])
			break;
		L->data[s] = L->data[child];
		s = child;
	}
	L->data[s] = temp;
}

//堆排序
void HeapSort(SqList* L) {
	//排序前先构建最大堆
	//由无序数组构建最大堆方法：从下往上、从右至左，将每个非叶节点当作根节点，将其和其子树调整成最大堆
	for (int i = L->length / 2; i > 0; i--)
		HeapAdjust(L, i, L->length);

	//进行排序
	for (int j = L->length; j > 0; j--){
		swap(L, 1, j);
		HeapAdjust(L, 1, j - 1);
	}
}

int main() {
	SqList L;
	initSqList(&L);
	insert(&L, 9);
	insert(&L, 1);
	insert(&L, 5);
	insert(&L, 8);
	insert(&L, 3);
	insert(&L, 7);
	insert(&L, 4);
	insert(&L, 6);
	insert(&L, 2);
	print(L);
	cout << endl;
	HeapSort(&L);
	print(L);

	return 0;
}