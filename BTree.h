#ifndef __BTREE_H_
#define __BTREE_H_

#include "BTreeNode.h"

class BTree {
private:
  int M; //ordem da b-árvore
  int numberOfKeys;   // quantidade de chaves 
  int numberOfNodes;   // quantidade de nós 
  BTreeNode* root;

  BTreeNode* search(int, BTreeNode*);
  void add(BTreeNode*, int);
  int remove(BTreeNode*, int);
  void print(BTreeNode*, int);
  BTreeNode* findBrother(BTreeNode* , int *, bool *);
  BTreeNode* sucessor (BTreeNode *);
  void fusion (BTreeNode* , BTreeNode* , BTreeNode*);
  void splitChild(BTreeNode*,int);

public:
  BTree(int order) {
    M = order;
    numberOfNodes = 0;
    numberOfKeys = 0;
    root = 0;
  }

  ~BTree() {
    delete root;
  }

  bool search(int value) {
    return search(value, root) != 0;
  }

  void add(int);
  bool remove(int);
 
  void print() {
    print(root, 0);
  }
  int getNumberOfNodes ()
  {
	return numberOfNodes;
  }
  //int min(int);

};

#endif
