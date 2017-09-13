typedef struct info {
	int reads;
	int writes;
	int hits;
	int misses;
} info;

//array of chars and array of tagNodes so this is the block
typedef struct tagNode {
	char *bits;
	char *index;
	char *binary;
	struct tagNode *next;
} tagNode;

//array of blocks 
typedef struct setNode {
	tagNode *block;
} setNode; 