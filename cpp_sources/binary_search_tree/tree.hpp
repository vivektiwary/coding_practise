#ifndef TREE_H
#define TREE_H

#include "node.hpp"
class Tree {
  Node* root;
  Node* _insert(Node*, Node*);
  Node* _delete(Node*, int);
  void _print_tree_inorder(Node*) const;
  Node* find_minimum(Node*);
 public:
  Tree(int);
  void insert(int);
  void delete_node(int);
  void print_tree_inorder();
};
#endif /* ifndef TREE_H */
