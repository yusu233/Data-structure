#include<iostream>
using namespace std;

typedef int HeapElemType;
#define MaxData INT_MAX;

//使用最大堆
class Heap
{
public:
	Heap() : heap(nullptr){}

	void create(int capacity) {
		heap = InitHeap(capacity);
	}

	void insert(HeapElemType value) {
		Insert(heap, value);
	}
	void traverse() {
		Traverse(*heap);
	}
	
	HeapElemType deleteheap() {
		return Delete(heap);
	}

private:
	//定义堆结构
	struct HeapStruct {
		HeapElemType* Elements_;//存储堆的数组
		int size_;//堆当前的元素个数
		int Maxsize_;//堆的最大容量
	};

	//创建并初始化堆
	HeapStruct* InitHeap(int capacity) {
		HeapStruct* H = new HeapStruct;
		H->Elements_ = new HeapElemType[capacity + 1];
		H->size_ = 0;
		H->Maxsize_ = capacity;
		H->Elements_[0] = MaxData;
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

	//最大堆的插入
	// 先假定插入的元素放在最后，然后向上走，找到合适的位置
	void Insert(HeapStruct* H, HeapElemType value) {
		int index;
		if (HeapFull(*H))
			cout << "堆已满！" << endl;
		index = ++H->size_;
		for (; H->Elements_[index / 2] < value && index > 1; index /= 2)
			H->Elements_[index] = H->Elements_[index / 2];
		H->Elements_[index] = value;
	}

	//最大堆的删除
	HeapElemType Delete(HeapStruct* H) {
		int parent, child;
		HeapElemType root, temp;
		if (HeapEmpty(*H)){
			cout << "堆已为空！" << endl;
			return -1;
		}
		root = H->Elements_[1];
		temp = H->Elements_[H->size_--];
		for (parent = 1; parent * 2 <= H->size_; parent = child){
			child = 2 * parent;
			//找出左右结点的最大值
			if (child != H->size_ && H->Elements_[child] < H->Elements_[child + 1])
				child++;
			if (temp >= H->Elements_[child])
				break;
			else
				H->Elements_[parent] = H->Elements_[child];
		}
		H->Elements_[parent] = temp;
		return root;
	}

	//最大堆的遍历
	void Traverse(HeapStruct H) {
		for (int i = 0; i <= H.size_; i++)
			cout << H.Elements_[i] << endl;
	}

	HeapStruct* heap;
};

int main() {
	Heap test;

	test.create(9);
	test.insert(90);
	test.insert(70);
	test.insert(80);
	test.insert(60);
	test.insert(100);
	test.traverse();

	test.deleteheap();
	test.traverse();
	return 0;
}