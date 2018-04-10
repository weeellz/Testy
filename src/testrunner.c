/*!
 * @authors
 * Ravil Bikbulatov
 * fexolm
 *
 * @date 08.04.18.
 *
 * @todo reverse test order
 */

#include <stdlib.h>
#include <stdio.h>
#include <testy.h>

int countTests = 0;

typedef struct __TestNode {
  struct __TestNode *next;
  testy_function test;
} TestNode;

struct __TestRunner {
  TestNode *head;
  int error_count;
};

testy_Runner testy_allocRunner() {
  testy_Runner runner = malloc(sizeof(struct __TestRunner));
  runner->head = NULL;
  runner->error_count = 0;
  return runner;
}

void testy_destroyRunner(testy_Runner runner) {
  TestNode *node = NULL;
  while (runner->head) {
    node = runner->head;
    runner->head = node->next;
    free(node);
  }
  free(runner);
}

void testy_addCase(testy_Runner runner, testy_function test) {
  TestNode *node = malloc(sizeof(TestNode));
  node->test = test;
  node->next = runner->head;
  runner->head = node;
  countTests++;
}

void testy_run(testy_Runner runner) {
  TestNode *node = runner->head;
  while (node) {
    node->test(runner);
    node = node->next;
  }
}

void __registerError(testy_Runner runner){
  runner->error_count++;
}

void testy_printErrorCount(testy_Runner runner){
  printf("Tests: %d, Passed: %d, Failed: %d", countTests, (countTests-runner->error_count),runner->error_count);
}