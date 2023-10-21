#pragma once
#include<vector>

namespace rbtree {
  class TreePrinter {
  public:
    void printTree(const std::vector<int>& data);
  private:  
    int getHeight(const std::vector<int>& data);
    void printSpace(int n);
  }
}