#pragma once
#include <utility>

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
  Node* getNode(int data,bool nil);
}
