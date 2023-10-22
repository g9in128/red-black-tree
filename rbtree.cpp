#include "rbtree.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace rbtree;

// RBTree::Node
RBTree::Node::Node(Node* parent,int data,NodeType type) 
  : m_parent(parent), m_data(data), m_type(type), 
  nil(false), m_left(new Node(this)), m_right(new Node(this)) {}

RBTree::Node::Node(Node* parent) : m_parent(parent), m_data(0), nil(true),
  m_type(NodeType::Black), m_left(nullptr), m_right(nullptr) {}

void RBTree::Node::assignNilNode(Node* at,int data,NodeType type) {
  if (at->nil) {
    at->m_data = data;
    at->m_type = type;
    at->nil = false;
    at->m_left = new Node(at);
    at->m_right = new Node(at);
  }
} 

void RBTree::Node::free(Node* start) {
  if (start->m_left != nullptr) free(start->m_left);
  if (start->m_right != nullptr) free(start->m_right);
  delete start;
}


// RBTree
RBTree::RBTree() : m_tree(nullptr) {}

RBTree::~RBTree() {
  Node::free(m_tree);
}

int RBTree::getHeight(int size) {
  int n = 1;
  while (size > 1) {
    size /= 2;
    n++;
  }
  return n;
}

void RBTree::printSpace(int n) {
  for (int i {0}; i < n; i++) std::cout << '\t';
}

int RBTree::pow(int base,int n) {
  int num {1};
  for (int i = 0; i < n;i++) {
    num *= base;
  }
  return num;
}

int RBTree::size() {
  return m_size;
}

void RBTree::printAll() {
  int height {getHeight(m_size)};
  int length {pow(2,height)};
  std::pair<int,NodeType>* tree {new std::pair<int,NodeType>[length]};
  for (int i = 0; i < length; i++) {
    tree[i] = {0,NodeType::None};
  }
  toArrayTree(tree, m_tree, 1);
  
  int start {pow(2,height - 1) - 1};
  int nextline {1};
  printSpace(start);
  for (int i {0}; i < length - 1; i++) {
    if (i == nextline) {
      start /= 2;
      nextline += 2 * nextline;
      std::cout << std::endl;
      printSpace(start);
    }
    std::pair<int,NodeType> node {tree[i + 1]};
    if (node.second != NodeType::None) {
      std::cout << (node.second == NodeType::Red ? "\033[41m" : "");
      std::cout << node.first << "\033[00m\t";
    }
    if (i != nextline - 1) {
      printSpace(start * 2 + 1);
    }
  }
  std::cout << std::endl;
  delete[] tree;
}

std::vector<std::pair<int,NodeType>> RBTree::toArrayTree() {
  int height {getHeight(m_size)};
  int length {pow(2,height)};
  std::pair<int,NodeType>* tree {new std::pair<int,NodeType>[length]};
  for (int i = 0; i < length; i++) {
    tree[i] = {0,NodeType::None};
  }
  toArrayTree(tree, m_tree, 1);

  std::vector<std::pair<int,NodeType>> ret {};
  for (int i = 0; i < length; i++) {
    ret.push_back(tree[i]);
  }
  delete[] tree;
  return ret;
}

void RBTree::toArrayTree(std::pair<int,NodeType>* tree,Node* nowp,int nowl) {
  tree[nowl] = {nowp->m_data,nowp->m_type};
  if (nowp->m_left != nullptr && !nowp->m_left->nil) {
    toArrayTree(tree, nowp->m_left, nowl * 2);
  }
  if (nowp->m_right != nullptr && !nowp->m_right->nil) {
    toArrayTree(tree, nowp->m_right, nowl * 2 + 1);
  }
}

RBTree RBTree::doTest() {
  RBTree tree {};
  Node* now {new Node(nullptr,17,NodeType::Black)};
  tree.m_tree = now;
  now = now->m_left;
  Node::assignNilNode(now,9,NodeType::Black);
  Node::assignNilNode(now->m_left, -1);
  Node::assignNilNode(now->m_right,10);
  now = now->m_parent->m_right;
  Node::assignNilNode(now, 30,NodeType::Black);
  Node::assignNilNode(now->m_left,18);
  Node::assignNilNode(now->m_right,45);
  tree.m_size = 7;
  return tree;
}