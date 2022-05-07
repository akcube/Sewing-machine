#include <utils.h>
#include <bits/stdc++.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

void* readFASTA(std::string fileName, int &n){
	int fd = open(fileName.c_str(), O_RDONLY);
	struct stat filestat;
	if(fstat(fd, &filestat) !=0) {
		perror("stat failed");
		exit(1);
	}
	char *file = (char*) mmap(NULL, filestat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	close(fd);
	for(int i=0; i<filestat.st_size; i++) if(file[i] == '\n') {
		file = &file[i+1];
		n = filestat.st_size - i - 1;
		break;
	}

	return (void*) file;
}

void* page_alloc(size_t mem_sz){
	return mmap(NULL, mem_sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}