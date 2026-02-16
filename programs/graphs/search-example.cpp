#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

import Graph;

using namespace std;

void dfs(Graph<string>& graph, 
         string vertex,
         unordered_set<string>& visited,
         unordered_map<string, string>& parentMap) {

    if (visited.contains(vertex)) {
        return; // Already visited this vertex
    }
    visited.insert(vertex); // Mark this vertex as visited

    // Recurse for all neighbors of this vertex
    for (const auto& neighbor : graph.getNeighbors(vertex)) {
        parentMap[neighbor] = vertex;
        dfs(graph, neighbor, visited, parentMap);
    }
}

int main() {
    Graph<string> graph;

    graph.addVertex("MTH111");
    graph.addVertex("MTH112");
    graph.addVertex("CS160");
    graph.addVertex("CS161");
    graph.addVertex("CS162");
    graph.addVertex("CS205");

    graph.addEdge("CS161", "CS160");
    graph.addEdge("CS161", "MTH111");
    graph.addEdge("MTH112", "MTH111");
    graph.addEdge("CS162", "CS161");
    graph.addEdge("CS205", "CS161");

    // Find prerequisites for CS205
    unordered_set<string> visited;
    unordered_map<string, string> parentMap;
    dfs(graph, "CS205", visited, parentMap);
    cout << "Prerequisites for CS205:" << endl;
    for (const auto& prereq : parentMap) {
        cout << prereq.first << " is a prerequisite for " << prereq.second << endl;
    }
}