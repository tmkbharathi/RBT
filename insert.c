/*******************************************************************************************************************************************************************
*Title			: Insertion
*Description		: This function performs inserting the new data into the given Red Black tree.
*Prototype		: int insert(tree_t **root, data_t item);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – New data to be inserted into the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

extern tree_t* root, *sentinel;
void insert(data_t item)
{
  struct node*tmp, *ptr, *par;
  par=sentinel;
  ptr=root;
  while(ptr!=sentinel)
  {
    par=ptr;
    if(item<ptr->data)
       ptr=ptr->left;
    else if(item > ptr->data)
       ptr=ptr->right;
    else
    {
      printf("INFO: Duplicate Elements can't be added\n");
      return;
    }
  }
  tmp=malloc(sizeof(tree_t));
  tmp->data=item;
  tmp->left=sentinel;
  tmp->right=sentinel;
  tmp->color=red;
  tmp->parent=par;
  if(par==sentinel)
       root=tmp;
  else if(tmp->data < par->data)
      par->left=tmp;
  else
      par->right=tmp;
  insertbalance(tmp);
}

void insertbalance(tree_t* ptr)
{
  tree_t* uncle, *par, *grandpar;
  while(ptr->parent->color == red)
  {
    par=ptr->parent;
    grandpar=par->parent;
    if(par == grandpar->left)
    {
      uncle=grandpar->right;
      if(uncle->color == red)    //case1: parent is red and parent is left child and uncle is red ->recolor it thats all
      {
         par->color=black;
         uncle->color=black;
         grandpar->color=red;
         ptr=grandpar;
      }
      else
      {
            if(ptr==par->right) //case2a, parent is red and parent is left child and uncle is black and newnode is right child->rotateleft abt parent and make to case2b
            {
              rotateleft(par);
              ptr=par;
              par=ptr->parent;
            }                          
            par->color=black;           //case 2b, parent is red and parent left and uncle is black and newnode is left child and recolor and rotate right about grandparent
            grandpar->color=red;
            rotateright(grandpar);
      }
    }
    else
    { 
      if( par ==  grandpar->right)
      {
      uncle=grandpar->left;
      if(uncle->color == red)       //case 1:parent is red and parent is right child and uncle is red then recolor 
      {
         par->color=black;
         uncle->color=black;
         grandpar->color=red;
         ptr=grandpar;
      }
      else                          
      {
        if(ptr == par->left)        //case 2a parent is red and parent is left child uncle is black and newnode is left child-> rotate right abt parent
        {
          rotateright(par);
          ptr=par;
          par=ptr->parent;
        }
        par->color=black;
        grandpar->color=red;
        rotateleft(grandpar);
        }
      }
    }
  }
  root->color=black;
} 

