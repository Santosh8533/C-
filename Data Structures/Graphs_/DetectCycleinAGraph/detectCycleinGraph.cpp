/**
    Author: Santosh Tandrothu
    Date: 02/24/2019
**/

/**
    Run-time: O(V+E)
    Space: O(V)
**/

// A C++ Program to detect cycle in a graph
#include<iostream>
#include <list>


using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(); // returns true if there is a cycle in this graph
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

// This function is a variation of DFSUytil() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    //break
    if(recStack[v]==true)return true;

    //intialize
    visited[v] = true;
    recStack[v] = true;

    //visit neighbors
    for(auto it=adj[v].begin();it!=adj[v].end();it++){
        if(!visited[*it] && isCyclicUtil(*it,visited,recStack))
            return true;
        else if(recStack[*it])
            return true;
    }
    recStack[v] = false;
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    //Create visited and recStack array of bools
    bool* visited = new bool[V];
    bool* recStack = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
        recStack[i] = false;
    }
    //Iterate over all vertices to cover both connected and disconnected graphs
    for(int i=0;i<V;i++){
        if(isCyclicUtil(i,visited,recStack))
            return true;
    }
    return false;
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	//g.addEdge(2, 0);
	g.addEdge(2, 3);
	//g.addEdge(3, 3);

	if(g.isCyclic())
		cout << "Graph contains cycle"<<endl;
	else
		cout << "Graph doesn't contain cycle"<<endl;

	//cycle
    Graph g1(4);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(2, 0);
	g.addEdge(2, 3);


	if(g1.isCyclic())
		cout << "Graph G1 contains cycle"<<endl;
	else
		cout << "Graph G1 doesn't contain cycle"<<endl;

    //self loop
	Graph g2(1);
	g2.addEdge(0, 0);
	if(g2.isCyclic())
		cout << "Graph G2 contains cycle"<<endl;
	else
		cout << "Graph G2 doesn't contain cycle"<<endl;
	return 0;
}

