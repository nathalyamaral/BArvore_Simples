#include "BTreeNode.h"

BTreeNode::BTreeNode(int m){
  n = 0;
  leaf = true;
  keys = new int[m - 1];
  pointers = new BTreeNode*[m];
  parent = 0;
  for(int i = 0; i < m; i++)
    pointers[i] = 0;
}

BTreeNode::~BTreeNode() {
  delete [] keys;

  delete [] pointers;
}

int BTreeNode::searchPos(int value) {
  int pos = 0;

  while(pos < n && value > keys[pos])
    pos++;

  return pos;
}

void BTreeNode::moveOn(int initial, int final) {
  for(int i = initial; i > final; i--) {
    keys[i] = keys[i - 1];
    pointers[i + 1] = pointers[i];
  }
}


int BTreeNode::min(int m)
{
	if (this->parent == 0) return 1;
	else 
	{
		if (m%2 == 0)	return m/2 -1;
		else		return (int)m/2;

	}

}
