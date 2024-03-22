#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BLOCK_SIZE 512 
typedef struct Block {
char data[BLOCK_SIZE];
struct Block *next;
} Block;
typedef struct File {
Block *firstBlock;
Block *lastBlock;
} File;
void initFile(File *file) {
file->firstBlock = NULL;
file->lastBlock = NULL;
}
void addBlockToFile(File *file, Block *block) {
if (file->firstBlock == NULL) {
file->firstBlock = block;
} else {
file->lastBlock->next = block;
}
file->lastBlock = block;
}
void simulateFileAllocation(File *file) {
printf("Simulating file allocation strategy...\n");
Block *currentBlock = file->firstBlock;
int blockCount = 0;
while (currentBlock != NULL) {
printf("Block %d: Data\n", ++blockCount);
currentBlock = currentBlock->next;
}
}
void freeFile(File *file) {
Block *currentBlock = file->firstBlock;
Block *nextBlock;
while (currentBlock != NULL) {
nextBlock = currentBlock->next;
free(currentBlock);
currentBlock = nextBlock;
}
file->firstBlock = NULL;
file->lastBlock = NULL;
}
int main() {
File file;
initFile(&file);
int numOfBlocks;
printf("Enter the number of blocks in the file: ");
scanf("%d", &numOfBlocks);
for (int i = 0; i < numOfBlocks; i++) {
Block *block = (Block *)malloc(sizeof(Block));
block->next = NULL;
addBlockToFile(&file, block);
}
simulateFileAllocation(&file);
freeFile(&file);
return 0;
}
