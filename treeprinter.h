#pragma once
#include<vector>
#include "rbtree.h"

namespace rbtree {
  class TreePrinter {
  public:
    void printTree(const std::vector<Node*>& data);
  private:  
    int getHeight(const std::vector<Node*>& data);
    void printSpace(int n);
    int pow(int base,int n);
  };
}