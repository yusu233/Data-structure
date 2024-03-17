#include<iostream>
using namespace std;

typedef int EdgeType;
#define Maxarc 4
#define INFINITY 65535

//创建图的存储结构（邻接矩阵）
struct GraphAdj
{
	EdgeType adj[Maxarc][Maxarc];
};

void CreateGraph(GraphAdj* G) {
	int i, j, count;
	int start, end, weight;
	 char x;

	//初始化邻接矩阵
	cout << "输入图的顶点数量：" << endl;
	cin >> count;
	for (i = 0; i < count; i++){
		for (j = 0; j < count; j++) {
			G->adj[i][j] = INFINITY;
		}
	}

	//构建无向图邻接矩阵
	cout << "输入边的起始顶点， 终止顶点， 权值(输入q终止)： " << endl;
	while (true)
	{
		cin >> x;
		if (x == 'q')
			break;
		start = atoi(&x);
		cin >> end >> weight;
		G->adj[start][end] = weight;
		G->adj[end][start] = G->adj[start][end];
		cout << "输入边的起始顶点， 终止顶点， 权值： " << endl;
	}
}

int main() {
	GraphAdj G;
	CreateGraph(&G);
	return 0;
}