#ifndef RBT_H
#define RBT_H
#define SUCCESS 0
#define FAILURE -1

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef int data_t;
typedef struct node
{
	struct node *left;
	data_t data;
	struct node *right;
	struct node *parent;
  enum{black , red}color;
}tree_t;


void print_tree(tree_t *ptr, int level, int direction);
void freeptr(tree_t *clean);

void insert(data_t data);
void insertbalance(tree_t *ptr);
void rotateright(tree_t *ptr);
void rotateleft(tree_t *ptr);


int find_maximum(data_t *max);
int find_minimum(data_t *min);

void delete(data_t item);
int find(int item, tree_t** loc);
void delbalance(tree_t *ptr);
tree_t* succ(tree_t *loc);

int delete_maximum();
int delete_minimum();

#endif
