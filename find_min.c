/*******************************************************************************************************************************************************************
*Title			: Find Minimum
*Description		: This function finds the minimum data from the given Red Black tree.
*Prototype		: int find_minimum(tree_t **root, data_t *min);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: min – Minimum data present in the tree is collected via this pointer.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"
extern tree_t * root, *sentinel;
int find_minimum(data_t *min)
{
  if(root==sentinel)
    return INT_MAX; 
    tree_t *mfind=root;
    while(mfind->left != sentinel)
        mfind=mfind->left;
    *min=mfind->data;
    return 0;
}
