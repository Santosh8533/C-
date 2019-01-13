    /**
        Author: Santosh Tandrothu
        Date: 01/12/2018
        Problem: Given an undirected graph with maximum degree D and D+1 colors,
        color the graph legally. (Legal: No two adjacent nodes should have same color)
    **/

    /***
        Time Complexity = O(N+M)
            *Check adjacent nodes colors to find legal color
             - for all nodes = O(M) -> M = Total no of edges in graph
            *Fill each node with color = O(N)

        Space Complexity = O(D) (to save colors)
    **/

https://github.com/SantoshKumarTandrothu/Cplusplus

#include<iostream>
#include<unordered_set>
#include<vector>
#include<sstream>

using namespace std;

class GraphNode{

    private:
    string label_;
    string color_;
    unordered_set<GraphNode*> neighbors_;

    public:

    //constructor
    GraphNode(const string& label):
    label_(label),
    color_(),
    neighbors_()
    {
    }

    //Get the label of the node
    const string& getLabel() const{
        return label_;
    }

    //Get the neighbors of the node
    const unordered_set<GraphNode*> getNeighbors() const{
        return neighbors_;
    }

    //Add a neighbor node
    void addNeighbor(GraphNode& neighbor){
        //neighbors_ are pointers which point to the address of adjacent nodes to the current node
        neighbors_.insert(&neighbor);
    }

    //Check if current node has any color
    bool hasColor() const{
        return !color_.empty();
    }

    //Get the color
    const string& getColor() const{
        if(hasColor()){
            return color_;
        }
        else{
            throw logic_error("GraphNode is not marked with color");
        }
    }

    //Set the color
    void setColor(const string& color){
        color_= color;
    }

};


void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors){

    for(auto node:graph){

        const auto& neighbors = node->getNeighbors();
        if(neighbors.find(node)!=neighbors.end()){
            ostringstream errorMessage;
            errorMessage << "Legal coloring not possible for node with loop:"<<node->getLabel();
            throw invalid_argument(errorMessage.str());
        }

        unordered_set<string> illegalColors;
        for(const auto neighbor:node->getNeighbors()){
            if(neighbor->hasColor()){
                illegalColors.insert(neighbor->getColor());
            }
        }

        for(const auto& color:colors){
            if(illegalColors.find(color) ==  illegalColors.end()){
                node->setColor(color);
                break;
            }
        }

    }
}

void displayColors(const vector<GraphNode*>& graph){
    for(auto node:graph){
        cout<<node->getLabel()<<":"<<node->getColor()<<endl;
    }
}

int main(){
    GraphNode a("a");
    GraphNode b("b");
    GraphNode c("c");

    a.addNeighbor(b);
    b.addNeighbor(a);
    b.addNeighbor(c);
    c.addNeighbor(b);

    vector<GraphNode*> graph {&a,&b, &c};
    vector<string> colors = {"white","black"};
    colorGraph(graph,colors);
    displayColors(graph);

    return 0;
}
