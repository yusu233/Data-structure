#include<iostream>
#include<stack>
using namespace std;

#define MAXSIZE 9
#define INFINITY 65535

class Graph
{
public:
	int VertexNum_, EdgeNum_;
	int arc_[MAXSIZE][MAXSIZE];
	char vertex_[MAXSIZE];
	//创建图
	void CreateGraph() {
		VertexNum_ = 9;
		EdgeNum_ = 32;

		//邻接矩阵
		vertex_[0] = '0';
		vertex_[1] = '1';
		vertex_[2] = '2';
		vertex_[3] = '3';
		vertex_[4] = '4';
		vertex_[5] = '5';
		vertex_[6] = '6';
		vertex_[7] = '7';
		vertex_[8] = '8';


		for (int i = 0; i < VertexNum_; i++){
			for (int j = 0; j < VertexNum_; j++){
				arc_[i][j] = INFINITY;
			}
		}

		for (int i = 0; i < VertexNum_; i++)
			arc_[i][i] = 0;

		arc_[0][2] = 5;
		arc_[0][1] = 1;

		arc_[1][0] = 1;
		arc_[1][2] = 3;
		arc_[1][3] = 7;
		arc_[1][4] = 5;

		arc_[2][0] = 5;
		arc_[2][1] = 3;
		arc_[2][4] = 1;
		arc_[2][5] = 7;

		arc_[3][1] = 7;
		arc_[3][4] = 2;
		arc_[3][6] = 3;

		arc_[4][1] = 5;
		arc_[4][2] = 1;
		arc_[4][3] = 2;
		arc_[4][5] = 3;
		arc_[4][6] = 6;
		arc_[4][7] = 9;

		arc_[5][2] = 7;
		arc_[5][4] = 3;
		arc_[5][7] = 5;

		arc_[6][3] = 3;
		arc_[6][4] = 6;
		arc_[6][7] = 2;
		arc_[6][8] = 7;

		arc_[7][4] = 9;
		arc_[7][5] = 7;
		arc_[7][6] = 2;
		arc_[7][8] = 4;

		arc_[8][6] = 7;
		arc_[8][7] = 4;
	}

};


void ShortestPath_Dijkstra(Graph G, int v0, int* path, int* distance) {
	int* final = new int[G.VertexNum_];

	//初始化结点
	for (int i = 0; i < G.VertexNum_; i++){
		path[i] = -1;//path数组存储最短路径中节点的前驱结点
		final[i] = 0;//存储结点是否已找到最短路径
		distance[i] = INFINITY;
	}

	distance[v0] = 0;//初始化出发点

	for (int i = 0; i < G.VertexNum_; i++){
		int min = INFINITY;
		int index = -1;

		//寻找最短的路径
		for (int j = 0; j < G.VertexNum_; j++){
			if (final[j] == 0 && distance[j] < min) {
				index = j;
				min = distance[j];
			}
		}
		
		final[index] = 1;//将V-S中距离v0最近的点加入S
		//更新S加入新节点后index节点邻接节点的距离
		for (int k = 0; k < G.VertexNum_; k++){
			if (final[k] == 0 && G.arc_[index][k] != INFINITY && (min + G.arc_[index][k] < distance[k])) {
				distance[k] = min + G.arc_[index][k];
				path[k] = index;
			}
		}
	}
}




int main() {
	Graph G;
	G.CreateGraph();
	int* path = new int[G.VertexNum_];
	int* distance = new int[G.VertexNum_];
	ShortestPath_Dijkstra(G, 0, path, distance);
	for (int i = 0; i < G.VertexNum_; i++){
		cout << "V[" << i << "] " << path[i] << endl;
	}
	return 0;
}