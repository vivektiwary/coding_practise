#include "tree.hpp"
#include <iostream>

int main(void)
{
  Tree t(6);
  t.insert(3);
  t.insert(7);
  t.insert(5);
  t.insert(4);
  t.insert(2);
  t.print_tree_inorder();
  std::cout << "====================================" << std::endl; 
  t.delete_node(3);
  t.print_tree_inorder();
  return 0;
}
