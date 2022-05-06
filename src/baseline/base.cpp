#define max(a, b) (a > b ? a : b)
#define d(i, j) ((i) * (m + 1) + (j))
#include "base.h"
#include <stdio.h>
#include <string.h>
long int dp[(int)1e9] = {0};
long int needle(char* seq1, int n, char* seq2, int m, int match, int mismatch, int gap) {
	for (int i = 1; i <= n; i++) {
		dp[d(i, 0)] = dp[d(i - 1, 0)] + gap;
	}
	for (int i = 1; i <= m; i++) {
		dp[d(0, i)] = dp[d(0, i - 1)] + gap;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 0) {
				dp[d(i, j)] = dp[d(i, j - 1)] + gap;
				continue;
			}
			if (j == 0) {
				dp[d(i, j)] = dp[d(i - 1, j)] + gap;
				continue;
			}
			int s = seq1[i - 1] == seq2[j - 1] ? match : mismatch;
			dp[d(i, j)] = dp[d(i - 1, j - 1)] + s;
			if (max(dp[d(i - 1, j)], dp[d(i, j - 1)]) + gap > dp[d(i, j)]) {
				dp[d(i, j)] = max(dp[d(i - 1, j)], dp[d(i, j - 1)]) + gap;
			}
			dp[d(i, j)] = max(dp[d(i, j)], 0);
		}
	}
	return dp[d(n, m)];
}