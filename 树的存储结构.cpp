#include<iostream>
using namespace std;

typedef int TElemtype;
#define MAXSIZE 20

//双亲表示法
struct PTNode
{
	TElemtype data;
	int parent;
};

struct Ptree
{
	PTNode nodes[MAXSIZE];
	int r, n;
};

//孩子表示法
struct CNode
{
	int child; //表示孩子结点在数组中存储的位置
	CNode* next;
};

struct PTNode
{
	TElemtype data;
	CNode* firstchild;
};

struct Tree
{
	PTNode nodes[MAXSIZE];
	int r, n;
};

//孩子兄弟表示法
struct CSNode
{
	TElemtype data;
	CNode* firstchild;
	CNode* rightsib;
};