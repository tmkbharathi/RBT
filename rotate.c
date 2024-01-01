#include"rbt.h"

extern tree_t* sentinel;
extern tree_t* root;


void rotateleft(tree_t* pptr)
{
  tree_t* aptr;
  aptr=pptr->right;   // aptr is right child of pptr
  pptr->right=aptr->left;

  if(aptr->left!=sentinel)
  {
       aptr->left->parent=pptr;
  }
  aptr->parent=pptr->parent;

  if(pptr->parent == sentinel)
      root=aptr;
  else if( pptr== pptr->parent->left)
      pptr->parent->left=aptr;
  else
      pptr->parent->right=aptr;

  aptr->left=pptr;
  pptr->parent=aptr;
}

void rotateright(tree_t *pptr)
{
  tree_t *aptr;
  aptr=pptr->left;
  pptr->left=aptr->right;

  if(aptr->right != sentinel)
    aptr->right->parent=pptr;
  aptr->parent=pptr->parent;

  if(pptr->parent == sentinel)
      root=aptr;
  else if(pptr == pptr->parent->right)
      pptr->parent->right=aptr;
  else
     pptr->parent->left=aptr;
  aptr->right=pptr;
  pptr->parent=aptr;
}
