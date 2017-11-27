#include "./edge_node.hpp"

// Initializing all edge with 0 weight
EdgeNode::EdgeNode() : weight(0) {}

EdgeNode::~EdgeNode() {}

EdgeNode* EdgeNode::get_next_node() const {
  return next;
}

void EdgeNode::set_next_node(EdgeNode* edge) {
  next = edge;
}

int EdgeNode::get_y_node() const {
  return y;
}

void EdgeNode::set_y_node(int y_val) {
  y = y_val;
}
