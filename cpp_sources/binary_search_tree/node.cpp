#include "node.hpp"

Node::Node(int value) {
  data = value;
  left = right = nullptr;
}

int Node::value() {
  return data;
}

void Node::set_value(int value) {
  data = value;
}
