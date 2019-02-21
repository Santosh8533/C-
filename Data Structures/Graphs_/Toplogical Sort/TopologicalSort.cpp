/**
Question the obvious: How DFS works in getting topological order? Because
                A
               / \
              B   C
             / \ / \
            D  E F G
1. B shall not be executed until A is executed.
2. D&E shall not be executed until B is executed.
3. Indirectly, D&E are dependent on A and B is directly dependent on A.
4. So, when starting at any node, all it's neighbors and neighbors's neighbors must
   be visited as we know this node stops the execution of all nodes below it.
**/

/**
    Date: 02/20/2019
    Author: Santosh Tandrothu
**/
/**
    Run-time: O(V+E)
    Space: O(V)
**/
// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

// Class to represent a graph
class Graph
{
	int V; // No. of vertices'

	// Pointer to an array containing adjacency listsList
	list<int> *adj;

	// A function used by topologicalSort

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of the complete graph
	vector<int> topologicalSort();
	void TopologicalSortUtil(int,stack<int>&,bool*);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}
void Graph::TopologicalSortUtil(int ver,stack<int> &nodes,bool* visited){

    visited[ver] = true;
    //Apply DFS on all the adjacent nodes of the vertex
    for(auto it=adj[ver].begin();it!=adj[ver].end();it++){
        if(!visited[*it]){
            TopologicalSortUtil(*it,nodes,visited);
        }
    }
    //push the vertex once all it's vertices or dependent nodes has been visited
    nodes.push(ver);
}

vector<int> Graph::topologicalSort(){
    stack<int> nodes;
    vector<int> res;

    bool *visited = new bool(V);
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    //for all nodes in the graph
    for(int i=0;i<V;i++){
        if(!visited[i])TopologicalSortUtil(i,nodes,visited);
    }

    while(!nodes.empty()){
        res.push_back(nodes.top());
        nodes.pop();
    }
    return res;
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given graph->"<<endl;
	vector<int> res = g.topologicalSort();
    for(int i:res){
        cout<<i<<"\t";
    }
	return 0;
}

