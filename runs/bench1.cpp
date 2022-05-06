#include <benchmark/benchmark.h>
#include <utils.h>
#include <needle.h>

char sequence1[25000000], sequence2[25000000];

// Define another benchmark
static void needle_bench(benchmark::State& state) {
  std::string f1 = "../../../data/medium/1.fasta", f2 = "../../../data/medium/2.fasta";
  int match = 1, mismatch = -2, gap = 1;
  for (auto _ : state){
    int n = readFASTA(sequence1, f1);
    int m = readFASTA(sequence2, f2);
    long int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
  }
}
BENCHMARK(needle_bench);

BENCHMARK_MAIN();