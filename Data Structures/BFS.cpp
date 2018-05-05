#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
    int v;
    list<int> *adj;
public:
    Graph(int);
    void addEdge(int,int);
    void printAdjList();
    void BFS(int);
};

Graph::Graph(int v){
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int souVer, int DestVer){
    adj[souVer].push_back(DestVer);
}

void Graph::printAdjList(){
    list<int>::iterator it;
    for(int i=0;i<v;i++){
            cout << i<<"-->";
        for(it=adj[i].begin();it!=adj[i].end();++it){
            cout << *it<<"-->";
        }
        cout <<endl;
    }
}
void Graph::BFS(int ver){

    //create an array to keep track of visited nodes
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }

    //Create a queue to save the vertices
    queue<int> que;

    visited[ver] = true;
    que.push(ver);

    list<int>::iterator it;

    while(!que.empty()){
        ver = que.front();
        cout<<ver<<endl;
        que.pop();

        for(it=adj[ver].begin();it!=adj[ver].end();++it){
            if(!visited[*it]){
                visited[*it] = true;
                que.push(*it);
            }
        }
    }
}
int main(){
    Graph g(7);

    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(2,4);
    g.addEdge(4,2);
    g.addEdge(2,5);
    g.addEdge(5,2);
    g.addEdge(3,5);
    g.addEdge(5,3);
    g.addEdge(4,5);
    g.addEdge(5,4);
    g.addEdge(4,6);
    g.addEdge(6,4);
    g.addEdge(5,6);
    g.addEdge(6,5);

    g.printAdjList();
    g.BFS(3);

    return 0;
}
