#include <bits/stdc++.h>
#include <utils.h>
#include <sys/mman.h>

using namespace std;

#define d(i, j) ((i) * (m + 1) + (j))

int needle(char* seq1, int n, char* seq2, int m, int match, int mismatch, int gap) {
	int (*dp)[m+1] = (int (*)[m+1]) page_alloc(sizeof(int) * (m+1) * (n+1));
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i-1][0] + gap;
	}
	for (int i = 1; i <= m; i++) {
		dp[0][i] = dp[0][i-1] + gap;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 0) {
				dp[i][j] = dp[i][j-1] + gap;
				continue;
			}
			if (j == 0) {
				dp[i][j] = dp[i-1][j] + gap;
				continue;
			}
			int s = seq1[i - 1] == seq2[j - 1] ? match : mismatch;
			dp[i][j] = dp[i-1][j-1] + s;
			if (max(dp[i-1][j], dp[i][j-1]) + gap > dp[i][j]) {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + gap;
			}
		}
	}
	int ans = dp[n][m];
	munmap(dp, sizeof(int) * (m+1) * (n+1));
	return ans;
}