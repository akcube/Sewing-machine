#ifndef UTILS_H
#define UTILS_H
#include <bits/stdc++.h>
void* readFASTA(std::string &fileName, int &n, size_t fsize);
void* page_alloc(size_t mem_sz);
size_t get_file_size(std::string &fileName);
void* slowReadFASTA(std::string &fileName, int &n, size_t fsize);
#endif
