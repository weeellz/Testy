#include <stdlib.h>
#include "testrunner.h"

TestRunner *allocTestRunner(){
    TestRunner *runner = malloc(sizeof(TestRunner));
    runner->head = NULL;
    return runner;
}

void destroyTestRunner(TestRunner *runner){
    TestNode *node = NULL;
    while(runner->head){
        node = runner->head;
        runner->head = node->next;
        free(node);
    }
    free(runner);
}

void addTestCase(TestRunner *runner, testCase test){
    TestNode *node = malloc(sizeof(TestNode));
    node->test = test;
    node->next = runner->head;
    runner->head = node;
}

void run(TestRunner *runner){
    TestNode *node = runner->head;
    while (node){
        node->test();
        node = node->next;
    }
}