#include<iostream>
using namespace std;

typedef int ElemType;

struct BTreeNode
{
	ElemType data;
	BTreeNode* lchild, * rchild;
};

//递归形式
BTreeNode* SearchBST1(BTreeNode* T, ElemType value) {
	if (!T)
		return NULL;
	if (value < T->data)
		return SearchBST1(T->lchild, value);
	if (value > T->data)
		return SearchBST1(T->rchild, value);
	return T;
}

//迭代形式
BTreeNode* SearchBST2(BTreeNode* T, ElemType value) {
	while (T)
	{
		if (value < T->data)
			T = T->lchild;
		else if (value > T->data)
			T = T->rchild;
		else
			return T;
	}
	return NULL;	
}

//插入元素
BTreeNode* InsertBST(BTreeNode* T, ElemType value) {
	if (!T)
	{
		T= new BTreeNode;
		T->data = value;
		T->lchild = T->rchild = NULL;
	}
	else if (value < T->data)
		T->lchild = InsertBST(T->lchild, value);
	else if (value > T->data)
		T->rchild = InsertBST(T->rchild, value);
	return T;
}

//删除元素
BTreeNode* DeleteBST(BTreeNode* T, ElemType value) {
	if (!T)
		cout << "二叉搜索树已经为空！" << endl;
	else if (value < T->data)
		T->lchild = DeleteBST(T->lchild, value);
	else if (value > T->data)
		T->rchild = DeleteBST(T->rchild, value);
	else
	{
		BTreeNode* temp;
		if (T->lchild != NULL && T->rchild != NULL)
		{
			temp = T->lchild;
			while (temp->rchild)
				temp = temp->rchild;
			T->data = temp->data;
			T->lchild = DeleteBST(T->lchild, temp->data);
		}
		else
		{
			if (!T->lchild)
				T = T->rchild;
			else if (!T->rchild)
				T = T->lchild;
		}
	}
	return T;
} 

void PreOrderTraverse(BTreeNode* T)
{
	if (T == NULL)
		return;
	cout << T->data << endl;;/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

int main(void)
{
	int i;
	int a[10] = { 62,88,58,47,35,73,51,99,37,93 };
	BTreeNode* T = NULL;

	for (i = 0; i < 10; i++)
	{
		T = InsertBST(T, a[i]);
	}
	cout << "插入完成的树：" << endl;
	PreOrderTraverse(T);
	cout << "删除93的树：" << endl;
	T = DeleteBST(T, 93);
	PreOrderTraverse(T);
	cout << "删除47的树：" << endl;
	T = DeleteBST(T, 47);
	PreOrderTraverse(T);
	return 0;
}