#include <stdlib.h>
#include "tree.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) { 
  /* TODO */
  if(tree==NULL) {
	  return 0;
  }
  if(tree->value == x) {
	  return 1;
  } else if(x<tree->value) {
	  return tree_member(x, tree->left);
  }
  return tree_member(x,tree->right);
}

Tree *tree_insert(int x, Tree *tree) { 
  /* TODO */
  if (tree == NULL) {
	Tree *temp =  (Tree *)malloc(sizeof(Tree)); 
    temp->value = x; 
    temp->left = temp->right = NULL; 
    return temp; 
  } 
  
  if (x < tree->value) {
      tree->left  = tree_insert(x, tree->left); 
  } else if (x > tree->value) {
      tree->right = tree_insert(x, tree->right); 
  }   
  
  return tree; 
  
}

void tree_free(Tree *tree) { 
  /* TODO */
  if(tree==NULL){
	  free(tree);
	  return;
  } else {
	  tree_free(tree->left);
	  tree_free(tree->right);
	  free(tree);
	  return;
  }
}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
  /* TODO */
  Tree * current = tree;
  while(current && current->left!=NULL){
	  current = current->left;
  }
  min = &current->value;
  free(current);
  new_tree = &tree;
  return;
}

Tree *tree_remove(int x, Tree *tree) { 
  /* TODO */
  if (tree==NULL) {
	  //the node does not exist in the tree so return the tree
	  return tree;
  }
  
  if(x<tree->value) {
	  tree->left = tree_remove(x, tree->left);
  } else if (x>tree->value) {
	  tree->right = tree_remove(x,tree->right);
  } else {
	  //we have found the correct node to remove.
	  if(tree->left==NULL) {
		  //there is only a right child (or no child) this should
		  //be the new head
		  Tree * newTree = tree->right;
		  free(tree);
		  return newTree;
	  } else if (tree->right==NULL) {
		  //there is only a left child this should be the new head
		  Tree * newTree = tree->left;
		  free(tree);
		  return newTree;
	  }
	  //ugh there are two children what a pain
	  int * min = NULL;
	  Tree **new_tree = &tree;
	  pop_minimum(tree->right,min,new_tree);
	  tree = *new_tree;
	  tree->value = *min;
  
	  
  }
  return tree;
}
