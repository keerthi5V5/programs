#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 100
#define BLOCK_SIZE 512
typedef struct Block {
char data[BLOCK_SIZE];
} Block;
typedef struct IndexBlock {
int blockPointers[MAX_BLOCKS];
int numOfBlocks;
} IndexBlock;
void simulateFileAllocation(IndexBlock *indexBlock) {
printf("Simulating file allocation strategy...\n");
for (int i = 0; i < indexBlock->numOfBlocks; i++) {
printf("Reading Block %d: %s\n", i + 1, indexBlock->blockPointers[i] == -1 ? "Empty" : "Data");
}
}
int main() {
IndexBlock indexBlock;
indexBlock.numOfBlocks = 0;
for (int i = 0; i < MAX_BLOCKS; i++) {
indexBlock.blockPointers[i] = -1;
}
printf("Enter the number of blocks in the file: ");
scanf("%d", &indexBlock.numOfBlocks);
if (indexBlock.numOfBlocks <= 0 || indexBlock.numOfBlocks > MAX_BLOCKS) {
printf("Invalid number of blocks.\n");
return 1;
}
simulateFileAllocation(&indexBlock);
return 0;
}
