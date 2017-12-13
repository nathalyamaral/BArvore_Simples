#include <stdio.h>
#include "BTree.h"

BTreeNode* BTree::search(int value, BTreeNode* node) {
  int i;

  if(node != 0) {
    for(i = 0; i < node->n && node->keys[i] < value; i++);

    if(i < node->n && node->keys[i] == value)
      return node;

    return search(value, node->pointers[i]);
  }

  return node;
}


bool BTree::remove(int key)
{
	int ret = remove (root, key);
	return true;
}

void BTree::add(int k) {
  BTreeNode* r,*s;
  
  r = root;
  if (r->n = M-1)
  {
      s = new BTreeNode(M);
      root = s;
      s->leaf = false;
      s->n = 0;
      s->pointers[0] = r;
      numberOfNodes++;
      splitChild(s,0);
      add(s,k);
  }
  else
  	  add(r,k);   
    
}

void BTree::add(BTreeNode* node, int value) {

  
}
void BTree::splitChild(BTreeNode* x, int i)
{
	BTreeNode* z,*y;

	z = new BTreeNode(M);
	y =  x->pointers[i];
	z->leaf = y->leaf;
	z->n = (M-1)/2;

	for (int j = 0; j < (M-1)/2; ++j)
		z->keys[j] = y->keys[j+((M-1)/2)];

	if(!y->leaf){
		for (int j = 0; j < (M-1)/2; ++j)
			z->pointers[j]= y->pointers[j+((M-1)/2)];
	}

	y->n = (M-1)/2;

	for (int j = x->n; j > 0; --j)
		x->pointers[j+1] = x->pointers[j];

	x->pointers[i+1] = z;

	for (int j = x->n; j > 0; --j)
		x->keys[j+1] = x->keys[j];

	x->keys[i] = y->keys[((M-1)/2)];
	x->n=x->n+1;
}

void BTree::print(BTreeNode* node, int spaces) {
  if(node != 0) {
    for(int i = 0; i < spaces; i++)
      printf(" ");

    for(int i = 0; i < node->n; i++)
    {
      printf("%d ",node->keys[i]);

    }
    if (node->parent)
	    printf ("(%d) (%d) (%d)",node->leaf, node->n, node->parent->keys[0]);
    else
  	    printf ("(%d) (%d) (nulo)",node->leaf, node->n );
    printf("\n");

    for(int i = 0; i < node->n + 1; i++)
      print(node->pointers[i], spaces + 5);
  }
}




int BTree::remove(BTreeNode* node, int value) 
{

	return 0;
   
}


BTreeNode* BTree::findBrother(BTreeNode* node,int *pos, bool *dir)
{

	int i;
	if (node->parent == 0)
	{
		printf("a raiz não tem irmão para realizar redistribuicao ou fusao!!!");
		return 0;	
	}

	// encontra qual é o índice do vetor pointers da raiz que aponta para node
      
	for( i=0; i < node->parent->n && node->parent->pointers[i]!=node; i++);

        // se i>0 significa que node tem irmão esquerdo
	if(i>0) 
	{
		*dir = false;
		if(node->parent->pointers[i-1]->n > node->parent->pointers[i-1]->min(M))
		{
			*pos = i-1;
			return node->parent->pointers[i-1]; // irmão à esquerda de node
		}
	
	}

        // se chegou aqui é porque i==0 ou o irmão esquerdo não tinha mais do que o mínimo de chaves
        // se não há um irmão direito de node 
	if(i< node->parent->n)
	{
		*dir = true;
		if(node->parent->pointers[i+1]->n >= node->parent->pointers[i+1]->min(M))
		{
			*pos = i;
			return node->parent->pointers[i+1];
		}
	}

	return 0;

}



void BTree::fusion (BTreeNode* node, BTreeNode* lft, BTreeNode* rgt)
{
	


}


BTreeNode* BTree::sucessor (BTreeNode * aux)
{

	while (aux->pointers[0]!=0)
		aux = aux->pointers[0];
	return aux;
}


