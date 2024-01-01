/*******************************************************************************************************************************************************************
*Title			: Find Maximum
*Description		: This function finds the maximum data from the given Red Black tree.
*Prototype		: int find_maximum(tree_t **root, data_t *max);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: max – Maximum data present in the tree is collected via this pointer.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

extern tree_t* root, *sentinel;

int find_maximum(data_t *max)
{
    if(root == sentinel)
        return INT_MIN;
    tree_t *mfind=root;
    while(mfind->right != sentinel)
        mfind=mfind->right;
    *max=mfind->data;
    return 0;
}
