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
//交换元素
void swap(SqList* L, int i, int j) {
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
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

void BubbleSort(SqList* L) {
	for (int i = 1; i < L->length; i++){
		for (int j = L->length - 1; j >= i; j--) {
			if (L->data[j] > L->data[j + 1])
				swap(L, j, j + 1);
		}
	}
}

void BubbleSort_avavnce(SqList* L) {
	bool flag = true;
	for (int i = 1; i < L->length && flag; i++) {
		flag = false;
		for (int j = L->length - 1; j >= i; j--) {
			if (L->data[j] > L->data[j + 1]){
				swap(L, j, j + 1);
				flag = true;
			}
		}
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
	BubbleSort_avavnce(&L);
	print(L);
	return 0;
}