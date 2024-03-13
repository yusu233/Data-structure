#include<iostream>
#include<algorithm>
using namespace std;

typedef int AVLTElemType;

class AVLTree
{
public:
	AVLTree() : AVLTreeRoot(nullptr) {}
	void insertelem(AVLTElemType value) {
		AVLTreeRoot = InsertAVLTree(AVLTreeRoot, value);
	}
	void deleteelem(AVLTElemType value) {
		AVLTreeRoot = DeleteAVLTree(AVLTreeRoot, value);
	}
private:
	//定义AVL树的结点结构
    struct Node
    {
	  AVLTElemType data;
	  Node* lchild;
	  Node* rchild;
	  int height;
	  Node(AVLTElemType value) : data(value), lchild(nullptr), rchild(nullptr), height(1) {}
    };

	//定义结点
	Node* AVLTreeRoot;

	//计算高度
	int height(Node* node) {
		return node == nullptr ? 0 : node->height;
	}

	//右旋转操作
	Node* RightRotate(Node* node) {
		Node* child = node->lchild;
		node->lchild = child->rchild;
		child->rchild = node;
		node->height = max(height(node->lchild), height(node->rchild)) + 1;
		child->height = max(height(child->lchild), height(child->rchild)) + 1;
		//返回旋转完成子树新的根节点
		return child;
	}

	//左旋转操作
	Node* LeftRotate(Node* node) {
		Node* child = node->rchild;
		node->rchild = child->lchild;
		child->lchild = node;
		node->height = max(height(node->lchild), height(node->rchild)) + 1;
		child->height = max(height(child->lchild), height(child->rchild)) + 1;
		//返回旋转完成子树新的根节点
		return child;
	}

	//左平衡（先左旋转后右旋转）
	Node* LeftBalance(Node* node) {
		node->lchild = LeftRotate(node->lchild);
		node = RightRotate(node);
		return node;
	}

	//右平衡（先右旋转后左旋转）
	Node* RightBalance(Node* node) {
		node->rchild = RightRotate(node->rchild);
		node = LeftRotate(node);
		return node;
	}

	//AVL树插入元素
	Node* InsertAVLTree(Node* T, AVLTElemType value) {
		if (!T){
		  Node* temp = new Node(value);
		  return temp;
		}
		else if (value < T->data) {
			T->lchild = InsertAVLTree(T->lchild, value);
			if (height(T->lchild) - height(T->rchild) > 1) {
				if (height(T->lchild->lchild) > height(T->lchild->rchild))
					T = RightRotate(T);
				else
					T = LeftBalance(T);
			}
		}
		else if (value > T->data) {
			T->rchild = InsertAVLTree(T->rchild, value);
			if (height(T->rchild) - height(T->lchild)> 1) {
				if (height(T->rchild->rchild) > height(T->rchild->lchild))
					T = LeftRotate(T);
				else
					T = RightBalance(T);
			}
		}
		//更新结点高度
		T->height = max(height(T->lchild), height(T->rchild)) + 1;
		return T;
	}

	//AVL树删除元素
	Node* DeleteAVLTree(Node* T, AVLTElemType value) {
		if (!T)
			cout << "AVL树已经为空！" << endl;
		else if (value < T->data) {
			T->lchild = DeleteAVLTree(T->lchild, value);
			//检查左子树删除完元素之后是否会造成不平衡，不平衡就更新为平衡二叉树
			if (height(T->rchild) - height(T->lchild) > 1){
				if (height(T->rchild->lchild) > height(T->rchild->rchild))
					T = RightBalance(T);
				else
					T = LeftRotate(T);
			}
		}
		else if (value > T->data) {
			T->rchild = DeleteAVLTree(T->rchild, value);
			if (height(T->lchild) - height(T->rchild) > 1){
				if (height(T->lchild->lchild) >= height(T->lchild->rchild))
					T = RightRotate(T);
				else
					T = LeftBalance(T);
			}
		}
		else {
			if (T->lchild != nullptr && T->rchild != nullptr){
				//避免删除结点之后的失衡情况出现，删除左右子树中较高的一个
				if (height(T->lchild) >= height(T->rchild)){
					Node* temp = T->lchild; 
					while (temp->rchild){
						temp = temp->rchild;
					}
					T->data = temp->data;
					T->lchild = DeleteAVLTree(T->lchild, temp->data);
				}
				else {
					Node* temp = T->rchild;
					while (temp->lchild){
						temp = temp->lchild;
					}
					T->data = temp->data;
					T->rchild = DeleteAVLTree(T->rchild, temp->data);
				}
			}
			else {
				if (T->lchild != nullptr) {
					T->data = T->lchild->data;
					delete T->lchild;
					T->lchild = nullptr;
				}
				else if(T->rchild != nullptr) {
					T->data = T->rchild->data;
					delete T->rchild;
					T->rchild = nullptr;
				}else{
					return nullptr;
				}
			}
		}
		T->height = max(height(T->lchild), height(T->rchild)) + 1;
		return T;
	}
};

int main() {
	AVLTree avl;
	//int test[10] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	for (int i = 1; i < 11; i++)
	{
		avl.insertelem(i);
	}
	avl.deleteelem(9);
	avl.deleteelem(10);
	avl.deleteelem(6);
	avl.deleteelem(1);
	avl.deleteelem(2);
	avl.deleteelem(3);
	return 0;
}