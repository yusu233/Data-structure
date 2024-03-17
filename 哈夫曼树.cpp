#include<iostream>
using namespace std;

typedef int HElemType;
#define MinData INT_MIN

//定义哈夫曼树结点的结构
struct HTNode {
	HElemType data;
	int weight;
	HTNode* lchild;
	HTNode* rchild;
};


//创建用于构造哈夫曼树的最小堆
class Heap
{
public:
	Heap() : heap(nullptr) {}

	void create(int capacity) {
		heap = InitHeap(capacity);
	}

	void insert(HTNode* value) {
		Insert(heap, value);
	}

	void traverse() {
		Traverse(*heap);
	}

	HTNode* deleteheap() {
		return Delete(heap);
	}

	int Getsize() {
		return heap->size_;
	}

private:

	//定义堆结构
	struct HeapStruct {
		HTNode* Elements_;//存储堆的数组
		int size_;//堆当前的元素个数
		int Maxsize_;//堆的最大容量
	};

	//创建并初始化堆
	HeapStruct* InitHeap(int capacity) {
		HeapStruct* H = new HeapStruct;
		H->Elements_ = new HTNode[capacity + 1];
		H->size_ = 0;
		H->Maxsize_ = capacity;
		H->Elements_[0].weight = MinData;
		return H;
	}

	//判断堆是否已满
	bool HeapFull(HeapStruct H) {
		if (H.size_ == H.Maxsize_)
			return true;
		return false;
	}

	//判断堆是否为空
	bool HeapEmpty(HeapStruct H) {
		if (H.size_ == 0)
			return true;
		return false;
	}

	//最小堆的插入
	void Insert(HeapStruct* H, HTNode* value) {
		int index;
		if (HeapFull(*H))
			cout << "堆已满！" << endl;
		index = ++H->size_;
		for (; H->Elements_[index / 2].weight > value->weight && index > 1; index /= 2)
			H->Elements_[index] = H->Elements_[index / 2];
		H->Elements_[index] = *value;
	}

	//最小堆的删除
	HTNode* Delete(HeapStruct* H) {
		int parent, child;
		HTNode* root, *temp;
		if (HeapEmpty(*H)) {
			cout << "堆已为空！" << endl;
			return ;
		}
		*root = H->Elements_[1];
		*temp = H->Elements_[H->size_--];
		for (parent = 1; parent * 2 <= H->size_; parent = child) {
			child = 2 * parent;
			//找出左右结点的最小值
			if (child != H->size_ && H->Elements_[child].weight > H->Elements_[child + 1].weight)
				child++;
			if (temp->weight <= H->Elements_[child].weight)
				break;
			else
				H->Elements_[parent] = H->Elements_[child];
		}
		H->Elements_[parent] = *temp;
		return root;
	}

	//最小堆的遍历
	void Traverse(HeapStruct H) {
		for (int i = 0; i <= H.size_; i++)
			cout << H.Elements_[i].data << endl;
	}

	HeapStruct* heap;
};

//哈夫曼树构造函数
HTNode* Huffman(Heap* H) {
	int i;
	HTNode* T;
	for ( i = 1; i < H->Getsize(); i++){
		T = new HTNode;
		T->lchild = H->deleteheap();
		T->rchild = H->deleteheap();
		T->weight = T->lchild->weight + T->rchild->weight;
		H->insert(T);
	}
	T = H->deleteheap();
	return T;
}

int main() {
	HTNode* array[10];
	Heap* H;
	for (int i = 0; i < 9; i++){
		H->insert(array[i]);
	}
	Huffman(H);
	H->traverse();
	return 0;
}
