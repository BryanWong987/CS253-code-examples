#ifndef __SINGLYLINKEDLIST_H
#define __SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "Job.h"
#include "Item.h"

typedef struct node Node;
typedef struct node *NodePtr;

typedef struct list List;
typedef struct list *ListPtr;

struct node {
	JobPtr item;
	NodePtr next;
};

struct list {
	NodePtr head;
};

/**
  Create a list
  @return a pointer to the new list
*/
ListPtr createList(void);

NodePtr createNode(JobPtr item);

void freeNode(NodePtr node);

/**
  Add a node to the front  of the list.
  @param L pointer to front of the list
  @param node the new node to add
  @return the current pointer to the front of the list
 */
void addAtFront(ListPtr L, NodePtr node);


/**
  Print the list from start to end.
  @param L pointer to front of the list
*/
void printList(ListPtr L);


/**
  free the list
  @param L pointer to front of the list
*/
void freeList(ListPtr L);


#endif /* __SINGLYLINKEDLIST_H */ 
