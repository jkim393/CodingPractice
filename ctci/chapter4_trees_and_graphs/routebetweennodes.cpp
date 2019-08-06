//Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//adjacency list implementation

// class Graph
// {
// public:
// 	int V;	// number of vertices
// 	vector<int> *adj;  //adjacency list 

// 	Graph(int V);
// 	void addEdge(int x, int y);
// 	bool isRoute(int x, int y);
// };

// // Constructor
// Graph::Graph(int V)
// {
// 	this->V=V;
// 	this->adj = new vector<int>[V];
// }

// // add a directed edge from x to y
// void Graph::addEdge(int x, int y){
// 	adj[x].push_back(y);
// }

void addEdge(vector<int> adj, int u, int v){ //u points to v
	adj[u].push_back(v);
}

bool isRoute(std::vector<int> adj, int x, int y){ //simple BFS
	vector<bool> visited(6, false); //set all of them to false
	queue<int> q; //nearest neighbor of the current node

	q.push(x); //original node x

	while(!q.empty()){ // while q is not empty
		int current = q.front();
		if(current == y){
			return true;
		}
		q.pop();
		visited[current] = true;
		int neighbor_size = adj[current].size();
		for (int i=0;i<neighbor_size;i++){
			if(!visited[adj[current][i]])
				q.push(adj[current][i]);
		}
	}
	return false;
}

int main(){

	int V = 6;
	vector<int> adj[V];
	addEdge(adj, 5, 2);
	addEdge(adj, 5, 0);
	addEdge(adj, 4, 0);
	addEdge(adj, 4, 1);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

	if(isRoute(adj, 5,4)) //false
		cout << "true\n";
	else
		cout << "false\n";


	if(isRoute(adj, 5,1)) //true
		cout << "true\n";
	else
		cout << "false\n";


	return 0;
}