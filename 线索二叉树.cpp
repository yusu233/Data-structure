#include<iostream>
using namespace std;

typedef char ElemType;
typedef enum{Link, Thread} Tag;

class BiThreadThree
{
public:
	BiThreadThree(): T(nullptr), H(){}
	void insert() {
		Insert(&T);
	}
	void inthread() {
		InorderThread(&H, T);
	}
	void traverse() {
		InOrderTraverse(H);
	}

private:
	//定义线索二叉树结点结构
	struct BiThrNode {
		ElemType data;
		Tag LTag, RTag;
		BiThrNode* lchild;
		BiThrNode* rchild;
	};

	//定义二叉树
	BiThrNode* T, *H;

	//初始化一颗空二叉树
	BiThrNode* InitBTT() {
		BiThrNode* T = new BiThrNode;
		T->data = '#';
		T->lchild = T->rchild = nullptr;
		T->LTag = T->RTag = Link;
		return T;
	}

	//向二叉树中插入元素(前序)
	void Insert(BiThrNode** T) {
		char ch;
		cout << "输入字符：";
		cin >> ch;
		if (ch == '#')
				*T = nullptr;
		else{
			*T = new BiThrNode;
			(*T)->data = ch;
			Insert(&(*T)->lchild);
			if ((*T)->lchild)
				(*T)->LTag = Link;
			Insert(&(*T)->rchild);
			if ((*T)->rchild)
				(*T)->RTag = Link;
		}
	}

	//中序遍历进行中序线索化
	BiThrNode* pre;//存储前一个结点的地址
	void InThread(BiThrNode* p) {
		if (p){
			InThread(p->lchild);
			if (p->lchild == nullptr){
				p->LTag = Thread;
				p->lchild = pre;
			}
			//结点p的后继结点还未访问，先修改上一个结点的右孩子
			if (pre->rchild == nullptr) {
				pre->RTag = Thread;
				pre->rchild = p;
			}
			pre = p;
			InThread(p->rchild);
		}
	}

	//中序遍历二叉树进行中序线索化，加入空头节点
	void InorderThread(BiThrNode** Thr , BiThrNode* T) {
		*Thr = new BiThrNode;
		(*Thr)->LTag = Link;
		(*Thr)->RTag = Thread;
		(*Thr)->rchild = *Thr;
		if (!T)
			(*Thr)->lchild = *Thr;
		else{
			(*Thr)->lchild = T;
			pre = (*Thr);
			InThread(T);
			pre->rchild = *Thr;
			pre->RTag = Thread;
			(*Thr)->rchild = pre;
		}
	}

	//中序遍历二叉线索树
	void InOrderTraverse(BiThrNode* T) {
		BiThrNode* p;
		p = T->lchild;
		while (p != T){
			while (p->LTag == Link)
				p = p->lchild;
			cout << p->data << endl;
			while (p->RTag == Thread && p->rchild != T){
				p = p->rchild;
				cout << p->data << endl;
			}
			p = p->rchild;
		}
	}
};


int main()
{
	BiThreadThree test;
	cout << "请按前序输入二叉树(如:'ABDH##I##EJ###CF##G##')" << endl;;
	test.insert(); /* 按前序产生二叉树 */
	test.inthread(); /* 中序遍历,并中序线索化二叉树 */
	cout << "中序遍历(输出)二叉线索树: " << endl;;
	test.traverse(); /* 中序遍历(输出)二叉线索树 */

	return 0;
}
