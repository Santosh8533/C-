    /**
        Author: Santosh Tandrothu
        Date: 01/13/2018
        Problem: Given a set of users in the form of a graph, find the shortest path
        to send a message between two users.
    **/

    /***
        Time Complexity = O(V+E)
        Space Complexity = O(V)
    **/


#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include<iostream>
#include<algorithm>

using namespace std;

  vector<string> reconstructPath(const unordered_map<string, string>& previousNodes,
                               const string& startNode, const string& endNode)
{
    vector<string> reversedShortestPath;

    // start from the end of the path and work backwards
    string currentNode = endNode;

    while (!currentNode.empty()) {
        reversedShortestPath.push_back(currentNode);
        currentNode = previousNodes.find(currentNode)->second;
    }

    // reverse our path to get the right order
    // by flipping it around, in place
    reverse(reversedShortestPath.begin(), reversedShortestPath.end());
    return reversedShortestPath;  // no longer reversed
}

vector<string> bfsGetPath(const unordered_map<string, vector<string>>& graph,
                           const string& startNode, const string& endNode)
{
    if (graph.count(startNode) == 0) {
        throw invalid_argument("Start node not in graph");
    }
    if (graph.count(endNode) == 0) {
        throw invalid_argument("End node not in graph");
    }

    deque<string> nodesToVisit;
    nodesToVisit.push_back(startNode);

    // keep track of how we got to each node
    // we'll use this to reconstruct the shortest path at the end
    // we'll ALSO use this to keep track of which nodes we've
    // already visited
    unordered_map<string, string> howWeReachedNodes;
    howWeReachedNodes.emplace(startNode, "");

    while (!nodesToVisit.empty()) {
        string currentNode = move(nodesToVisit.front());
        nodesToVisit.pop_front();

        // stop when we reach the end node
        if (currentNode == endNode) {
            return reconstructPath(howWeReachedNodes, startNode, endNode);
        }

        for (const auto& neighbor : graph.find(currentNode)->second) {
            if (howWeReachedNodes.count(neighbor) == 0) {
                nodesToVisit.push_back(neighbor);
                howWeReachedNodes.emplace(neighbor, currentNode);
            }
        }
    }

    // if we get here, then we never found the end node
    // so there's NO path from startNode to endNode
    return vector<string>();
}

int main(){

    unordered_map<string, vector<string>> graph{
        { "a", {"b", "c", "d"} },
        { "b", {"a","c","d"} },
        { "c", {"a", "e"} },
        { "d", {"a", "b"} },
        { "e", {"c"} },
        { "f", {"g"} },
        { "g", {"f"} }
    };
    vector<string> shortestPath = bfsGetPath(graph,"a","e");
    cout<<"Expected path: a->c->e"<<endl;
    cout<<"Actual path:";
    for(auto node:shortestPath){
        cout<<node<<"->";
    }
    cout<<endl;
}
