#include<iostream>
using namespace std;

typedef char TElemType;
string strs = "AB-D--CEGRY------";//非常容易堆栈溢出，不能乱改，改动需要响应改变str的大小
int length = strs.size();
char* str;
int index = 0;

struct BTNode
{
	TElemType data;
	BTNode* lchild, * rchild;
};

void InitBiTree(BTNode** T);
void BTreeCreate(BTNode** T);
void PreOrderTraverse(BTNode* T);

int main() {
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = strs[i];
	}
	BTNode* T;
	InitBiTree(&T);
	BTreeCreate(&T);
	PreOrderTraverse(T);
	return 0;
}


void InitBiTree(BTNode** T)
{
	*T = NULL;
}

void BTreeCreate(BTNode** T) {
	TElemType temp = str[index++];
	if (temp == '-')
		*T = NULL;
	else
	{
		*T = new BTNode;
		(*T)->data = temp;
		BTreeCreate(&(*T)->lchild);
		BTreeCreate(&(*T)->rchild);
	}
}


void PreOrderTraverse(BTNode* T)
{
	if (T == NULL)
		return;
	cout << T->data << endl;;/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}