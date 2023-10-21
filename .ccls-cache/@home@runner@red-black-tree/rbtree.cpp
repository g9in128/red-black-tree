#include "rbtree.h"

namespace rbtree {
  Node* getNode(int data, NodeType type, bool nil) {
    if (nil) type = NodeType::Black;
    Node* node {new Node{data,nil,type}};
    return node;
  }
}