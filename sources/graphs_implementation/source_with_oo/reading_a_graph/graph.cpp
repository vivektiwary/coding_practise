"Copyright 2017 Vivek Kumar"
#include "graph.hpp"

Graph::Graph(int nvertices, int nedges, bool directed) {
  nvertices = nvertices;
  nedges = nedges;
  directed = directed;

  for (int i = 0; i < MAXV + 1; ++i) { edges[i] = NULL; }
  for (int i = 0; i < MAXV + 1; ++i) { degree[i] = 0; }
}

Graph::read_graph() {
  int x, y;
  for (int i = 0; i < nedges; ++i) {
    cout << "Enter the x and y value"; cin >> x >> y;
    insert_edge(x, y);
  }
}

Graph::insert_edge(int x, int y) {
  EdgeNode* edge = new EdgeNode();
  edge->setYNode(y);
  edge->setNextNode(NULL);

  edges[x]
}
