#include <benchmark/benchmark.h>
#include <utils.h>
#include <needle.h>

/**
 * -----------------------------------------------------------------------------------------------------
 * Standard 2D N*M Needle Benchmarks
 * -----------------------------------------------------------------------------------------------------
 */
static void needle2d_small_1_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_1/1.fasta", f2 = "../../../data/small/test_1/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle2d_small_2_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_2/1.fasta", f2 = "../../../data/small/test_2/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle2d_small_3_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_3/1.fasta", f2 = "../../../data/small/test_3/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle2d_small_4_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_4/1.fasta", f2 = "../../../data/small/test_4/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

BENCHMARK(needle2d_small_1_bench);
// BENCHMARK(needle2d_small_2_bench);
// BENCHMARK(needle2d_small_3_bench);
// BENCHMARK(needle2d_small_4_bench);

/**
 * -----------------------------------------------------------------------------------------------------
 * 1D optimized N*M Needle Benchmarks
 * -----------------------------------------------------------------------------------------------------
 */

static void needle1d_small_1_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_1/1.fasta", f2 = "../../../data/small/test_1/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle_1d(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle1d_small_2_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_2/1.fasta", f2 = "../../../data/small/test_2/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle_1d(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle1d_small_3_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_3/1.fasta", f2 = "../../../data/small/test_3/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle_1d(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle1d_small_4_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_4/1.fasta", f2 = "../../../data/small/test_4/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle_1d(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

BENCHMARK(needle1d_small_1_bench);
BENCHMARK(needle1d_small_2_bench);
BENCHMARK(needle1d_small_3_bench);
// BENCHMARK(needle1d_small_4_bench);

/**
 * -----------------------------------------------------------------------------------------------------
 * 1D diagonal -> linear cache map optimized N*M Needle Benchmark
 * -----------------------------------------------------------------------------------------------------
 */

static void needle_diag_small_1_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_1/1.fasta", f2 = "../../../data/small/test_1/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle_diag_cache(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_small_2_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_2/1.fasta", f2 = "../../../data/small/test_2/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle_diag_cache(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_small_3_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_3/1.fasta", f2 = "../../../data/small/test_3/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle_diag_cache(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_small_4_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_4/1.fasta", f2 = "../../../data/small/test_4/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) readFASTA(f1, n);
    char *sequence2 = (char*) readFASTA(f2, m);
    int ans = needle_diag_cache(sequence1, n, sequence2, m, match, mismatch, gap);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

BENCHMARK(needle_diag_small_1_bench);
BENCHMARK(needle_diag_small_2_bench);
BENCHMARK(needle_diag_small_3_bench);
BENCHMARK(needle_diag_small_4_bench);

BENCHMARK_MAIN();