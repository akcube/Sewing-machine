#include <bits/stdc++.h>
#include <utils.h>
#include <sys/mman.h>

using namespace std;

#define d(i, j) ((i) * (m + 1) + (j))

int needle_1d(char* seq1, int n, char* seq2, int m, int match, int mismatch, int gap) {
	int *previous = (int*) page_alloc(sizeof(int) * (max(m, n)+1));
	int *curr = (int*) page_alloc(sizeof(int) * (max(m, n)+1));
	for (int i = 1; i <= n; i++) {
		previous[i] = previous[i - 1] + gap;
	}
	int* p = previous;
	int* c = curr;
	for (int i = 1; i <= n; i++) {
		c[0] = p[0] + gap;
		for (int j = 1; j <= m; j++) {
			int s = seq1[i - 1] == seq2[j - 1] ? match : mismatch;
			c[j] = max(p[j - 1] + s, max(p[j], c[j - 1]) + gap);		
		}
		swap(p, c);
	}
	int ans = p[m];
	munmap(previous, sizeof(int) * (max(m, n)+1));
	munmap(curr, sizeof(int) * (max(m, n)+1));
	return ans; 
}
