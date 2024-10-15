#include <stdio.h>
#include <stdlib.h>
#include "List.h"

ListPtr createList(void) {
    ListPtr list;
    list = (ListPtr) malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void freeList(ListPtr list) {
}

int getSize(ListPtr list) {
    return 0;
}

bool isEmpty(ListPtr list) {
    return false;
}

void addAtFront(ListPtr list, NodePtr node) {
}

void addAtRear(ListPtr list, NodePtr node) {
}

NodePtr removeFront(ListPtr list) {
    return NULL;
}

NodePtr removeRear(ListPtr list) {
    return NULL;
}

NodePtr removeNode(ListPtr list, NodePtr node) {
    return NULL;
}

NodePtr search(ListPtr list, int key) {
    return NULL;
}

void reverseList(ListPtr list) {
}

void printList(ListPtr list) {
}
