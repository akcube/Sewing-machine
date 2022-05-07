#include <benchmark/benchmark.h>
#include <utils.h>
#include <needle.h>

// Define another benchmark
static void needle_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_1/1.fasta", f2 = "../../../data/small/test_1/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    std::cout<<ans<<std::endl;
  }
}
BENCHMARK(needle_bench);

BENCHMARK_MAIN();