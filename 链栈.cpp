#include<iostream>
using namespace std;

typedef int SElemtype;
#define MAXSIZE 20

struct StackNode {
	SElemtype data;
	StackNode* next;
	StackNode(SElemtype x) : data(x), next(nullptr){}
};

struct LinkStack {
	StackNode* top;
	int count;
};

//创建空栈
bool InitStack(LinkStack* s) {
	s->top = new StackNode(0);
	s->top = nullptr;
	s->count = 0;
	return true;
}

//判断栈是否为空
bool StackEmpty(LinkStack s) {
	if (s.count == 0)
	{
		return true;
	}
	return false;
}

//计算栈的长度
int StackLength(LinkStack s) {
	return s.count;
}

//返回栈顶元素

bool GetTop(LinkStack s, SElemtype* e) {
	if (s.top == nullptr)
	{
		return false;
	}
	*e = s.top->data;
	return true;
}

//入栈
bool Push(LinkStack* s, SElemtype e) {
	StackNode* n = new StackNode(e);
	n->next = s->top;
	s->top = n;
	s->count++;
	return true;
}

//出栈
bool Pop(LinkStack* s, SElemtype* e) {
	if (StackEmpty(*s))
	{
		return false;
	}
	StackNode* n = s->top;
	*e = s->top->data;
	s->top = n->next;
	delete n;
	s->count--;
	return true;
}

int main()
{
	int j;
	LinkStack s;
	int e;
	if (InitStack(&s))
		for (j = 1; j <= 10; j++)
			Push(&s, j);
	Pop(&s, &e);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
	return 0;
}