#include<iostream>
using namespace std;

#include<iostream>

using namespace std;
typedef int SElemtype;
#define MAXSIZE 20


struct Stack
{
	SElemtype data[MAXSIZE];
	int top;
};

bool InitStack(Stack* s) {
	s->data[MAXSIZE] = {};
	s->top = -1;
	return true;
}

bool StackEmpty(Stack s) {
	if (s.top == -1)
	{
		return true;
	}
	return false;
}

int StackLength(Stack s) {
	return (s.top + 1);
}

bool Push(Stack* s, SElemtype e) {
	if (s->top == MAXSIZE)
	{
		cout << "栈已满！" << endl;
		return false;
	}
	s->data[++s->top] = e;
	return true;
}

bool Pop(Stack* s, SElemtype* e) {
	if (s->top == -1) {
		cout << "栈已空！" << endl;
		return false;
	}
	*e = s->data[s->top--];
	return true;
}

/*int main() {
	int j;
	Stack s;
	int e;
	if (InitStack(&s))
	{
		for (j = 1; j <= 5; j++)
			Push(&s, j);
	}

	printf("当前栈中元素有：%d \n", StackLength(s));

	Pop(&s, &e);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	return 0;
}*/