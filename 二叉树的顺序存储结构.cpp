#include<iostream>
using namespace std;

#define MAXSIZE 100
#define MAX_TREE_SIZE 100

typedef  int TElemtype;
typedef TElemtype SqBiTree[MAX_TREE_SIZE];

//初始化二叉树
bool InitBiTree(SqBiTree T) {
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		T[i] = 0;
	}
	return true;
}

bool CreateBiTree(SqBiTree T)
{
	int i = 0;
	printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n", MAX_TREE_SIZE);
	while (i < 10)
	{
		T[i] = i + 1;

		if (i != 0 && T[(i + 1) / 2 - 1] == -1 && T[i] != -1) /* 此结点(不空)无双亲且不是根 */
		{
			printf("出现无双亲的非根结点%d\n", T[i]);
			exit(0);
		}
		i++;
	}
	while (i < MAX_TREE_SIZE)
	{
		T[i] = -1; /* 将空赋值给T的后面的结点 */
		i++;
	}

	return true;
}

//判断二叉树是否为空
bool BiEmpty(SqBiTree T) {
	if (T[0] == -1)
	{
		return true;
	}
	return false;
}

//二叉树深度
int BiTreeDepth(SqBiTree T) {
	int i, j = -1;
	for (i = MAX_TREE_SIZE - 1; i >=0; i--)
	{
		if (T[i] != -1) {
			break;
		}
	}
	i++;
	while (i >= powl(2, j))
	{
		j++;
	}
	return j;
}

//返回二叉树根节点的值
bool BiTreeRoot(SqBiTree T, TElemtype* e) {
	if (BiEmpty(T))
	{
		return false;
	}
	*e = T[0];
	return true;
}

//返回指定位置的值
struct Pos
{
	int level, order;
};//位置的格式

TElemtype BiTreeValue(SqBiTree T, Pos e) {
	return T[(int)powl(2, e.level - 1) + e.order -2];//减去2是因为结点下标从0开始，且表达式第一项已经求出了本层第一个结的位置，与order中的重复
}

//为指定位置的二叉树结点赋值
bool BiTreeAssign(SqBiTree T, Pos e, TElemtype value) {
	int p = (int)powl(2, e.level - 1) + e.order - 2;
	if (value != -1 && T[(p + 1) / 2 - 1] == -1)
	{
		return false;
	}
	else if(value == -1 && T[p * 2 + 1] != -1 || T[p * 2 + 2] != -1)
	{
		return false;
	}
	T[p] = value;
	return true;
}

//返回双亲结点
TElemtype BiTreeParent(SqBiTree T, TElemtype e) {
	if (T[0] == -1)
	{
		return false;
	}
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		if (T[i] == e) {
			return T[(i + 1) / 2 - 1];
		}
	}
	return -1;
}

//返回e的孩子结点
TElemtype Leftchild(SqBiTree T, TElemtype e) {
	if (T[0] == -1)
	{
		return false;
	}
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		if (T[i] == e)
			return T[i * 2 + 1];//如果是右孩子则下标为2i+2；
	}
	return false;
}

//返回左兄弟结点
TElemtype LeftSib(SqBiTree T, TElemtype e) {
	if (T[0] == -1)
	{
		return false;
	}
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		if (T[i] == e && i % 2 == 0)
			return T[i - 1];
	}
	return false;
}//右兄弟结点同理

//前序遍历递归方法
void PreTraverse(SqBiTree T, int index) {
	cout << T[index] << " ";
	if (T[2 * index + 1] != -1)
		PreTraverse(T, 2 * index + 1);
	if (T[2 * index + 2] != -1)
		PreTraverse(T, 2 * index + 2);
}

bool PreOrderTraverse(SqBiTree T) {
	if (!BiEmpty(T))
	{
		PreTraverse(T, 0);
	}
	return true;
}

//中序遍历
void InTraverse(SqBiTree T, int index) {
	
	if (T[2 * index + 1] != -1)
		InTraverse(T, 2 * index + 1);
	cout << T[index] << " ";
	if (T[2 * index + 2] != -1)
		InTraverse(T, 2 * index + 2);
}

bool InOrderTraverse(SqBiTree T) {
	if (!BiEmpty(T))
	{
		InTraverse(T, 0);
	}
	return true;
}

//后序遍历
void PostTraverse(SqBiTree T, int index) {

	if (T[2 * index + 1] != -1)
		PostTraverse(T, 2 * index + 1);
	if (T[2 * index + 2] != -1)
		PostTraverse(T, 2 * index + 2);
	cout << T[index] << " ";
}

bool PostOrderTraverse(SqBiTree T) {
	if (!BiEmpty(T))
	{
		PostTraverse(T, 0);
	}
	return true;
}


//层序遍历
void LevelOrderTraverse(SqBiTree T) {
	int i = MAX_TREE_SIZE - 1;
	while (T[i] == -1)
		i--;
	for (int j = 0; j <= i; j++)
	{
		if (T[j] != -1)
			cout << T[j] << " ";
	}
}

int main()
{
	Pos p;
	TElemtype e;
	SqBiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiEmpty(T), BiTreeDepth(T));
	bool i = BiTreeRoot(T, &e);
	if (i)
		printf("二叉树的根为：%d\n", e);
	else
		printf("树空，无根\n");
	printf("层序遍历二叉树:\n");
	LevelOrderTraverse(T);
	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T);
	printf("中序遍历二叉树:\n");
	InOrderTraverse(T);
	printf("后序遍历二叉树:\n");
	PostOrderTraverse(T);
	printf("修改结点的层号3本层序号2。");
	p.level = 3;
	p.order = 2;
	e = BiTreeValue(T, p);
	printf("待修改结点的原值为%d请输入新值:50 ", e);
	e = 50;
	BiTreeAssign(T, p, e);
	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T);
	printf("结点%d的双亲为%d", e, BiTreeParent(T, e));
	printf("左孩子 %d", Leftchild(T, e));
	printf("左兄弟 %d\n", LeftSib(T, e));
	return 0;
}