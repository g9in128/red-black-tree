#pragma once
#include <vector>

namespace rbtree {
  enum class NodeType {
    Black,
    Red
  };
  
  struct Node {
    int data;
    bool nil;
    NodeType type;
  };
  
  Node* getNode(int data,NodeType type = NodeType::Red,bool nil = false);

  class RBTree {
    public:
      RBTree();
      ~RBTree();
      void add(int data);
      int del(int data);
      int find(int data);
      void printAll();
      std::vector<int> getAll();
      int getHeight();
    private:
      std::vector<Node*> m_tree;
      // Node* getNode(int data,NodeType type = NodeType::Red,bool nil = false);
      // Node* getNode(int data,bool nil);
      void free(int idx);
  };
}
