#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BTree.h"

int main() {
  BTree* tree = new BTree(4);



   tree->add(1);
   tree->add(2);
   tree->add(3);
   tree->add(4);
   tree->add(5);
   tree->add(6);
   tree->add(7);
   tree->add(8);
   tree->add(9);
   tree->add(10);
   
   tree->print();

   tree->remove(7);
   tree->print();

   tree->remove(7);
   tree->print();

   printf("\n---------------------------------------------------\n");
   tree->print();
   printf("quant. nós=%d \n",tree->getNumberOfNodes());


delete tree;
  return 0;
}
