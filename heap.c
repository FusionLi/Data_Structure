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

// mode: 0: insert; 1: delete
static binaryTreePTR findLastNode (binaryTreePTR root, binaryTreePTR parentNode, int level, int mode) {
	binaryTreePTR lastNode = root;
	while (level != 0) {
		if (mode == 0)
			parentNode->parent = lastNode;
		printf("level: %d and remainder: %d",level, level % 2);
		if ((level-1) % 2 == 0)
			lastNode = lastNode->left;
		else
			lastNode = lastNode->right;
		level /= 2;
	}
	return lastNode;
}

/* 
-1: insert failure
0: insert without modification
1: insert with modification (swap parent and child)
*/
int Insert(heapPTR heapHandle, int child) {
	if (heapHandle == NULL) 
		return -1;
	binaryTreePTR newNode = malloc(sizeof(struct binaryTree));
	newNode->data = child;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	// insert the node
	binaryTreePTR insertNode = findLastNode (heapHandle->heapHead, newNode, heapHandle->count, 0);
	insertNode = newNode;
	/* modify heap to if heap property is violated */
	int insertType = 0;
	// heap head's parent pointer points to NULL
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
	heapHandle->count += 1;
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
		struct binaryTree* deleteNode = findLastNode((*heapHandle)->heapHead, NULL, (*heapHandle)->count - i, 1);
		free(deleteNode);
	}
	free(*heapHandle);
	return;
}
























