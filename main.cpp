#include <iostream>
#include <vector>
#include "rbtree.h"
#include "treeprinter.h"
using namespace rbtree;

std::vector<Node*> doTest() {
  std::vector<Node*> testTree {};
  testTree.push_back(getNode(-7,NodeType::Black));
  testTree.push_back(getNode(-5,NodeType::Black));
  testTree.push_back(getNode(8));
  testTree.push_back(getNode(-10,NodeType::Black));
  testTree.push_back(getNode(-6));
  testTree.push_back(getNode(5,NodeType::Black));
  testTree.push_back(getNode(17,NodeType::Black));
  testTree.push_back(getNode(0,NodeType::Black,true));
  testTree.push_back(getNode(0,NodeType::Black,true));
  testTree.push_back(getNode(0,NodeType::Black,true));
  testTree.push_back(getNode(0,NodeType::Black,true));
  testTree.push_back(getNode(0,NodeType::Black,true));
  testTree.push_back(getNode(0,NodeType::Black,true));
  testTree.push_back(getNode(0,NodeType::Black,true));
  testTree.push_back(getNode(0,NodeType::Black,true));
  return testTree;
}

int main() {
  std::vector<Node*> test = doTest();
  TreePrinter printer {};
  printer.printTree(test);
}