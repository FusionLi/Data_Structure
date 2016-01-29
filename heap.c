#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void CreateHeap(heapPTR heapHandle, int root) {
	heapHandle = malloc(sizeof(struct heap));
	heapHandle->count = 1;
	heapHandle->heapHead = malloc(sizeof(struct binaryTree));
	heapHandle->heapHead->data = root;
	heapHandle->heapHead->left = NULL;
	heapHandle->heapHead->right = NULL;
	return;
}

/* 
-1: insert failure
0: insert without modification
1: insert with modification (swap parent and child)
*/
int Insert(heapPTR heapHandle, int child) {
	if (heapHandle == NULL) 
		return -1;
	struct binaryTree* newNode = malloc(sizeof(struct binaryTree));
	struct binaryTree* insertNode = heapHandle->heapHead;
	newNode->data = child;
	newNode->left = NULL;
	newNode->right = NULL;
	int level = heapHandle->count;
	// insert the node
	while (level != 0) {
		if (level % 2 == 0)
			insertNode = insertNode->left;
		else
			insertNode = insertNode->right;
		level /= level;
	}
	insertNode = newNode;
	// modify heap to if heap property is violated
	
	heapHandle->count += 1;
}

static 