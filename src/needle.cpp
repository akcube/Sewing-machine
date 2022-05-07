#include <bits/stdc++.h>
#include <utils.h>
#include <sys/mman.h>

using namespace std;

#define d(i, j) ((i) * (m + 1) + (j))

int needle(char* seq1, int n, char* seq2, int m, int match, int mismatch, int gap) {
	int *dp = (int*) page_alloc(sizeof(int) * (m+1) * (n+1));
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
	int ans = dp[d(n, m)];
	munmap(dp, sizeof(int) * (m+1) * (n+1));
	return ans;
}