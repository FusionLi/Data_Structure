typedef heap* heapPTR;

struct heap
{
	struct binaryTree* heapHead;
	int count; // keep track how many nodes have been inserted
};

struct binaryTree
{
	int data;
	struct heap* left;
	struct heap* right;
};

