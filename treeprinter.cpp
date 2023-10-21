#include <iostream>
#include "rbtree.h"
#include "treeprinter.h"

int rbtree::TreePrinter::getHeight(const std::vector<Node *> &data) {
  size_t idx {data.size()};
  int n = 0;
  while (idx > 1) {
    idx /= 2;
    n++;
  }
  return n;
}

void rbtree::TreePrinter::printSpace(int n) {
  for (int i {0}; i < n; i++) std::cout << '\t';
}

int rbtree::TreePrinter::pow(int base,int n) {
  int num {1};
  for (int i = 0; i < n;i++) {
    num *= base;
  }
  return num;
}

void rbtree::TreePrinter::printTree(const std::vector<Node *> &data) {
  int h {getHeight(data)};
  int start {pow(2,h - 1) - 1};
  int nextline {1};
  printSpace(start);
  for (int i {0}; i < data.size(); i++) {
    if (i == nextline) {
      start /= 2;
      nextline += 2 * nextline;
      std::cout << std::endl;
      printSpace(start);
    }
    if (data[i] != nullptr) {
      Node& node {*data[i]};
      if (!node.nil) {
        std::cout << (node.type == NodeType::Red ? "\033[41m" : "") << node.data << "\033[00m\t";
      }else {
        std::cout << '\t';
      }
    }else {
      std::cout << '\t';
    }
    if (i != nextline - 1) {
      printSpace(start * 2 + 1);
    }
  }
  std::cout << std::endl;
}
