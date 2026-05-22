/**
 * @brief Performs a breadth-first search on the graph starting from the given vertex
 * @param graph The graph to search
 * @param vertex The starting vertex
 * @return A map of each vertex to its parent in the search tree
 */
unordered_map<string, string> bfs(const Graph<string>& graph,
                                  const string& vertex) {
  queue<string> searchQueue;
  searchQueue.push(vertex);

  unordered_set<string> known;
  known.insert(vertex);

  unordered_map<string, string> parentMap;

  while (!searchQueue.empty()) {
    string current = searchQueue.front();
    searchQueue.pop();

    for (const auto& neighbor : graph.getNeighbors(current)) {
      if (!known.contains(neighbor)) {
        known.insert(neighbor);
        parentMap[neighbor] = current;
        searchQueue.push(neighbor);
      }
    }
  }
  return parentMap;
}
