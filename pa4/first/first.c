#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "first.h"

void superFree(setNode **cache, int setNum) {
	tagNode *ptr;
	int i;
	for (i = 0; i <setNum; i++) {
		while (cache[i]->block != NULL) {
			ptr = cache[i]->block;
			cache[i]->block = cache[i]->block->next;
			free(ptr->bits);
			free(ptr->index);
			free(ptr->binary);
			free(ptr);
		}
		free(cache[i]);
	}
	free(cache);
}

//node maker
tagNode *createTagNode (char *input, char *index, char *binary) {
	tagNode *tag = (tagNode*) malloc(sizeof(tagNode));
	tag->bits = input;
	tag->index = index;
	tag->binary = binary;
	tag->next = NULL;
	return tag; 
}

//forms set
setNode *createSet () {
	setNode *set = (setNode*) malloc(sizeof(setNode));
	set->block = NULL;
	return set; 
}

//check the number of tags
int numberOfTags (tagNode *root) {
	tagNode *ptr;
	ptr = root;
	int tagNumber = 0;
	while (ptr != NULL) {
		tagNumber++;
		ptr = ptr->next;
	}
	return tagNumber;
}

//forms blocks
void insertTagNode (setNode *start, tagNode *insert, int setSize) {
	if (start->block == NULL) {
		start->block = insert;
		return;
	}
	else {
		tagNode *ptr;
		if (numberOfTags(start->block) >= setSize) {
			if (setSize == 1) {
				start->block = insert;
				return;
			}
			ptr = start->block;
			start->block = start->block->next;
			free(ptr->bits);
			free(ptr->index);
			free(ptr->binary);
			free(ptr);
		}
		ptr = start->block;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = insert;
	}
	return;
}

//checks for tags by going through cache (0 not there, 1 there)
int checkTag (setNode *start, char* tag) {
	if (start->block == NULL) {
		return 0;
	}
	else {
		tagNode *ptr;
		ptr = start->block;
		while (ptr !=NULL) {
			if (strcmp(ptr->bits, tag) == 0) {
				return 1;
			}
			ptr = ptr->next;
		}
	}
	return 0;
}

//prints results
void printResult (info a, info b) {
	printf("cache A\n");
	printf("Memory reads: %d\n", a.reads);
	printf("Memory writes: %d\n", a.writes);
	printf("Cache hits: %d\n", a.hits);
	printf("Cache misses: %d\n", a.misses);

	printf("cache B\n");
	printf("Memory reads: %d\n", b.reads);
	printf("Memory writes: %d\n", b.writes);
	printf("Cache hits: %d\n", b.hits);
	printf("Cache misses: %d\n", b.misses);
}

// checks if its a power of 2 for input
int powerOf2 (int x) {
	while (x != 1) {
		if ((x % 2 == 1) && (x != 1)) {
			return 0;
		}
		x = x / 2;
	}
	return 1;
}

