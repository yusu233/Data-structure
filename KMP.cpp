#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef char String[MAXSIZE];

//字符串赋值操作
void StrAssign(String T, const char* chars) {
	int length = strlen(chars);
	if (length > MAXSIZE){
		return;
	}
	else {
		T[0] = length;
		for (int i = 1; i <= T[0]; i++){
			T[i] = chars[i - 1];
		}
	}
}

//字符串清零
void StrClear(String T) {
	T[0] = 0;
}

//打印字符串
void StrPrint(String T) {
	for (int i = 1; i <= T[0]; i++){
		cout << T[i] << endl;
	}
}

//打印next数组
void NextPrint(int* T, int len) {
	for (int i = 1; i <= len; i++) {
		cout << T[i] << endl;
	}
}

//计算字符串的长度
int StrLen(String T) {
	return T[0];
}

//KMP字符串模式匹配算法(Next)
void GetNext(String T, int* next) {
	int i = 1, k = 0, j;
	next[0] = -1;
	next[1] = 0;
	while (i < T[0]){
		if (k == 0 || T[i] == T[k]) {
			i++;
			k++;
			next[i] = k;
		}
		else{
			k = next[k];
		}
	}
}

int KMP(String S, String T, int pos) {
	int i = pos, j = 1;
	int next[MAXSIZE];
	GetNext(T, next);
	while (i <= S[0] && j <= T[0]){
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return -1;
}

//KMP字符串模式匹配算法(Nextval)
void GetNextval(String T, int* nextval) {
	int i = 1, k = 0, j;
	nextval[0] = -1;
	nextval[1] = 0;
	while (i < T[0]) {
		if (k == 0 || T[i] == T[k]) {
			i++;
			k++;
			if (T[i] == T[k])
				nextval[i] = nextval[k];
			else
				nextval[i] = k;
		}
		else {
			k = nextval[k];
		}
	}
}

int KMP1(String S, String T, int pos) {
	int i = pos, j = 1;
	int nextval[MAXSIZE];
	GetNextval(T, nextval);
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			j = nextval[j];
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return -1;
}

int main()
{
	int i, * p;
	String s1, s2;  //s1为子串，s2为主串

	StrAssign(s1, "abcdex");
	printf("子串为: \n");
	StrPrint(s1);
	i = StrLen(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	GetNext(s1, p);
	printf("Next为: \n");
	NextPrint(p, i);
	printf("\n");

	StrAssign(s1, "abcabx");
	printf("子串为: \n");
	StrPrint(s1);
	i = StrLen(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	GetNext(s1, p);
	printf("Next为: \n");
	NextPrint(p, i);
	printf("\n");

	StrAssign(s1, "ababaaaba");
	printf("子串为: \n");
	StrPrint(s1);
	i = StrLen(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	GetNext(s1, p);
	printf("Next为: \n");
	NextPrint(p, i);
	printf("\n");

	StrAssign(s1, "aaaaaaaab");
	printf("子串为: \n");
	StrPrint(s1);
	i = StrLen(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	GetNext(s1, p);
	printf("Next为: \n");
	NextPrint(p, i);
	printf("\n");

	StrAssign(s1, "ababaaaba");
	printf("子串为: \n");
	StrPrint(s1);
	i = StrLen(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	GetNext(s1, p);
	printf("Next为: \n");
	NextPrint(p, i);
	GetNextval(s1, p);
	printf("NextVal为: ");
	NextPrint(p, i);
	printf("\n");

	StrAssign(s1, "aaaaaaaab");
	printf("子串为: \n");
	StrPrint(s1);
	i = StrLen(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	GetNext(s1, p);
	printf("Next为: \n");
	NextPrint(p, i);
	GetNextval(s1, p);
	printf("NextVal为: ");
	NextPrint(p, i);

	printf("\n");

	StrAssign(s1, "00000000000000000000000000000000000000000000000001");
	printf("主串为: \n");
	StrPrint(s1);
	StrAssign(s2, "0000000001");
	printf("子串为: \n");
	StrPrint(s2);
	printf("\n");
	printf("主串和子串在第%d个字符处首次匹配（KMP算法） \n", KMP(s1, s2, 1));
	printf("主串和子串在第%d个字符处首次匹配（KMP改良算法） \n", KMP1(s1, s2, 1));

	return 0;
}