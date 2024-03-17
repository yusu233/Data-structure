#include<iostream>

using namespace std;
typedef int SElemtype;
#define MAXSIZE 20


struct DoubleStack
{
	SElemtype data[MAXSIZE];
	int top1, top2;
};

bool InitStack(DoubleStack* s) {
	s->data[MAXSIZE] = {};
	s->top1 = -1;
	s->top2 = MAXSIZE;
	return true;
}

bool StackEmpty(DoubleStack s) {
	if (s.top1 == -1 && s.top2 == MAXSIZE)
	{
		return true;
	}
	return false;
}

int StackLength(DoubleStack s) {
	return (s.top1 + MAXSIZE + 1 - s.top2);
}

bool Push(DoubleStack* s, SElemtype e, int stacknumber) {
	if (s->top1 + 1 == s->top2)
	{
		cout << "Õ»ÒÑÂú£¡" << endl;
		return false;
	}
	if (stacknumber == 1)
	{
		s->data[++s->top1] = e;
		return true;
	}
	else {
		s->data[--s->top2] = e;
		return true;
	}
}

bool Pop(DoubleStack* s, SElemtype* e, int stacknumber) {
	if (stacknumber == 1)
	{
		if (s->top1 == -1) {
			cout << "Õ»ÒÑ¿Õ£¡" << endl;
			return false;
		}
		*e = s->data[s->top1--];
		return true;
	}
	else {
		if (s->top2 == MAXSIZE)
		{
			cout << "Õ»ÒÑ¿Õ£¡" << endl;
			return false;
		}
		*e = s->data[s->top2++];
		return true;
	}
}

int main() {
	int j;
	DoubleStack s;
	int e;
	if (InitStack(&s))
	{
		for (j = 1; j <= 5; j++)
			Push(&s, j, 1);
		for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
			Push(&s, j, 2);
	}

	printf("µ±Ç°Õ»ÖÐÔªËØÓÐ£º%d \n", StackLength(s));

	Pop(&s, &e, 2);
	printf("µ¯³öµÄÕ»¶¥ÔªËØ e=%d\n", e);
	printf("Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n", StackEmpty(s));

	for (j = 6; j <= MAXSIZE - 2; j++)
		Push(&s, j, 1);

	printf("Õ»Âú·ñ£º%d(1:·ñ 0:Âú)\n", Push(&s, 100, 1));

	return 0;
}