#include<iostream>
using namespace std;

#define MAXSIZE 9

class Graph
{
public:
	//创建图
	void CreateGraph() {
		VertexNum_ = 9;
		EdgeNum_ = 15;
		for (int i = 0; i < VertexNum_; i++){
			AdjList_[i].vertex = char(int('A') + i);
		}
		for (int j = 0; j < VertexNum_; j++){
			AdjList_[j].firstedge = nullptr;
		}

		EdgeNode* temp0 = new EdgeNode(5, nullptr);
		AdjList_[0].firstedge = new EdgeNode(1, temp0);

		EdgeNode* temp1 = new EdgeNode(8, nullptr);
		AdjList_[1].firstedge = new EdgeNode(2, nullptr);
		EdgeNode* temp2 = new EdgeNode(6, temp1);
		AdjList_[1].firstedge->next = temp2;

		EdgeNode* temp3 = new EdgeNode(8, nullptr);
		AdjList_[2].firstedge = new EdgeNode(3, temp3);

		EdgeNode* temp4 = new EdgeNode(8, nullptr);
		AdjList_[3].firstedge = new EdgeNode(4, nullptr);
		EdgeNode* temp5 = new EdgeNode(7, temp4);
		EdgeNode* temp6 = new EdgeNode(6, temp5);
		AdjList_[3].firstedge->next = temp6;

		EdgeNode* temp7 = new EdgeNode(7, nullptr);
		AdjList_[4].firstedge = new EdgeNode(5, temp7);

		AdjList_[5].firstedge = new EdgeNode(6, nullptr);

		AdjList_[6].firstedge = new EdgeNode(7, nullptr);

		for (int i = 0; i < MAXSIZE; i++){
			visited_[i] = false;
		}
	}


	//深度优先遍历递归函数
	void DFS(int i) {
		visited_[i] = true;

		/*cout << vertex_[i] << "->";
		for (int j = 0; j < MAXSIZE; j++){
			if (arc_[i][j] == 1 && visited_[j] == false)
				DFS(j);
		}*/

		cout << AdjList_[i].vertex << "->";
		EdgeNode* p;
		p = AdjList_[i].firstedge;
		while (p){
			if (visited_[p->index] == false)
				DFS(p->index);
			p = p->next;
		}
	}

	//邻接矩阵的深度优先遍历操作
	void DFETraverse() {
		for (int i = 0; i < VertexNum_; i++) {
			if (visited_[i] == false)
				DFS(i);
		}

	}

private:
	bool visited_[MAXSIZE];
	int VertexNum_, EdgeNum_;

	//邻接矩阵存储
	char vertex_[MAXSIZE];
	int arc_[MAXSIZE][MAXSIZE];


	//邻接表存储
	struct EdgeNode{
		int index;//存储邻接点在数组中的下标
		EdgeNode* next;

		EdgeNode(int x, EdgeNode* p): index(x), next(p){}
	};
	struct VertexNode{
		char vertex;
		EdgeNode* firstedge;
	};
	VertexNode AdjList_[MAXSIZE];
};


int main() {
	Graph G;
	G.CreateGraph();
	G.DFETraverse();
	cout << "end" << endl;
	return 0;
}