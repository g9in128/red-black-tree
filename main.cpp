#include <iostream>
#include <vector>
#include "rbtree.h"
using namespace rbtree;

int main() {
  RBTree test {RBTree::doTest()};
  test.printAll();
}