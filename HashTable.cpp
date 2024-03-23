#include<iostream>

#define HASHSIZE 12

//定义哈希表结构
struct HashTable{
	int* elem;
	int count;
};

int m = 0;  //存储哈希表的长度

//初始化哈希表
void initHashTable(HashTable* H) {
	m = HASHSIZE;
	H->count = 0;
	H->elem = new int[m];
	for (int i = 0; i < m; i++){
		H->elem[i] = -1;
	}
}

//散列函数
int Hash(int key) {
	//除留取余法
	return key % m;
}

//插入
void insertHashTable(HashTable* H, int key) {
	if (H->count <= HASHSIZE){
		int addr = Hash(key);
	    while (H->elem[addr] != -1)
		    addr = (addr + 1) % m;
	    H->elem[addr] = key;
	    H->count++;
	}
	else
		std::cout << "Hashtable is full!" << std::endl;
	
}

//查询
bool searchHashTable(HashTable H, int key, int* address) {
	*address = Hash(key);
	while (H.elem[*address] != key){
		*address = (*address + 1) % m;
		if (H.elem[*address] == -1 || *address == Hash(key))
			return false;
	}
	return true;
}

int main()
{
	int arr[HASHSIZE] = { 12,67,56,16,25,37,22,29,15,47,48,34 };
	int i, p, key, result;
	HashTable H;

	key = 39;

	initHashTable(&H);
	for (i = 0; i < m; i++)
		insertHashTable(&H, arr[i]);

	result = searchHashTable(H, key, &p);
	if (result)
		printf("查找 %d 的地址为：%d \n", key, p);
	else
		printf("查找 %d 失败。\n", key);

	for (i = 0; i < m; i++)
	{
		key = arr[i];
		searchHashTable(H, key, &p);
		printf("查找 %d 的地址为：%d \n", key, p);
	}

	return 0;
}