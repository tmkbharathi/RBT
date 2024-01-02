/*******************************************************************************************************************************************************************
 *Title			: Deletion
 *Description		: This function performs deleting of the given data from the given Red Black tree.
 *Prototype		: int delete(tree_t **root, data_t item); 
 *Input Parameters	: root – Pointer to the root node of the Red Black tree.
 : item – Data to be deleted from the Red Black tree.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

extern tree_t * root, *sentinel;
void delete(data_t item)
{
  tree_t * child, *ptr, *successor;
  if(!find(item, &ptr))
  {
    printf("Item Not present\n");                             //find node to delete
    return;      
  }
  if(ptr->left != sentinel ||  ptr->right !=sentinel)           //checking ptr have child are not
  {
    successor=succ(ptr);
    ptr->data = successor->data;
    ptr=successor;
  }

  if(ptr->left != sentinel)
    child=ptr->left;
  else
    child=ptr->right;
  child->parent=ptr->parent;

  if(ptr->parent == sentinel)
    root=child;
  else if(ptr==ptr->parent->left)
    ptr->parent->left=child;
  else
    ptr->parent->right=child;

  if(child == root)
    child->color=black;
  else if(ptr->color == black)
  {
    if(child!=sentinel)                     
      child->color=black;
    else
      delbalance(child);
  }
}

void delbalance(tree_t *nptr)
{
  tree_t *sib;
  while(nptr!=root)
  {
    if(nptr==nptr->parent->left)
    {
      sib=nptr->parent->right;
      if(sib->color ==  red)                    //case 1; Node sibling is red rotate and call case 2/3
      {
        sib->color==black;
        nptr->parent->color=red;
        rotateleft(nptr->parent);
        sib=nptr->parent->right;        //new sibling
      }
      if(sib->left->color==black && sib->right->color==black)   //case 2 nsiblings and both nephews are black
      {
        sib->color=red;
        if(nptr->parent->color == red)          //case 2a; parent is red 
        {
          nptr->parent->color=black;
          return;
        }
        else
          nptr=nptr->parent;
      }
      else
      {
        if(sib->right->color == black)        //case 3a; sibling is black, far nephew is black, other newphew will be red 
        {
          sib->left->color=black;
          sib->color=red;
          rotateright(sib);
          sib=nptr->parent->right;
        }
        sib->color=nptr->parent->color;         //case 3b; sibling is balck , far nephew is red other may be either black or red
          nptr->parent->color = black;
        sib->right->color=black;
        rotateleft(nptr->parent);
        return;
      }
    }
    else
    {
      sib=nptr->parent->left;
      if(sib->color ==red)                //case1
      {
        sib->color=black;
        nptr->parent->color=red;
        rotateright(nptr->parent);
        sib=nptr->parent->left;
      } 
      if(sib->right->color==black && sib->left->color==black)   //case 2 nsiblings and both nephews are black
      {
        sib->color=red;
        if(nptr->parent->color == red)          //case 2a; parent is red 
        {
          nptr->parent->color=black;
          return;
        }
        else
          nptr=nptr->parent;
      }
      else
      {
        if(sib->left->color == black)        //case 3a 
        {
          sib->right->color=black;
          sib->color=red;
          rotateleft(sib);
          sib=nptr->parent->left;
        }
        sib->color=nptr->parent->color;         //case 3b
          nptr->parent->color = black;
        sib->left->color=black;
        rotateright(nptr->parent);
        return;
      }
    }
  }
}
  tree_t* succ(tree_t *loc)
  {
    tree_t* ptr=loc->right;
    while(ptr->left!=sentinel)
    {
      ptr=ptr->left;
    }
    return ptr;
  }

  int find(int item, tree_t **loc)
  {
    tree_t *ptr;
    if(root == sentinel)              //tree empty
    {
      *loc=sentinel;
      return 0;
    }
    if(item == root->data)            //item is at root 
    {
      *loc=root;
      return 1;
    }
    if(item<root->data)
      ptr=root->left;
    else
      ptr=root->right;
    while(ptr!=sentinel)
    {
      if(item==ptr->data)
      {
        *loc=ptr;
        return 1;
      }
      if(item<ptr->data)
        ptr=ptr->left;
      else
        ptr=ptr->right;
    }
    *loc=sentinel;                    //if Item not found
    return 0;
  }
