#include <utils.h>
#include <bits/stdc++.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t get_file_size(std::string &fileName){
	int fd = open(fileName.c_str(), O_RDONLY);
	struct stat filestat;
	if(fstat(fd, &filestat) !=0) {
		perror("stat failed");
		exit(1);
	}
	close(fd);
	return filestat.st_size;
}

void* readFASTA(std::string &fileName, int &n, size_t fsize){
	int fd = open(fileName.c_str(), O_RDONLY);
	char *file = (char*) mmap(NULL, fsize, PROT_READ, MAP_PRIVATE, fd, 0);
	close(fd);
	for(int i=0; i<fsize; i++) if(file[i] == '\n') {
		file = &file[i+1];
		n = fsize - i - 1;
		break;
	}
	return (void*) file;
}

void* slowReadFASTA(std::string &fileName, int &n, size_t fsize){
	FILE* fp = fopen(fileName.c_str(), "r");
	fscanf(fp, "%*[^\n]s\n");
	char *seq = (char*) malloc(sizeof(char) * fsize);
	char c;
	int index = 0;
	while(fscanf(fp, "%c", &c) == 1) seq[index++] = c;
	seq[index] = '\0';
	n = index;
	return (void*) seq;
}

void* page_alloc(size_t mem_sz){
	return mmap(NULL, mem_sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}