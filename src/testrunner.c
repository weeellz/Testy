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
#include <testy.h>

typedef struct __TestNode {
  struct __TestNode *next;
  testy_function test;
} TestNode;

struct __TestRunner {
  TestNode *head;
};

testy_Runner testy_allocRunner() {
  testy_Runner runner = malloc(sizeof(struct __TestRunner));
  runner->head = NULL;
  return runner;
}

void testy_destoyRunner(testy_Runner runner) {
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
}

void testy_run(testy_Runner runner) {
  TestNode *node = runner->head;
  while (node) {
    node->test(runner);
    node = node->next;
  }
}