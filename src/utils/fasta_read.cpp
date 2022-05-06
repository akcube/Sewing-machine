#include <utils.h>
#include <bits/stdc++.h>

int readFASTA(char *sequence, std::string fileName) {

	FILE* fp = fopen(fileName.c_str(), "r");
	// Clear first line 
	fscanf(fp, "%*[^\n]s\n");

	//Take input character by character to remove \n
	char c;
	long int index = 0;
	while (fscanf(fp, "%c", &c) == 1)
		if (c != '\n') sequence[index++] = c;

	sequence[index] = '\0';
	return index;
}

void* page_alloc(size_t mem_sz){
	return mmap(NULL, mem_sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}