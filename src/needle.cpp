
#include "baseline/base.h"
#include "utils/fasta_read.h"
#include <stdlib.h>
// You'll have to declare the constant string size as it'll cause a segfault if you malloc at runtime
char sequence1[25000000], sequence2[25000000];
int main(int argc, char* argv[]) {
	if (argc != 6) {
		printf("Usage: ./needle file1 file2 match_score mismatch_score gap_score");
		return 0;
	}
	int n = readFASTA(sequence1, argv[1]);
	int m = readFASTA(sequence2, argv[2]);
	int match = atoi(argv[3]);	
	int mismatch = atoi(argv[4]);	
	int gap = atoi(argv[5]);	
	long int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
	printf("%ld", ans);
}
