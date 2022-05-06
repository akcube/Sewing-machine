#include <bits/stdc++.h>

using namespace std;

#define d(i, j) ((i) * (m + 1) + (j))
int previous[(int)(2.5e7)] = {0};
int curr[(int)(2.5e7)] = {0};

int needle(char* seq1, int n, char* seq2, int m, int match, int mismatch, int gap) {
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
	return p[m]; 
}



