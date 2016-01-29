#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int main() {
	heapPTR heap= NULL;
	char cmd[80];
	int data;
	int cmdOrderCheck = 0;
	while (1) {
		printf("Command: ");
		scanf("%79s", cmd);
		if (strcmp(cmd, "create") == 0 && cmdOrderCheck == 0) {
			printf("Data: ");
			scanf("%d", &data);
			CreateHeap(&heap, data);
			cmdOrderCheck = 1;
		}
		else if (strcmp(cmd, "insert") == 0 && cmdOrderCheck == 1) {
			printf("Data: ");
			scanf("%d", &data);
			Insert(heap, data);
		}
		else if (strcmp(cmd, "print") == 0 && cmdOrderCheck == 1) {
			PrintHeap(heap->heapHead);
		}
		else if (strcmp(cmd, "destroy") == 0 && cmdOrderCheck == 1) {
			DestroyHeap(&heap);
			cmdOrderCheck = 0;
		}
		else if (strcmp(cmd, "quit") == 0) {
			if (cmdOrderCheck == 1)
				DestroyHeap(&heap);
			break;
		}
		else {
			printf("Invalid command\n");
		}
	}
	return 0;
}
