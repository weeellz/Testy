/*!
 * @author fexolm 
 * @date 08.04.18.
 */

#include <Testy/testy.h>
#include <stdio.h>
#include <Testy/assert.h>

TESTY_CASE(test1) {
  printf("test1\n");
}

TESTY_CASE(test2) {
  testy_assert_double_lt(2.065, 2.064);
  printf("test2\n");
END_CASE
}

TESTY_CASE(test3) {
  testy_assert_int_eq(4, 4);
  printf("test3\n");
END_CASE
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
  testy_printErrorCount(runner);
  testy_destroyRunner(runner);
}
