#include<iostream>

using namespace std;
#define MAXSIZE 20
typedef int QelemType;

//定义队列解结构
struct Queue {
	QelemType data[MAXSIZE];
	int front, rear;
};

//初始化队列
bool InitQueue(Queue* q) {
	q->front = 0;
	q->rear = 0;
	return true;
}

//判断队列是否为空
bool QueueEmpty(Queue q) {
	if (q.front == q.rear)
	{
		return true;
	}
	return false;
}

//求队列的大小
int QueueLength(Queue q) {
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

//队列的第一个值
bool GetHead(Queue q, QelemType* e) {
	if (q.front == q.rear)
	{
		cout << "队列为空！" << endl;
		return false;
	}
	*e = q.data[q.front];
	return true;
}

//在队尾增加元素
bool AddQueue(Queue* q, QelemType e) {
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		cout << "队列已满！" << endl;
		return false;
	}
	q->data[q->rear] = e;
	q->rear = (++q->rear) % MAXSIZE;
	return true;
}

//返回并删除队头的元素
bool DelQueue(Queue* q, QelemType* e) {
	if (q->front == q->rear)
	{
		return false;
	}
	*e = q->data[q->front];
	q->front = (++q->front) % MAXSIZE;
	return true;
}

/*int main()
{
	int i = 0, l;
	QelemType d;
	Queue Q;
	InitQueue(&Q);
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));

	printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ", MAXSIZE - 1);
	do
	{
		d = i + 100;
		if (d == -1)
			break;
		i++;
		AddQueue(&Q, d);
	} while (i < MAXSIZE - 1);

	printf("队列长度为: %d\n", QueueLength(Q));
	printf("现在队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
	printf("连续%d次由队头删除元素,队尾插入元素:\n", MAXSIZE);
	for (l = 1; l <= MAXSIZE; l++)
	{
		DelQueue(&Q, &d);
		printf("删除的元素是%d,插入的元素:%d \n", d, l + 1000);
		// scanf("%d",&d); 
		d = l + 1000;
		AddQueue(&Q, d);
	}
	l = QueueLength(Q);

	printf("共向队尾插入了%d个元素\n", i + MAXSIZE);
	if (l - 2 > 0)
		printf("现在由队头删除%d个元素:\n", l - 2);
	while (QueueLength(Q) > 2)
	{
		DelQueue(&Q, &d);
		printf("删除的元素值为%d\n", d);
	}

	bool j = GetHead(Q, &d);
	if (j)
		printf("现在队头元素为: %d\n", d);
	return 0;
}*/

