#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "edge_node.hpp"

class Graph {
 private:
  static const int MAXV = 1000;
  EdgeNode* edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;

  void display_graph();
  void insert_edge(int x, int y);

 public:
  Graph(int nvertices, int nedges, bool directed);
  void read_graph();
  virtual ~Graph();
};

#endif /* GRAPH_H */
