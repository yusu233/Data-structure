#include<iostream>
using namespace std;

#define Max 5

//结点表结构
struct Verteexlist{
	int vertex;
	Adjlist* firstedge;
};

//边表结构
struct Adjlist{
	int adjvex;
	int weight;
	Adjlist* next;
};

struct Graph{
	Verteexlist array[Max];
	int vertexNum, EdgeNum;
};

void CrateGraph(Graph* G) {
	int i, j, k;
	cout << "输入顶点数和边数: " << endl;
	cin >> G->vertexNum >> G->EdgeNum;
	for (i = 0; i < G->vertexNum; i++){
		cout << "输入第" << i + 1 << "个顶点: ";
		cin >> G->array[i].vertex;
		G->array[i].firstedge = nullptr;
	}

	Adjlist* e;
	int start, end, weight;
	for (k = 0; k < G->EdgeNum; k++){
		cout << "输入第" << k + 1 << "条边起始点、终止点和权值：";
		cin >> start >> end >> weight;
		e = new Adjlist;
		e->adjvex = end;
		e->weight = weight;
		e->next = G->array[start].firstedge;
		G->array[start].firstedge = e;
	}
}