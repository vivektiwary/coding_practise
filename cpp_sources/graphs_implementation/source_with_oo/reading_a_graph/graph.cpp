#include "graph.hpp"
#include "edge_node.hpp"
#include <iostream>

Graph::Graph(int n_vertex, int n_edges, bool n_directed) {
  nvertices = n_vertex;
  nedges = n_edges;
  directed = n_directed;

  for (int i = 1; i < MAXV + 1; ++i) { edges[i] = NULL; }
  for (int i = 1; i < MAXV + 1; ++i) { degree[i] = 0; }
}

Graph::~Graph() {}

void Graph::read_graph() {
  int x, y;
  std::cout << "============= t " << nedges << std::endl;
  for (int i = 1; i <= nedges; ++i) {
    std::cout << "Enter the x and y value "; std::cin >> x >> y;
    std::cout << "the directed is: " << directed << std::endl;
    insert_edge(x, y, directed);
  }
}

void Graph::insert_edge(int x, int y, bool directed) {
  EdgeNode* edge = new EdgeNode();
  edge->set_y_node(y);
  if (edges[x] == NULL) {
    edge->set_next_node(NULL);
    edges[x] = edge;
  }
  else {
    edge->set_next_node((*edges[x]).get_next_node());
    (*edges[x]).set_next_node(edge);
  }

  degree[x] += 1;

  if (directed == false) {
    insert_edge(y, x, true);
  }
}

void Graph::display_graph() {
  for (int i = 1; i <= nvertices; i++) {
    EdgeNode* edge = edges[i];
    std::cout << "The edge from " << i << " is: ";
    while (edge != NULL) {
      std::cout << " " << (*edge).get_y_node();
      edge = (*edge).get_next_node();
    }
    std::cout << std::endl;
  }
}

int Graph::get_nedges() {
  return nedges;
}

void Graph::set_nedges(int edges) {
  nedges = edges;
}
