#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
  /* TODO */
  int total = 0;
  while(list!=NULL) {
	  total= total+list->head;
	  list = list->tail;
  }
  return total;
}

void iterate(int (*f)(int), List *list) {
  /* TODO */
  while(list!=NULL) {
	  list->head=f(list->head);
	  list=list->tail;
  }
  return;
}

void print_list(List *list) { 
  /* TODO */
 
  while(list!=NULL) {
	  printf("%d, ",list->head);
	  list=list->tail;
  }
  printf("\n");
  return;
}

/**** CHALLENGE PROBLEMS ****/

void MoveNode(List** destRef, List** sourceRef) {
	
	List* newNode = *sourceRef;
	
	*sourceRef = newNode->tail;
	newNode->tail = *destRef;
	*destRef = newNode;
}

List *merge(List *list1, List *list2) { 
  List * result = NULL;
  List ** lastPtrRef = &result;
  while(1) {
	 if(list1==NULL) {
		 *lastPtrRef = list2;
		 break;
	 } else if (list2 == NULL) {
		 *lastPtrRef = list1;
		 break;
	 }
	 if (list1->head <= list2->head) {
		 MoveNode(lastPtrRef, &list1);
	 } else {
		 MoveNode(lastPtrRef, &list2);
	 }
	 lastPtrRef = &((*lastPtrRef)->tail);
	}
	return result;
 }
  

void split(List *list, List **list1, List **list2) { 
  /* TODO */
  List aDummy; 
  List* aTail = &aDummy; /* points to the last node in 'a' */
  List bDummy; 
  List* bTail = &bDummy; /* points to the last node in 'b' */
  List* current = list; 
  aDummy.tail = NULL; 
  bDummy.tail = NULL; 
  while (current != NULL)  
  { 
    MoveNode(&(aTail->tail), &(current)); /* add at 'a' tail */
    aTail = aTail->tail; /* advance the 'a' tail */
    if (current != NULL)  
    { 
      MoveNode(&(bTail->tail), &(current)); 
      bTail = bTail->tail; 
    } 
  } 
  *list1 = aDummy.tail; 
  *list2 = bDummy.tail; 
} 




/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *cl_mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = cl_mergesort(list1);
    list2 = cl_mergesort(list2);
    return merge(list1, list2);
  }
}
