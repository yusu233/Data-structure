#include<iostream>
using namespace std;

#define MAXVEX 14
#define MAXEDGE 20

//图
struct Graph{
	int vertex[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int VertexNum, EdgeNum;
};

//边表节点
struct EdgeNode{
	int index;
	EdgeNode* next;
};

//顶点表节点
struct VertexNode{
	int vex, indegree;
	EdgeNode* firstedge;
};

//顶点数组
struct GraphAdjList{
	VertexNode adjlist[MAXVEX];
	int VertexNum, EdgeNum;
};

void CreateGraph(Graph* G)
{
	int i, j;
	G->EdgeNum = MAXEDGE;
	G->VertexNum = MAXVEX;

	for (i = 0; i < G->VertexNum; i++)
	{
		G->vertex[i] = i;
	}

	for (i = 0; i < G->VertexNum; i++)
	{
		for (j = 0; j < G->VertexNum; j++)
		{
			G->arc[i][j] = 0;
		}
	}

	G->arc[0][4] = 1;
	G->arc[0][5] = 1;
	G->arc[0][11] = 1;
	G->arc[1][2] = 1;
	G->arc[1][4] = 1;
	G->arc[1][8] = 1;
	G->arc[2][5] = 1;
	G->arc[2][6] = 1;
	G->arc[2][9] = 1;
	G->arc[3][2] = 1;
	G->arc[3][13] = 1;
	G->arc[4][7] = 1;
	G->arc[5][8] = 1;
	G->arc[5][12] = 1;
	G->arc[6][5] = 1;
	G->arc[8][7] = 1;
	G->arc[9][10] = 1;
	G->arc[9][11] = 1;
	G->arc[10][13] = 1;
	G->arc[12][9] = 1;

}

//构建图的邻接表
void CreateALGraph(Graph G, GraphAdjList* GL) {
	GL->VertexNum = G.VertexNum;
	GL->EdgeNum = G.EdgeNum;
	for (int i = 0; i < GL->VertexNum; i++){
		GL->adjlist[i].indegree = 0;
		GL->adjlist[i].vex = G.vertex[i];
		GL->adjlist[i].firstedge = nullptr;
	}

	for (int i = 0; i < GL->VertexNum; i++){
		for (int j = 0; j < GL->VertexNum; j++) {
			if (G.arc[i][j] == 1){
				EdgeNode* temp = new EdgeNode;
				temp->index = j;
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
	for (int i = 0; i < GL.VertexNum; i++){
		if (GL.adjlist[i].indegree == 0)
			stack[++top] = i;
	}

	while (top != -1){
		int temp = stack[top--];
		cout << GL.adjlist[temp].vex << "->";
		count++;
		for  (e = GL.adjlist[temp].firstedge; e ; e = e->next){
			int k = e->index;
			if (--GL.adjlist[k].indegree == 0)
				stack[++top] = k;
		}
	}
	delete[] stack;
	if (count == GL.VertexNum){
		return true;
	}
	return false;
}

int main(){
	Graph G;
	GraphAdjList GL;
	int result;
	CreateGraph(&G);
	CreateALGraph(G, &GL);
	result = TopologicalSort(GL);
	printf("result:%d", result);

	return 0;
}