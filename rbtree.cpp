#include "rbtree.h"
#include <iostream>

using namespace rbtree;

Node* getNode(int data, NodeType type, bool nil) {
  if (nil) type = NodeType::Black;
  Node* node {new Node{data,nil,type}};
  return node;
}

void RBTree::free(int idx) {
  int l {idx * 2},r {idx * 2 + 1};
  if (l < m_tree.size() && m_tree[l] != nullptr) {
    free(l);
  }
  if (r < m_tree.size() && m_tree[r] != nullptr) {
    free(r);
  }
  std::cout << m_tree[idx]->data;
  delete m_tree[idx];
}

RBTree::RBTree() : m_tree({0}) {}

RBTree::~RBTree() {
  free(1);
}