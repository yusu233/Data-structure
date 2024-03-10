#include<iostream>
using namespace std;

typedef int QelemType;

//定义链表结构体
struct LinkNode
{
	QelemType data;
	LinkNode* next;
	LinkNode(int x): data(x), next(nullptr){}
};

//定义链队列结构体
struct LinkQueue {
	LinkNode* front;
	LinkNode* rear;
};

//初始化链队列
bool InitQueue(LinkQueue* q) {
	q->rear = q->front = new LinkNode(0);
	return true;
}

//判断链队列是否为空
bool QueueEmpty(LinkQueue q) {
	if (q.front == q.rear)
	{
		return true;
	}
	return false;
}

//清空链队列
bool ClearQueue(LinkQueue* q) {
	q->rear = q->front;
	while (q->front->next)
	{
		LinkNode* temp = q->front->next;
		q->front->next = temp->next;
		delete temp;
	}
	return true;
}

//队列的长度
int QueueLength(LinkQueue q) {
	int count = 0;
	LinkNode* temp = q.front->next;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
//注意求长度的时候不要直接使用front指针遍历，这样会改变队列的结构！也不能使用temp->nexr = temp->next->next，这样也会改变队列结构！

//返回队列头元素
bool GetHead(LinkQueue q, QelemType* e) {
	if (q.front == q.rear)
	{
		return false;
	}
	*e = q.front->next->data;
	return true;
}

//在队尾增加元素
bool AddQueue(LinkQueue* q, QelemType e) {
	LinkNode* n = new LinkNode(e);
	q->rear->next = n;
	q->rear = n;
	return true;
}

//删除队头元素
bool DelQueue(LinkQueue* q, QelemType* e) {
	if (q->front == q->rear)
	{
		return false;
	}
	LinkNode* temp = q->front->next;
	*e = temp->data;
	q->front->next = temp->next;
	//防止误删除尾指针rear
	if (q->rear == temp)
	{
		q->rear = q->front;
	}
	delete temp;
	return true;
}

/*int main()
{
	QelemType d;
	LinkQueue q;
	if (InitQueue(&q))
		printf("成功地构造了一个空队列!\n");
	printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));
	printf("队列的长度为%d\n", QueueLength(q));
	AddQueue(&q, -5);
	AddQueue(&q, 5);
	AddQueue(&q, 10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));
	if (GetHead(q, &d))
		printf("队头元素是：%d\n", d);
	DelQueue(&q, &d);
	printf("删除了队头元素%d\n", d);
	if (GetHead(q, &d))
		printf("新的队头元素是：%d\n", d);
	ClearQueue(&q);
	printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
	return 0;
}*/