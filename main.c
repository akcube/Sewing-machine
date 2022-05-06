#include "utils/fasta_read.h"
// You'll have to declare the constant string size as it'll cause a segfault if you malloc at runtime
char sequence[1000000];
int main(int argc, char* argv[]) {
	readFASTA(sequence, argv[1]);
	printf("%s", sequence);
}
