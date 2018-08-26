#include <sys/time.h>
#include <sys/resource.h>

double get_time()
{
  struct timeval t;
  struct timezone tzp;
  gettimeofday(&t, &tzp);
  return t.tv_sec + t.tv_usec*1e-6;
}

typedef struct {
  double min;
  double max;
  double mean;
} testy_BenchmarkResult;

#define TESTY_BENCHMARK(name)                               \
  testy_BenchmarkResult name(int testy_bench_count) {       \
    testy_BenchmarkResult res;                              \
    res.max = 0;                                            \
    res.min = 999999999;                                    \
    res.mean = 0;                                           \
    for(int testy_iter = 0;                                 \
            testy_iter < testy_bench_count;                 \
            ++testy_iter) {                                 \
    double testy_timer = get_time();

#define TESTY_BENCHMARK_END                                             \
      double testy_endtimer = get_time();                               \
      double diff = (testy_endtimer - testy_timer);                     \
      res.mean += diff;                                                 \
      res.max = res.max > diff ? res.max : diff;                        \
      res.min = res.min < diff ? res.min : diff;                        \
    }                                                                   \
    res.mean /= testy_bench_count;                                      \
    return res;                                                         \
  }
