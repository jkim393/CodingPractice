//Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
private:	
	int V;
	vector<int> * adj;
public:
	Graph(int v){
		this->V = v;
		this->adj = new vector<int>[V]; // create an array of vectors where the array is size V
	}

	void addEdge(int u, int v){ //directed graph; u->v
		adj[u].push_back(v);
	}

	bool isRoute(int x, int y){
		std::vector<bool> visited(V);
		queue<int> q;
		q.push(x);

		while(!q.empty()){
			int current = q.front();
			if (current == y){
				return true;
			}
			visited[current] = true;
			q.pop();

			//enqueue all neighbors of current
			int neighbor_size = this->adj[current].size();
			for(int i=0;i<neighbor_size;i++){
				if( ! visited[ adj[current][i] ] ) { //if the neighboring vertex hasn't been visited
					q.push(adj[current][i]); // enqueue that vertex
				}
			}

		}

	}

};

int main(){
	Graph g(6);

	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	if(g.isRoute(5,4)) //false
		cout << "true\n";
	else
		cout << "false\n";


	if(g.isRoute(5,1)) //true
		cout << "true\n";
	else
		cout << "false\n";

	return 0;
}