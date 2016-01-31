#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void CreateHeap(heapPTR* heapHandle, int root) {
	*heapHandle = malloc(sizeof(struct heap));
	(*heapHandle)->count = 1;
	(*heapHandle)->heapHead = malloc(sizeof(struct binaryTree));
	(*heapHandle)->heapHead->data = root;
	(*heapHandle)->heapHead->left = NULL;
	(*heapHandle)->heapHead->right = NULL;
	(*heapHandle)->heapHead->parent = NULL;
	return;
}

/*
return: 0: insert without modifying the heap (no swap between parent and child)
	1: insert with modifying the heap (swap between parent and child)
	-1: failure in insertion
*/
int Insert(heapPTR heapHandle, int child) {
	if (heapHandle == NULL) 
		return -1;
	heapHandle->count += 1;
	binaryTreePTR newNode = malloc(sizeof(struct binaryTree));
	binaryTreePTR insertNode = heapHandle->heapHead;
	newNode->data = child;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = insertNode;
	// insert the node
	int level = heapHandle->count;
	while (level > 1) {
		newNode->parent = insertNode;
		if (level % 2 == 0)
			insertNode = insertNode->left;
		else
			insertNode = insertNode->right;
		level /= 2;
	}
	insertNode = newNode->parent; //trick part: insertNode after the while loop is actually the pointer pointing to where the node should be inserted but not
				      // the node we can directly point to, so we need it parent node
	if (insertNode->left == NULL)  //trick part: cannot insert based on even or odd because the tree separates the even and odd data
		insertNode->left = newNode;
	else 
		insertNode->right = newNode;
	/* modify heap to if heap property is violated */
	int insertType = 0;
	// heap head's parent pointer points to NULL
	insertNode = newNode; //trick part: same as above
	while (insertNode->parent != NULL) {
		// heap property has been violated
		if (insertNode->data > (insertNode->parent)->data) {
			// swap data
			int temp = insertNode->data;
			insertNode->data = (insertNode->parent)->data;
			(insertNode->parent)->data = temp;
			insertType = 1;
		}
		insertNode = insertNode->parent;
	}
	return insertType;
}

void PrintHeap (binaryTreePTR heapRoot) {
	if (heapRoot == NULL)
		return;
	else {
		printf("Node: %d\n", heapRoot->data);
		PrintHeap(heapRoot->left);
		PrintHeap(heapRoot->right);
	}
}

void DestroyHeap (heapPTR* heapHandle) {
	for (int i = 0; i < (*heapHandle)->count; i++) {
		binaryTreePTR traceNode = (*heapHandle)->heapHead;
		binaryTreePTR deleteNode = (*heapHandle)->heapHead;
		int level = (*heapHandle)->count - i;
		while (level != 0) {
			deleteNode = traceNode;
			if (level % 2 == 0)
				traceNode = traceNode->left;
			else
				traceNode = traceNode->right;
			level /= 2;
		}
		free(deleteNode);
	}
	free(*heapHandle);
	return;
}
























