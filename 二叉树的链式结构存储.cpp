#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef char TElemType;
TElemType null = ' ';
int treeIndex = 1;
typedef char String[24]; /*  0号单元存放串的长度 */
String str;

//二叉树结点结构
struct BTNode {
	TElemType data;
	BTNode* lchild, *rchild;
};

//建立空二叉树
bool InitBTree(BTNode** T) {
	T = NULL;
	return true;
}


//判断二叉树是否为空
bool BTreeEmpty(BTNode* T) {
	if (T->data == ' ')
	{
		return true;
	}
	return false;
}

//二叉树深度
int BTreeDepth(BTNode* T) {
	int leftdepth, rightdepth;
	if (BTreeEmpty(T))
		return 0;
	if (T->lchild)
		leftdepth = BTreeDepth(T->lchild);
	else
		leftdepth = 0;
	if (T->rchild)
		rightdepth = BTreeDepth(T->rchild);
	else
		rightdepth = 0;
	return leftdepth > rightdepth ? leftdepth : rightdepth;
}

//返回二叉树的根节点
TElemType BTreeRoot(BTNode* T) {
	if (BTreeEmpty(T))
		return ' ';
	else
		return T->data;
}

//返回指定结点的值
TElemType Value(BTNode* position) {
	return position->data;
}

//为指定结点赋值
void BTreeAssign(BTNode* position, TElemType value) {
	position->data = value;
}

//前序遍历二叉树
void PreOrderTraverse(BTNode* T) {
	if (T == NULL)
		return;
	cout << T->data << endl;
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//中序遍历二叉树
void InOrderTraverse(BTNode* T) {
	if (T == NULL)
	{
		return;
	}
	InOrderTraverse(T->lchild);
	cout << T->data << endl;
	InOrderTraverse(T->rchild);
}

//后序遍历二叉树
void PostOrderTraverse(BTNode* T) {
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout << T->data << endl;
}

bool StrAssign(String T, const char* chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
		return false;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return true;
	}
}

void CreateBiTree(BTNode* &T)
{
	TElemType ch;

	/* scanf("%c",&ch); */
	ch = str[treeIndex++];

	if (ch == '#')
		T = NULL;
	else
	{
		T = new BTNode;
		if (!T)
			exit(OVERFLOW);
		T->data = ch; /* 生成根结点 */
		CreateBiTree(T->lchild); /* 构造左子树 */
		CreateBiTree(T->rchild); /* 构造右子树 */
	}
}

int main()
{
	BTNode* T;
	TElemType e1;
	InitBTree(&T);
	StrAssign(str, "ABDH#K###E##CFI###G#J##");

	CreateBiTree(T);

	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BTreeEmpty(T), BTreeDepth(T));
	e1 = BTreeRoot(T);
	printf("二叉树的根为: %c\n", e1);

	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树:");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);
	return 0;
}