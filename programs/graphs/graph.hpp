#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <stdexcept>
#include <unordered_map>

template<typename T>
class Graph {
public:
    void addVertex(T vertex);
    void removeVertex(T vertex);
    bool hasVertex(T vertex);
    void addEdge(T source, T destination, int weight);
    void removeEdge(T source, T destination);
    bool hasEdge(T source, T destination);
    int getEdgeWeight(T source, T destination);
    std::list<T> getNeighbors(T vertex);
private:
    std::unordered_map<T, std::unordered_map<T, int>> adjacencyMap;
};

template<typename T>
void Graph<T>::addVertex(T vertex) {
  if(!adjacencyMap.contains(vertex)) {
    adjacencyMap[vertex] = std::unordered_map<T, int>();
  }
}

template<typename T>
void Graph<T>::removeVertex(T vertex) {
  // erase returns count of how many records were erased
  size_t count = adjacencyMap.erase(vertex);
  // if vertex removed, also check all other vertices and remove any edges to this vertex
  if(count > 0) {
    for(auto& [v, neighbors] : adjacencyMap) {
      neighbors.erase(vertex);
    }
  }
}

template<typename T>
bool Graph<T>::hasVertex(T vertex) {
  return adjacencyMap.contains(vertex);
}

template<typename T>
void Graph<T>::addEdge(T source, T destination, int weight) {
  if(adjacencyMap.contains(source) && adjacencyMap.contains(destination)) {
    //add or update the edge from source to destination with the given weight
    adjacencyMap[source][destination] = weight;
  }
}

template<typename T>
void Graph<T>::removeEdge(T source, T destination) {
  if(adjacencyMap.contains(source)) {
    adjacencyMap[source].erase(destination);
  }
}

template<typename T>
bool Graph<T>::hasEdge(T source, T destination) {
  if(adjacencyMap.contains(source)) {
    return adjacencyMap[source].contains(destination);
  }
  return false;
}

template<typename T>
int Graph<T>::getEdgeWeight(T source, T destination) {
  if(adjacencyMap.contains(source) && adjacencyMap[source].contains(destination)) {
    return adjacencyMap[source][destination];
  }
  throw std::logic_error("Edge does not exist");
}

template<typename T>
std::list<T> Graph<T>::getNeighbors(T vertex) {
  std::list<T> neighborsList;
  if(adjacencyMap.contains(vertex)) {
    for(const auto& [neighbor, weight] : adjacencyMap[vertex]) {
      neighborsList.push_back(neighbor);
    }
  }
  return neighborsList;
}

#endif // GRAPH_H