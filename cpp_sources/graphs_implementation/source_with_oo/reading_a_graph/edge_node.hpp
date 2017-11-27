#ifndef EDGE_NODE_H
#define EDGE_NODE_H

class EdgeNode {
 private:
  int weight;
  int y;
  EdgeNode* next;

 public:
  EdgeNode();
  virtual ~EdgeNode();
  EdgeNode* get_next_node() const;
  void set_next_node(EdgeNode*);
  int get_y_node() const;
  void set_y_node(int);
};

#endif /* EDGE_NODE_H */
