// A C++ program to print topological sorting of a graph
// using indegrees.
#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int V;    // No. of vertices'

    // Pointer to an array containing adjacency listsList
    list<int> *adj;

public:
    Graph(int V);   // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void Graph::topologicalSort(){
    //declare a vector to store vertex and indegree
    vector<int> inDegree(V,0);
    vector<int> topOrder;
    for(int i=0;i<V;i++){
        for(auto it=adj[i].begin();it!=adj[i].end();it++){
            inDegree[*it]++;
        }
    }

    //create a queue and enquee all vertices with zero degree
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){q.push(i);}
    }

    //check each element in queue - visit it's neighbors and reduce their indegree by 1
    //if indegree becomes zero add them to queue
    int count_=0;
    while(!q.empty()){
        int ver = q.front();
        q.pop();
        topOrder.push_back(ver);

        for(auto it=adj[ver].begin();it!=adj[ver].end();it++){
            inDegree[*it]--;
            if(inDegree[*it]==0){q.push(*it);}
        }
        count_++;
    }
    if(count_!=V){
        cout<<"Cycle exists"<<endl;
        topOrder.erase();
        return topOrder;
    }
    return topOrder;
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

    cout << "Following is a Topological Sort of\n";
    g.topologicalSort();

    return 0;
}
