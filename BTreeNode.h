#ifndef __BTREENODE_H_
#define __BTREENODE_H_

extern int M;

class BTreeNode {
public:
 
  int n;
  int* keys;
  bool leaf;
  BTreeNode** pointers;
  BTreeNode* parent;

  BTreeNode(int);
  ~BTreeNode();

  int searchPos(int);
  void moveOn(int, int);
  int min(int);
};

#endif
