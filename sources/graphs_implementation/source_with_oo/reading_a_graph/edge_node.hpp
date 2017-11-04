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
  EdgeNode* getNextNode() const;
  void setNextNode(EdgeNode*);
  int getYNode() const;
  void setYNode(int);
};

#endif /* EDGE_NODE_H */
