/*!
 * @author fexolm 
 * @date 08.04.18.
 */

#include <testy.h>
#include <stdio.h>
#include <assert.h>

TESTY_CASE(test1) {
  printf("test1\n");
}

TESTY_CASE(test2) {
  testy_assert_double_lt(2.063, 2.045);
  printf("test2\n");
}

TESTY_CASE(test3) {
  printf("test3\n");
}

TESTY_CASE(test4) {
  printf("test4\n");
}

int main() {
  testy_Runner runner = testy_allocRunner();
  testy_addCase(runner, test1);
  testy_addCase(runner, test2);
  testy_addCase(runner, test3);
  testy_addCase(runner, test4);
  testy_run(runner);
  testy_destoyRunner(runner);
}
