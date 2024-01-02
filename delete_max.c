/*******************************************************************************************************************************************************************
*Title			: Delete Maximum
*Description		: This function deletes the maximum data from the given Red Black tree.
*Prototype		: int delete_maximum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"
extern tree_t *root, *sentinel;

int delete_maximum()
{
    tree_t *ptr=root;
    
    if (root==sentinel) 
    {
        printf("Tree is empty\n");
        return 0;
    }

    while (ptr->right!=sentinel)          // Find the rightmost node (maximum value)
        ptr=ptr->right;


    if (ptr->left!=sentinel || ptr->right!=sentinel)                 // Node to be deleted has at most one child
    {
        tree_t *child=(ptr->left != sentinel) ? ptr->left : ptr->right;
        child->parent=ptr->parent;

        if (ptr->parent==sentinel)
            root=child;
        else if (ptr==ptr->parent->left)
            ptr->parent->left=child;
        else
            ptr->parent->right=child;

        if (child==root)
            child->color=black;
        else if (ptr->color==black) 
        {
            if (child!=sentinel)
                child->color=black;
            else
                delbalance(child);
        }
    }
    else 
    {
        if (ptr==ptr->parent->left)                  // Node to be deleted is a leaf node
            ptr->parent->left=sentinel;
        else
            ptr->parent->right=sentinel;
    }

    if (ptr==root)
        return 0;
    if (ptr->color==black)
        delbalance(ptr);

    free(ptr);
}
