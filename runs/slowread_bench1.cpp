#include <benchmark/benchmark.h>
#include <utils.h>
#include <needle.h>
#include <sys/mman.h>

// #define VERIF

/**
 * -----------------------------------------------------------------------------------------------------
 * Standard 2D N*M Needle Benchmarks
 * -----------------------------------------------------------------------------------------------------
 */
static void needle2d_small_1_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_1/1.fasta", f2 = "../../../data/small/test_1/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m, f1_off, f2_off;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle2d_small_2_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_2/1.fasta", f2 = "../../../data/small/test_2/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle2d_small_3_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_3/1.fasta", f2 = "../../../data/small/test_3/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle2d_small_4_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_4/1.fasta", f2 = "../../../data/small/test_4/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

BENCHMARK(needle2d_small_1_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle2d_small_2_bench)->Unit(benchmark::kMillisecond);
// BENCHMARK(needle2d_small_3_bench)->Unit(benchmark::kMillisecond);
// BENCHMARK(needle2d_small_4_bench)->Unit(benchmark::kMillisecond);

/**
 * -----------------------------------------------------------------------------------------------------
 * 1D optimized N*M Needle Benchmarks
 * -----------------------------------------------------------------------------------------------------
 */

static void needle1d_small_1_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_1/1.fasta", f2 = "../../../data/small/test_1/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_1d(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle1d_small_2_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_2/1.fasta", f2 = "../../../data/small/test_2/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_1d(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle1d_small_3_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_3/1.fasta", f2 = "../../../data/small/test_3/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_1d(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle1d_small_4_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_4/1.fasta", f2 = "../../../data/small/test_4/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_1d(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

BENCHMARK(needle1d_small_1_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle1d_small_2_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle1d_small_3_bench)->Unit(benchmark::kMillisecond);
// BENCHMARK(needle1d_small_4_bench)->Unit(benchmark::kMillisecond);

/**
 * -----------------------------------------------------------------------------------------------------
 * 1D diagonal -> linear cache map optimized N*M Needle Benchmark
 * -----------------------------------------------------------------------------------------------------
 */

static void needle_diag_small_1_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_1/1.fasta", f2 = "../../../data/small/test_1/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_cache(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_small_2_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_2/1.fasta", f2 = "../../../data/small/test_2/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_cache(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_small_3_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_3/1.fasta", f2 = "../../../data/small/test_3/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_cache(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_small_4_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_4/1.fasta", f2 = "../../../data/small/test_4/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_cache(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

BENCHMARK(needle_diag_small_1_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle_diag_small_2_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle_diag_small_3_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle_diag_small_4_bench)->Unit(benchmark::kMillisecond);

/**
 * -----------------------------------------------------------------------------------------------------
 * 1D diagonal -> linear + parallel optimized N*M Needle Benchmark
 * -----------------------------------------------------------------------------------------------------
 */

static void needle_diag_par_small_1_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_1/1.fasta", f2 = "../../../data/small/test_1/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_par(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_par_small_2_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_2/1.fasta", f2 = "../../../data/small/test_2/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_par(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_par_small_3_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_3/1.fasta", f2 = "../../../data/small/test_3/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_par(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_par_small_4_bench(benchmark::State& state) {
  std::string f1 = "../../../data/small/test_4/1.fasta", f2 = "../../../data/small/test_4/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_par(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

static void needle_diag_par_medium_bench(benchmark::State& state) {
  std::string f1 = "../../../data/medium/1.fasta", f2 = "../../../data/medium/2.fasta";
  int match = 1, mismatch = -2, gap = -1;
  size_t f1_size = get_file_size(f1), f2_size = get_file_size(f2);
  for (auto _ : state){
    int n, m;
    char *sequence1 = (char*) slowReadFASTA(f1, n, f1_size);
    char *sequence2 = (char*) slowReadFASTA(f2, m, f2_size);
    int ans = needle_diag_par(sequence1, n, sequence2, m, match, mismatch, gap);
    free(sequence1);
    free(sequence2);
    #ifdef VERIF
      std::cout<<ans<<std::endl;
    #endif
  }
}

// BENCHMARK(needle_diag_par_medium_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle_diag_par_small_1_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle_diag_par_small_2_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle_diag_par_small_3_bench)->Unit(benchmark::kMillisecond);
BENCHMARK(needle_diag_par_small_4_bench)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();