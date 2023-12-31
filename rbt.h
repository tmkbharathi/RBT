#ifndef RBT_H
#define RBT_H
#define SUCCESS 0
#define FAILURE -1

#include<stdio.h>
#include<stdlib.h>

typedef int data_t;
typedef struct node
{
	struct node *left;
	data_t data;
	struct node *right;
	struct node *parent;
  enum{black , red}color;
}tree_t;


void print_tree(tree_t *ptr, int level);

void insert(data_t data);
void insertbalance(tree_t *ptr);
void rotateright(tree_t *ptr);
void rotateleft(tree_t *ptr);
#endif
