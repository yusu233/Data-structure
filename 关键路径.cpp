#include<iostream>
using namespace std;

#define MAXVEX 30
#define MAXEDGE 30
#define INFINITY 65535

int* etv, * ltv;
int* stack2;
int top2 = -1;

//图
struct Graph {
	int vertex[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int VertexNum, EdgeNum;
};

//边表节点
struct EdgeNode {
	int index, weight;
	EdgeNode* next;
};

//顶点表节点
struct VertexNode {
	int vex, indegree;
	EdgeNode* firstedge;
};

//顶点数组
struct GraphAdjList {
	VertexNode adjlist[MAXVEX];
	int VertexNum, EdgeNum;
};

void CreateGraph(Graph* G)
{
	int i, j;
	G->EdgeNum = 13;
	G->VertexNum = 10;

	for (i = 0; i < G->VertexNum; i++)
	{
		G->vertex[i] = i;
	}

	for (i = 0; i < G->VertexNum; i++)
	{
		for (j = 0; j < G->VertexNum; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = INFINITY;
		}
	}

	G->arc[0][1] = 3;
	G->arc[0][2] = 4;
	G->arc[1][3] = 5;
	G->arc[1][4] = 6;
	G->arc[2][3] = 8;
	G->arc[2][5] = 7;
	G->arc[3][4] = 3;
	G->arc[4][6] = 9;
	G->arc[4][7] = 4;
	G->arc[5][7] = 6;
	G->arc[6][9] = 2;
	G->arc[7][8] = 5;
	G->arc[8][9] = 3;

}

//构建图的邻接表
void CreateALGraph(Graph G, GraphAdjList* GL) {
	GL->VertexNum = G.VertexNum;
	GL->EdgeNum = G.EdgeNum;
	for (int i = 0; i < GL->VertexNum; i++) {
		GL->adjlist[i].indegree = 0;
		GL->adjlist[i].vex = G.vertex[i];
		GL->adjlist[i].firstedge = nullptr;
	}

	for (int i = 0; i < GL->VertexNum; i++) {
		for (int j = 0; j < GL->VertexNum; j++) {
			if (G.arc[i][j] != 0 && G.arc[i][j] < INFINITY) {
				EdgeNode* temp = new EdgeNode;
				temp->index = j;
				temp->weight = G.arc[i][j];
				temp->next = GL->adjlist[i].firstedge;
				GL->adjlist[i].firstedge = temp;
				GL->adjlist[j].indegree++;
			}
		}
	}
}

bool TopologicalSort(GraphAdjList GL) {
	EdgeNode* e;
	int top = -1;
	int count = 0;
	int* stack = new int[GL.VertexNum];
	stack2 = new int[GL.VertexNum];
	for (int i = 0; i < GL.VertexNum; i++) {
		if (GL.adjlist[i].indegree == 0)
			stack[++top] = i;
	}
	//事件的最早发生时间
	etv = new int[GL.VertexNum];
	for (int i = 0; i < GL.VertexNum; i++)
		etv[i] = 0;

	while (top != -1) {
		int temp = stack[top--];
		cout << GL.adjlist[temp].vex << "->";
		count++;

		stack2[++top2] = temp;

		for (e = GL.adjlist[temp].firstedge; e; e = e->next) {
			int k = e->index;
			if (--GL.adjlist[k].indegree == 0)
				stack[++top] = k;

			if (etv[temp] + e->weight > etv[k])
				etv[k] = etv[temp] + e->weight;
		}
	}
	delete[] stack;
	if (count == GL.VertexNum) {
		return true;
	}
	return false;
}

void CriticalPath(GraphAdjList GL) {
	EdgeNode* e;
	int ete, lte;
	TopologicalSort(GL);
	cout << endl;
	//事件最晚发生时间
	ltv = new int[GL.VertexNum];
	for (int i = 0; i < GL.VertexNum; i++)
		ltv[i] = etv[GL.VertexNum - 1];
	while (top2 != -1){
		int temp = stack2[top2--];
		for  (e = GL.adjlist[temp].firstedge; e; e = e->next){
			int k = e->index;
			if (ltv[k] - e->weight < ltv[temp])
				ltv[temp] = ltv[k] - e->weight;
		}
	}

	//求活动最早开工时间和最晚开工时间
	for (int i = 0; i < GL.VertexNum; i++){
		for (e = GL.adjlist[i].firstedge; e; e = e->next) {
			int k = e->index;
			ete = etv[i];
			lte = ltv[k] - e->weight;
			if (ete == lte)
				cout << GL.adjlist[i].vex << "->" << GL.adjlist[k].vex << endl;
		}
	}
}


int main() {
	Graph G;
	GraphAdjList GL;
	CreateGraph(&G);
	CreateALGraph(G, &GL);
	//TopologicalSort(GL);
	CriticalPath(GL);
	return 0;
}