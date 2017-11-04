"Copyright 2017 Vivek Kumar"
#include "./edge_node.hpp"

// Initializing all edge with 0 weight
EdgeNode::EdgeNode() : weight = 0 {}

EdgeNode& EdgeNode::getNextNode() const {
  return next;
}

void EdgeNode::setNextNode(EdgeNode& edge) {
  next = edge;
}

int EdgeNode::getYNode() const {
  return y;
}

void EdgeNode::setYNode(int y) {
  y = y;
}
