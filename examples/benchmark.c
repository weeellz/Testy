/*!
 * @author fexolm 
 * @date 12.08.18.
 */
#include <Testy/benchmark.h>
#include <stdio.h>
#include <unistd.h>
TESTY_BENCHMARK(bench1)
  sleep(1);
TESTY_BENCHMARK_END

int main() {
  testy_BenchmarkResult res = bench1(3);
  printf("max: %lf\nmin: %lf\nmean: %lf\n", res.max, res.min, res.mean);
}
