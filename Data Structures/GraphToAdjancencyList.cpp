#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<iterator>
using namespace std;

class Graph{
    int v;
    list<int> *adj;
    map<int,list<int>> myMap;
    map<int,list<int>>::iterator it;
public:
    Graph();
    Graph(int);
    void addEdge(int,int);
    void addEdgeUsingMap(int,int);
    void printAdjList();
    void printAdjListFromMap();
    //void BFS(int);
};

Graph::Graph(){
}

Graph::Graph(int v){
    this->v = v;
    adj = new list<int>[v];
}

/** The following implementation has a problem
    Let's say the first vertex is 1 and 2nd is 100, then you need to create 101 nodes to accomodate the 2nd node and rest of the nodes are unused.
    How do you solve this problem?
**/
void Graph::addEdge(int souVer, int DestVer){
    adj[souVer].push_back(DestVer);
}

void Graph::addEdgeUsingMap(int souVer, int DestVer){
    //Check if map already has this value

    it = myMap.find(souVer);
     //if present, push the element
    if(it!= myMap.end()){
        myMap[souVer].push_back(DestVer);
    }

//if not, insert a new entry - find() returns an iterator to that key value else it returns to the iterator to the end of the map
    else{
        list<int> l;
        l.push_back(DestVer);
        myMap[souVer] = l;
    }
}

void Graph::printAdjListFromMap(){
    list<int>::iterator listIt;
    list<int> tempList;
    for(it=myMap.begin();it!=myMap.end();it++){
        cout<<it->first;
        tempList = myMap[it->first];
        for(listIt=tempList.begin();listIt!=tempList.end();++listIt){
            cout << "-->"<<*listIt;
        }
        cout<<endl;
    }
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

    cout<<"Graph with Adjacency LinkedList"<<endl;
    g.printAdjList();


    cout<<"Graph with Map"<<endl;
    Graph gMap;
    gMap.addEdgeUsingMap(1,2);
    gMap.addEdgeUsingMap(1,3);
    gMap.addEdgeUsingMap(2,1);
    gMap.addEdgeUsingMap(2,2);
    gMap.addEdgeUsingMap(2,3);
    gMap.addEdgeUsingMap(4,1);
    gMap.addEdgeUsingMap(4,2);
    gMap.addEdgeUsingMap(5,1);
    gMap.printAdjListFromMap();

  
    return 0;
}
