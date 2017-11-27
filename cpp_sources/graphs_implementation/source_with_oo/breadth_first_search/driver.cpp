#include "graph.hpp"

int main(void)
{
  Graph graph(6);
  graph.add_edge(0, 1, graph.directed);
  graph.add_edge(0, 4, graph.directed);
  graph.add_edge(0, 5, graph.directed);

  graph.add_edge(1, 4, graph.directed);
  graph.add_edge(1, 2, graph.directed);

  graph.add_edge(2, 3, graph.directed);

  graph.add_edge(3, 4, graph.directed);

  graph.BFS(0);
  graph.find_path(0, 0);
  return 0;
}