//takes hex without the 0x and returns binary
char *hexToBinary(char *hex) {
	char *bin = (char*) malloc(49 * sizeof(char));
	int i;
	for(i = 0; i < strlen(hex); i++) {
		switch(hex[i]) {
			case '0':
				bin[i*4+0] = '0';
				bin[i*4+1] = '0';
				bin[i*4+2] = '0';
				bin[i*4+3] = '0';
				break;
			case '1':
				bin[i*4+0] = '0';
				bin[i*4+1] = '0';
				bin[i*4+2] = '0';
				bin[i*4+3] = '1';
				break;
			case '2':
				bin[i*4+0] = '0';
				bin[i*4+1] = '0';
				bin[i*4+2] = '1';
				bin[i*4+3] = '0';
				break;
			case '3':
				bin[i*4+0] = '0';
				bin[i*4+1] = '0';
				bin[i*4+2] = '1';
				bin[i*4+3] = '1';
				break;
			case '4':
				bin[i*4+0] = '0';
				bin[i*4+1] = '1';
				bin[i*4+2] = '0';
				bin[i*4+3] = '0';
				break;
			case '5':
				bin[i*4+0] = '0';
				bin[i*4+1] = '1';
				bin[i*4+2] = '0';
				bin[i*4+3] = '1';
				break;
			case '6':
				bin[i*4+0] = '0';
				bin[i*4+1] = '1';
				bin[i*4+2] = '1';
				bin[i*4+3] = '0';
				break;
			case '7':
				bin[i*4+0] = '0';
				bin[i*4+1] = '1';
				bin[i*4+2] = '1';
				bin[i*4+3] = '1';
				break;
			case '8':
				bin[i*4+0] = '1';
				bin[i*4+1] = '0';
				bin[i*4+2] = '0';
				bin[i*4+3] = '0';
				break;
			case '9':
				bin[i*4+0] = '1';
				bin[i*4+1] = '0';
				bin[i*4+2] = '0';
				bin[i*4+3] = '1';
				break;
			case 'a':
				bin[i*4+0] = '1';
				bin[i*4+1] = '0';
				bin[i*4+2] = '1';
				bin[i*4+3] = '0';
				break;
			case 'b':
				bin[i*4+0] = '1';
				bin[i*4+1] = '0';
				bin[i*4+2] = '1';
				bin[i*4+3] = '1';
				break;
			case 'c':
				bin[i*4+0] = '1';
				bin[i*4+1] = '1';
				bin[i*4+2] = '0';
				bin[i*4+3] = '0';
				break;
			case 'd':
				bin[i*4+0] = '1';
				bin[i*4+1] = '1';
				bin[i*4+2] = '0';
				bin[i*4+3] = '1';
				break;
			case 'e':
				bin[i*4+0] = '1';
				bin[i*4+1] = '1';
				bin[i*4+2] = '1';
				bin[i*4+3] = '0';
				break;
			case 'f':
				bin[i*4+0] = '1';
				bin[i*4+1] = '1';
				bin[i*4+2] = '1';
				bin[i*4+3] = '1';
				break;	
		}
	}
	
	bin[48] = '\0';
	return bin;
}

int binaryToDecimal(char *binary) {
	int i;
	int result = 0;
	int power = 0; 
	for (i = strlen(binary) - 1; i >= 0; i--) {
		int added = (binary[i] - '0') * (int)pow(2, power);
		result += added;
		power++;
	}
	return result;
}

//calculate number of sets for cache
int numCacheSets(int assoc, int cacheS, int blockS) {
	if (assoc == 1) {
		return (cacheS/blockS);
	}
	else {
		if (assoc != 0) {
			return ((cacheS)/(blockS * assoc));
		}
		else {
			return 1; 
		}
	}
}

int sizeOfSets(int associativity, int cacheS, int blockS) {
	if (associativity != 0) {
		return associativity;
	}
	else {
		return (cacheS/blockS);
	}
}

//calculate number of tag bits
int numTagBits(int memLength, int setIndexBits, int blockOffsetBits) {
	return memLength - setIndexBits - blockOffsetBits;
}

//block offset bits
int numBlockOffsetBits(int blockSize) {
	return (int)(log((double)blockSize)/log(2.0));
}

//set index bits
int numSetIndexBits(int cacheSets) {
	return (int)(log((double)cacheSets)/log(2.0));
}

//gets bits given the start of the mem address
char *bitMaker(int front, int bits, char *memAddress) {
	char *bit = (char*) malloc(sizeof(char) * (bits+1));
	int i;
	for (i = front; i < front +bits; i++) {
		bit[i-front] = memAddress[i];
	}
	bit[bits] = '\0';
	return bit;
}

