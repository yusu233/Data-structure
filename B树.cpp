#include<iostream>
//为了方便使用关键字的下标计算孩子数组的下标，关键字数组从1开始使用
//（如keys[1]的左孩子为1-1=0，右孩子为1）

typedef struct Node {
	int level;  //树的阶数
	int keyNum;  //关键字的数量
	int childNum;  //孩子数量
	int* keys;  //关键字数组；
	struct Node** children;  //孩子数组(需要修改指针的指向，所以需要使用指针的指针)
	struct Node* parent;  //父亲指针
} Node;

//结构体初始化函数 
Node* initNode(int level) {
	Node* node = new Node;
	node->level = level;
	node->keyNum = 0;
	node->childNum = 0;
	node->keys = new int[level + 1];
	node->children = new Node*[level];
	node->parent = nullptr;
	for (int i = 0; i < level; i++){
		node->keys[i] = 0;
		node->children[i] = nullptr;
	}
	node->keys[level] = 0;
	return node;
}

//查找插入位置
int findIndex(Node* node, int data) {
	int index;
	for (index = 1; index <= node->keyNum; index++){
		if (data < node->keys[index])
			break;
	}
	return index; 
}

//查找插入的叶子节点
Node* findLeafNode(Node* node, int data) {
	if (node->childNum == 0){
		return node;
	}
	else {
		int index = findIndex(node, data);
		return  findLeafNode(node->children[index - 1], data);
	}
}

void addData(Node* node, int data, Node** T) {
	int index = findIndex(node, data);
	for (int i = node->keyNum; i >= index; i--){
		node->keys[i + 1] = node->keys[i];
	}
	node->keys[index] = data;
	node->keyNum++;
	//判断是否需要分裂
	if (node->keyNum == node->level){
		int mid = node->level / 2 + node->level % 2;  //寻找中间的节点
		Node* lchild = initNode(node->level);
		Node* rchild = initNode(node->level);
		for (int i = 1; i < mid; i++)
			addData(lchild, node->keys[i], T);
		for (int i = mid + 1; i <= node->keyNum; i++)
			addData(rchild, node->keys[i], T);
		//左孩子分配
		for (int i = 0; i < mid; i++){
			lchild->children[i] = node->children[i];
			if (node->children[i] != nullptr){
				node->children[i]->parent = lchild;
			    lchild->childNum++;
			}
		}
		//右孩子分配
		int index = 0;
		for (int i = mid; i <= node->childNum; i++){
			rchild->children[index++] = node->children[i];
			if (node->children[i] != nullptr) {
				node->children[i]->parent = rchild;
				rchild->childNum++;
			}
		}
		//父节点
		if (node->parent == nullptr){
			Node* newParent = initNode(node->level);
			addData(newParent, node->keys[mid], T);
			newParent->children[0] = lchild;
			newParent->children[1] = rchild;
			newParent->childNum = 2;
			lchild->parent = newParent;
			rchild->parent = newParent;
			*T = newParent;
		}
		else{
			int index = findIndex(node->parent, node->keys[mid]);
			lchild->parent = node->parent;
			rchild->parent = node->parent;
			node->parent->children[index - 1] = lchild;
			if (node->parent->children[index] != nullptr){
				for (int i = node->parent->childNum - 1; i >= index; i--)
					node->parent->children[i + 1] = node->parent->children[i];
			}
			node->parent->children[index] = rchild;
			node->parent->childNum++;
			addData(node->parent, node->keys[mid], T);
		}
	}
}

//插入
void insertNode(Node** T, int data) {
	//T为根节点指针的指针
	Node* node = findLeafNode(*T, data);
	addData(node, data, T);
}

void printTrree(Node* T) {
	if (T != nullptr){
		for (int i = 1; i <= T->keyNum; i++)
			std::cout << T->keys[i] << " ";
		std::cout << std::endl;
		for (int i = 0; i < T->childNum; i++){
			printTrree(T->children[i]);
		}
	}
}

int main() {
	Node* T = initNode(5);
	insertNode(&T, 1);
	insertNode(&T, 2);
	insertNode(&T, 6);
	insertNode(&T, 7);
	insertNode(&T, 11);
	insertNode(&T, 4);
	insertNode(&T, 8);
	insertNode(&T, 13);
	insertNode(&T, 10);
	insertNode(&T, 5);
	insertNode(&T, 17);
	insertNode(&T, 9);
	insertNode(&T, 16);
	insertNode(&T, 20);
	insertNode(&T, 3);
	insertNode(&T, 12);
	insertNode(&T, 14);
	insertNode(&T, 18);
	insertNode(&T, 19);
	insertNode(&T, 15);
	printTrree(T);
	return 0;
}