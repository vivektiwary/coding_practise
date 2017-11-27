#ifndef NODE_H
#define NODE_H

class Node {
  int data;
 public:
  Node(int);
  Node* left;
  Node* right;
  int value();
  void set_value(int);
};
#endif /* ifndef NODE_H */
