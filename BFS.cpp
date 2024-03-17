#include<iostream>
using namespace std;

#define MAXSIZE 9

class Queue{
public:
	//初始化队列
	void CreateQueue() {
		front = 0;
		rear = 0;
	}
	//判断队列是否为空
	bool QueueEmpty() {
		return (front == rear);
	}
	//队列元素个数
	int QueueLength() {
		return (rear - front + MAXSIZE) % MAXSIZE;
	}
	//在队尾插入元素
	void InsertQueue(int c) {
		if ((rear + 1) % MAXSIZE == front)
			cout << "队列已满！" << endl;
		else{
			Vertex[rear] = c;
			rear = (rear + 1) % MAXSIZE;
		}
	}
	//返回并删除队首元素
	int DeleteQueue() {
		if (rear == front) {
			cout << "队列已空！" << endl;
			return -1;
		}else{
			int temp = Vertex[front];
			front = (front + 1) % MAXSIZE;
			return temp;
		}
	}

private:
	int Vertex[MAXSIZE];
	int front, rear;
};

class Graph
{
public:
	//创建图
	void CreateGraph() {
		VertexNum_ = 9;
		EdgeNum_ = 15;
		
		//邻接矩阵
		/*vertex_[0] = 'A';
		vertex_[1] = 'B';
		vertex_[2] = 'C';
		vertex_[3] = 'D';
		vertex_[4] = 'E';
		vertex_[5] = 'F';
		vertex_[6] = 'G';
		vertex_[7] = 'H';
		vertex_[8] = 'I';


		for (int i = 0; i < VertexNum_; i++) // 初始化图
		{
			for (int j = 0; j < VertexNum_; j++)
			{
				arc_[i][j] = 0;
			}
		}

		arc_[0][1] = 1;
		arc_[0][5] = 1;

		arc_[1][2] = 1;
		arc_[1][8] = 1;
		arc_[1][6] = 1;

		arc_[2][3] = 1;
		arc_[2][8] = 1;

		arc_[3][4] = 1;
		arc_[3][7] = 1;
		arc_[3][6] = 1;
		arc_[3][8] = 1;

		arc_[4][5] = 1;
		arc_[4][7] = 1;

		arc_[5][6] = 1;

		arc_[6][7] = 1;*/

		//邻接表
		for (int i = 0; i < VertexNum_; i++) {
			AdjList_[i].vertex = char(int('A') + i);
		}
		for (int j = 0; j < VertexNum_; j++) {
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

		for (int i = 0; i < MAXSIZE; i++) {
			visited_[i] = false;
		}
	}


	//广度优先遍历递归函数
	void BFSTraverse() {
		Queue Q;
		Q.CreateQueue();
		for (int i = 0; i < VertexNum_; i++){
			if (visited_[i] == false) {
				visited_[i] = true;
				cout << AdjList_[i].vertex << "->";
				//cout << vertex_[i] << "->";
				Q.InsertQueue(i);
				while (!Q.QueueEmpty()){
					int k = Q.DeleteQueue();
					/*
					for (int j = 0; j < VertexNum_; j++){
						if (arc_[k][j] == 1 && visited_[j] == false) {
							Q.InsertQueue(j);
						    cout << vertex_[j] << "->";
							visited_[j] = true;
						}
						
					}*/
					EdgeNode* p = AdjList_[k].firstedge;
					while (p){
						if (!visited_[p->index]) {
							visited_[p->index] = true;
							cout << AdjList_[p->index].vertex << "->";
							Q.InsertQueue(p->index);
						}
						p = p->next;
					}
				}
			}
		}
	}

private:
	bool visited_[MAXSIZE];
	int VertexNum_, EdgeNum_;

	//邻接矩阵存储
	char vertex_[MAXSIZE];
	int arc_[MAXSIZE][MAXSIZE];    


	//邻接表存储
	struct EdgeNode {
		int index;//存储邻接点在数组中的下标
		EdgeNode* next;

		EdgeNode(int x, EdgeNode* p) : index(x), next(p) {}
	};
	struct VertexNode {
		char vertex;
		EdgeNode* firstedge;
	};
	VertexNode AdjList_[MAXSIZE];
};


int main() {
	Graph G;
	G.CreateGraph();
	G.BFSTraverse();
	cout << "end" << endl;
	return 0;
}