int main(int argc, char** argv) {
	
	int i, j, k;
	//checks for 5 inputs bc 5 inputs in usage interface
	if (argc != 5) {
		printf("Error\n");
		return -1;
	}

	//assign variables to each input
	int cacheSize = atoi(argv[1]);
	char *cache_Assoc = argv[2];
	int blockSize = atoi(argv[3]);
	FILE *fp;
	fp = fopen(argv[4], "r");

	char one[7] = "direct";
	char two[6] = "assoc";
	char three[7] = "assoc:";
	int cacheAssoc;

	//checks if inputs are correct
	//check for cacheSize
	if ((cacheSize == 0) || (powerOf2(cacheSize) == 0)) {
		printf("Error\n");
		return -1;
	}

	//checks associativity
	if (strlen(cache_Assoc) < 5) {
		printf("Error\n");
		return -1;
	}
	else {
		if (strlen(cache_Assoc) == 5) {
			if (strcmp(cache_Assoc, two) == 0) {
				cacheAssoc = 0;
			}
			else {
				printf("Error\n");
				return -1;
			}
		}
		if (strlen(cache_Assoc) == 6) {
			if (strcmp(cache_Assoc, one) == 0) {
				cacheAssoc = 1;
			}
			else {
				printf("Error\n");
				return -1;
			}
		}
		if (strlen(cache_Assoc) > 6) {
			char threeCompare[7];
			for (i = 0; i < 6; i++) {
				threeCompare[i] = cache_Assoc[i];
			}
			if (strcmp(threeCompare, three) != 0) {
				printf("Error\n");
				return -1;
			}
			int nInt = strlen(cache_Assoc) - 5;
			char *nWay = (char*) malloc(nInt * sizeof(char));
			for (j = 0; j < nInt; j++) {
				nWay[j] = cache_Assoc[j+6];
			}
			cacheAssoc = atoi(nWay);
			if ((cacheAssoc == 0) || (powerOf2(cacheAssoc) == 0)) {
				printf("Error\n");
				return -1;
			}
			free(nWay);
		}
	}

	//check block size 
	if ((blockSize == 0) || (powerOf2(blockSize) == 0)) {
		printf("Error\n");
		return -1;
	}

	//check file input
	if (fp == NULL) {
		printf("Error\n");
		return -1;
	}

	//setup info
	info typeA = {0, 0, 0, 0};
	info typeB = {0, 0, 0, 0};

	//setup cache
	int numSets = numCacheSets(cacheAssoc, cacheSize, blockSize);
	int setSize = sizeOfSets(cacheAssoc, cacheSize, blockSize);
	int blockOffsetBits = numBlockOffsetBits(blockSize);
	int setIndexBits = numSetIndexBits(numSets);
	int tagBits = numTagBits(48,setIndexBits, blockOffsetBits);

	setNode **cacheA = (setNode**) malloc(numSets * sizeof(setNode*));
	for (i = 0; i < numSets; i++) {
		cacheA[i] = createSet();
	}
	setNode **cacheB = (setNode**) malloc(numSets * sizeof(setNode*)); 
	for (i = 0; i < numSets; i++) {
		cacheB[i] = createSet();
	}

	char counter[20];
	char row;
	char memAddress[15];

	char *binaryMemA;
	char *binaryMemB;
	char *tagCacheA;
	char *indexCacheA;
	int indexDecimalA;

	char *tagCacheB;
	char *indexCacheB;
	int indexDecimalB;

	while (fscanf(fp, "%s %c %s", counter, &row, memAddress) != 1) {
		//put zeros on the left
		char newMem[13];
		int lZero = 14 - strlen(memAddress);
		for (k = 0; k < lZero; k++) {
			newMem[k] = '0';
		}
		for (i = lZero; i < 13; i++) {
			newMem[i] = memAddress[i - lZero + 2];
		}
		newMem[12] = '\0';
		//only doing this to free in the end
		binaryMemA = hexToBinary(newMem);
		binaryMemB = hexToBinary(newMem);

		tagCacheA = bitMaker(0, tagBits, binaryMemA);
		indexCacheA = bitMaker(tagBits, setIndexBits, binaryMemA);
		indexDecimalA = binaryToDecimal(indexCacheA);

		//printf("%s\n", tagCacheA);

		if (checkTag(cacheA[indexDecimalA], tagCacheA) == 0) {
			typeA.misses++;
			typeA.reads++;
			insertTagNode(cacheA[indexDecimalA], createTagNode(tagCacheA, indexCacheA, binaryMemA), setSize);
			if (row == 'W') {
				typeA.writes++;
			}
		}
		else {
			typeA.hits++;
			if (row == 'W') {
				typeA.writes++;
			}
		}

		tagCacheB = bitMaker(setIndexBits, tagBits, binaryMemB);
		indexCacheB = bitMaker(0, setIndexBits, binaryMemB);
		indexDecimalB = binaryToDecimal(indexCacheB);

		if (checkTag(cacheB[indexDecimalB], tagCacheB) == 0) {
			typeB.misses++;
			typeB.reads++;
			insertTagNode(cacheB[indexDecimalB], createTagNode(tagCacheB, indexCacheB, binaryMemB), setSize);
			if (row == 'W') {
				
				typeB.writes++;
			}
		}
		else {
			typeB.hits++;
			if (row == 'W') {
				typeB.writes++;
			}
		}

	}
	fclose(fp);
	superFree(cacheA, numSets);
	superFree(cacheB, numSets);
	printResult(typeA,typeB);
	return 0;
}