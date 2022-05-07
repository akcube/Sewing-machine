#include <bits/stdc++.h>
#include "a.h"

using namespace std;
int curr3[(int)(2.5e7)] = {0};
int curr2[(int)(2.5e7)] = {0};
int curr1[(int)(2.5e7)] = {0};

int needle(char* seq1, int n, char* seq2, int m, int match, int mismatch, int gap) {
	if (n < m) {
		return needle(seq2, m, seq1, n, match, mismatch, gap);
	}
	int *c1 = curr1, *c2 = curr2, *c3 = curr3;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= i; j++) {
			if (j != 0 && j != i) {
				int s = seq1[j - 1] == seq2[i - j - 1] ? match : mismatch;
				c1[j] = max(c3[j - 1] + s, max(c2[j - 1], c2[j]) + gap);		
			}	
			else if (j == 0) {
				c1[j] = c2[j] + gap;
			}
			else {
				c1[j] = c2[j - 1] + gap;
			}
		}
		swap(c1, c3);
		swap(c2, c3);
	}	
	for (int i = 1; i <= n - m; i++) {
		for (int j = 0; j <= m; j++) {
			if (j == m) {
				c1[j] = c2[j] + gap;	
			}
			else {
				int s = seq1[j + i - 1] == seq2[m - j - 1] ? match : mismatch;
				c1[j] = max(c3[j + (i != 1)] + s, max(c2[j], c2[j + 1]) + gap);
			}
		}
		swap(c1, c3);
		swap(c2, c3);
	}
	int h = 1;
	for (int i = n - m + 1; i <= n; i++) {
		for (int j = 0; j <= m - h;  j++) {
			int s = seq1[i + j - 1] == seq2[m - j - 1] ? match : mismatch;
			c1[j] = max(c3[j + (i != 1)] + s, max(c2[j], c2[j + 1]) + gap);
		}
		h++;
		swap(c1, c3);
		swap(c2, c3);
	}
	return c2[0];
}
