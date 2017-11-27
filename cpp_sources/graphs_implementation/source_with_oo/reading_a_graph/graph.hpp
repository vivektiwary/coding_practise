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

  void insert_edge(int x, int y, bool directed);

 public:
  Graph(int nvertices, int nedges, bool directed);
  void read_graph();
  void display_graph();
  int get_nedges();
  void set_nedges(int edges);
  virtual ~Graph();
};

#endif /* GRAPH_H */
