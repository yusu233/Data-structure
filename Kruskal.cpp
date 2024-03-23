#include<iostream>
using namespace std;

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

struct Graph{
	int arc[MAXVEX][MAXVEX];
	int VertexNum, EdgeNum;
};

struct Edge{
	int begin, end, weight;
};  //边集数组

void CreateGraph(Graph* G)
{
	int i, j;

	G->EdgeNum = 15;
	G->VertexNum = 9;

	for (i = 0; i < G->VertexNum; i++)
	{
		for (j = 0; j < G->VertexNum; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	for (i = 0; i < G->VertexNum; i++)
	{
		for (j = i; j < G->VertexNum; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

void Sort(Graph G, Edge edge[]) {
	for (int i = 0; i < G.EdgeNum; i++){
		for (int j = i + 1; j < G.EdgeNum; j++) {
			if (edge[i].weight > edge[j].weight){
				Edge temp = edge[i];
				edge[i] = edge[j];
				edge[j] = temp;
			}
		}
	}
}  //可以进行优化，使用最小堆降低排序的时间复杂度

//邻接矩阵转换为边集数组
void Transfer(Graph G, Edge* edge) {
	int k = 0;
	for (int i = 0; i < G.VertexNum; i++){
		for (int j = i + 1; j < G.VertexNum; j++) {
			if (G.arc[i][j] < INFINITY){
				edge[k].begin = i;
				edge[k].end = j;
				edge[k].weight = G.arc[i][j];
				k++;
			}
		}
	}
}

//并查集查找
int Find(int* parent, int f) {
	while (parent[f] > 0){
		f = parent[f];
	}
	return f;
}

void MinSpanTree_Kruskal(Graph G) {
	int parent[MAXVEX];
	Edge edge[MAXEDGE];
	Transfer(G, edge);
	Sort(G, edge);
	for (int i = 0; i < G.VertexNum; i++){
		parent[i] = 0;
	}

	for (int j = 0; j < G.EdgeNum; j++){
		int n = Find(parent, edge[j].begin);
		int m = Find(parent, edge[j].end);
		if (n != m){
			parent[n] = m;
			cout << "(" << edge[j].begin << ", " << edge[j].end << ") " << edge[j].weight << endl;
		}
	}
}

int main(void)
{
	Graph G;
	CreateGraph(&G);
	MinSpanTree_Kruskal(G);
	return 0;
}