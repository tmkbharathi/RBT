#include "rbt.h"

tree_t* root=NULL;
tree_t* sentinel=NULL;
int main()
{
  sentinel=malloc(sizeof(tree_t));
  sentinel->data=-1;
  sentinel->color=black;
  root=sentinel;

	data_t data;
	data_t minimum;
	data_t maximum;
  int dummy;
    char option = 'y';
	do
	{
		printf("\n1. Insert\n2. Delete\n3. Find Minimum\n4. Delete Minimum\n5. Find Maximum\n6. Delete Maximum\n7. Print Tree\n");
		int operation;
		scanf(" %d", &operation);
		switch (operation)
		{
			case 1:
				printf("Enter the data to be inserted into the RB Tree: ");
				scanf("%d", &data);
			  insert(data);
				print_tree(root, 1);
				break;
		//	case 2:
		//		printf("Enter the data to be deleted from the RB Tree: ");
			//	scanf("%d", &data);
			//	delete(&root, data);
			//	print_tree(root, 1);
			//	break;
			case 3:
				dummy=find_minimum(&minimum);
        if (dummy == INT_MAX)
            printf("Empty Tree\n");
        else
				   printf("Minimum data: %d\n", minimum);
			  print_tree(root, 1);
				break;
			//case 4:
			//	delete_minimum(&root);
			//	print_tree(root, 1);
			//	break;
			case 5:
				dummy=find_maximum(&maximum);
        if (dummy == INT_MIN)
            printf("Empty Tree\n");
        else
				    printf("Maximum data: %d\n", maximum);
				print_tree(root, 1);
				break;				
			//case 6:
			//	delete_maximum(&root);
			//	print_tree(root, 1);
				break;				
      case 7:
        print_tree(root, 1);
        break;
		}
		//printf("\nWant to continue? Press [yY|nN]: ");
		//scanf("\n%c", &option);
	}while (option == 'y' || option == 'Y');

	return 0;
}

void print_tree(tree_t *ptr, int level) 
{
    if (ptr != sentinel) 
    {
        print_tree(ptr->right, level + 1);
        for (int i = 0; i < level; i++)
            printf("    ");

        printf("%d", ptr->data);                                //inorder Traversal

        if (ptr->color == red)
            printf(" (Red)\n");
        else
            printf(" (Black)\n");

        print_tree(ptr->left, level + 1);
    }
}

