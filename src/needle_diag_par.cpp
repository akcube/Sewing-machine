#include <bits/stdc++.h>
#include <needle.h>
#include <utils.h>
#include <sys/mman.h>

using namespace std;

int needle_diag_par(char* seq1, int n, char* seq2, int m, int match, int mismatch, int gap) {
    if (n < m) {
        return needle_diag_par(seq2, m, seq1, n, match, mismatch, gap);
    }
	int *curr1 = (int*) page_alloc(sizeof(int) * (max(m, n)+1));
	int *curr2 = (int*) page_alloc(sizeof(int) * (max(m, n)+1));
	int *curr3 = (int*) page_alloc(sizeof(int) * (max(m, n)+1));
    int *c1 = curr1, *c2 = curr2, *c3 = curr3;
    for (int i = 1; i <= m; i++) {
        c1[0] = c2[0] + gap;
        c1[i] = c2[i - 1] + gap;
        #pragma omp parallel for num_threads(8) proc_bind(close)
        for (int j = 1; j < i; j++) {
            int s = seq1[j - 1] == seq2[i - j - 1] ? match : mismatch;
            c1[j] = max(c3[j - 1] + s, max(c2[j - 1], c2[j]) + gap);        
        }
        swap(c1, c3);
        swap(c2, c3);
    }    
    for (int i = 1; i <= n - m; i++) {
        c1[m] = c2[m] + gap;    
        #pragma omp parallel for num_threads(8) proc_bind(close)
        for (int j = 0; j < m; j++) {
            int s = seq1[j + i - 1] == seq2[m - j - 1] ? match : mismatch;
            c1[j] = max(c3[j + (i != 1)] + s, max(c2[j], c2[j + 1]) + gap);
        }
        swap(c1, c3);
        swap(c2, c3);
    }
    int h = 1;
    for (int i = n - m + 1; i <= n; i++) {
        #pragma omp parallel for num_threads(8) proc_bind(close)
        for (int j = 0; j <= m - h;  j++) {
            int s = seq1[i + j - 1] == seq2[m - j - 1] ? match : mismatch;
            c1[j] = max(c3[j + (i != 1)] + s, max(c2[j], c2[j + 1]) + gap);
        }
        h++;
        swap(c1, c3);
        swap(c2, c3);
    }
    int ans = c2[0];
    munmap(curr1, sizeof(int) * (max(m, n)+1));
    munmap(curr2, sizeof(int) * (max(m, n)+1));
    munmap(curr3, sizeof(int) * (max(m, n)+1));
    return ans;
}