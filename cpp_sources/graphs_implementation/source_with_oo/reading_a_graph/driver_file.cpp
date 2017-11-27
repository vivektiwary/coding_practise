#include <iostream>
#include "graph.hpp"

int main(void)
{
  int vertices, edges;
  std::cout << "Enter the number of vertices "; std::cin >> vertices;
  std::cout << "Enter the number of edges "; std::cin >> edges;
  Graph g(vertices, edges, true);
  std::cout << "the edges are from driver " << g.get_nedges() << std::endl;
  g.read_graph();
  g.display_graph();
  return 0;
}
