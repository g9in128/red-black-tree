#pragma once
#include <vector>

namespace rbtree {
  enum class NodeType {
    None = -1,
    Black,
    Red
  };
  

  class RBTree {
    public:
      RBTree();
      ~RBTree();
      void add(int data);
      int del(int data);
      int find(int data);
      void printAll();
      int size();
      std::vector<std::pair<int,NodeType>> toArrayTree();
      static RBTree doTest();
    private:
      class Node {
        public:
          Node(Node* parent,int data,NodeType type);
          Node(Node* parent);
          Node* m_parent;
          Node* m_left;
          Node* m_right;
          int m_data;
          bool nil;
          NodeType m_type;
          static void assignNilNode(Node* at,int data,
              NodeType type = NodeType::Red);
          static void free(Node* start);
      };
      Node* m_tree;
      int m_size {};
      static void toArrayTree(std::pair<int,NodeType>* tree,Node* nowp,int nowl);
      static int getHeight(int size);
      static void printSpace(int n);
      static int pow(int base,int n);
  };
  
}