#include <iostream>
#include "tree.hpp"

Tree::Tree(int root_value) {
  root = new Node(root_value);
}

void Tree::insert(int node_value) {
  Node* new_node = new Node(node_value);
  _insert(root, new_node);
}

Node* Tree::_insert(Node* root_node, Node* new_node) {
  if (root_node == NULL) {
    return new_node;
  }
  if (new_node->value() < root_node->value()) {
    root_node->left = _insert(root_node->left, new_node);
  }
  else if (new_node->value() > root_node->value()) {
    root_node->right = _insert(root_node->right, new_node);
  }
  return root_node;
}

void Tree::delete_node(int node_value) {
  _delete(root, node_value);
}

Node* Tree::find_minimum(Node* node) {
  Node* min_node = NULL;
  while(node->left != NULL) {
    node = node->left;
    min_node = node;
  }
  return min_node;
}

Node* Tree::_delete(Node* root_node, int node_value) {
  if (root_node->value() == node_value) {
    if (root_node->left == NULL) {
      root_node = root_node->right;
    }
    else if (root_node->right == NULL) {
      root_node = root_node->left;
    }
    else if (root_node->left != NULL && root_node->right != NULL) {
      Node * min_node = find_minimum(root_node->right);
      root_node->set_value(min_node->value());
    }
    return root_node;
  }  
  if (node_value < root_node->value()) {
    root_node->left = _delete(root_node->left, node_value);
  }
  else if (node_value > root_node->value()) {
    root_node->right = _delete(root_node->right, node_value);
  }
  return root_node;
}

void Tree::print_tree_inorder() {
  _print_tree_inorder(root);
}

void Tree::_print_tree_inorder(Node* root) const {
  if (root == NULL) return;
 _print_tree_inorder(root->left);
  std::cout << "The node value is: " << root->value() << std::endl;
  _print_tree_inorder(root->right);
}
