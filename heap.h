typedef struct heap* heapPTR;
typedef struct binaryTree* binaryTreePTR;

void CreateHeap(heapPTR* heapHandle, int root);
int Insert(heapPTR heapHandle, int child);
void PrintHeap (binaryTreePTR heapRoot);
void DestroyHeap (heapPTR* heapHandle);

// Max parent heap
struct heap
{
	struct binaryTree* heapHead;
	int count; // keep track how many nodes have been inserted
};

// add node for its parent
struct binaryTree
{
	int data;
	struct binaryTree* left;
	struct binaryTree* right;
	struct binaryTree* parent;
};
