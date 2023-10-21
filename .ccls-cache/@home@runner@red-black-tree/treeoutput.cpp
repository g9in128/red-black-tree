#include <iostream>
#define FMT_HEADER_ONLY
#include "fmt/core.h"
#include "treeoutput.h"

int rbtree::TreePrinter::getHeight(const std::vector<int> &data) {
  int idx {static_cast<int>(data.size())};
  int n = 0;
  while (idx > 1) {
    idx /= 2;
    n++;
  }
  return n;
}

void rbtree::TreePrinter::printSpace(int n) {
  
}

void rbtree::TreePrinter::printTree(const std::vector<int> &data) {
  int h = rbtree::TreePrinter::getHeight(data);
  
}
