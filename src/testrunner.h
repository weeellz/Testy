#pragma once

typedef void (*testCase)(void);

typedef struct __TestNode{
    struct __TestNode *next;
    testCase test;
} TestNode;

typedef struct {
    TestNode *head;
} TestRunner;

TestRunner *allocTestRunner();

void destroyTestRunner(TestRunner *runner);

void addTestCase(TestRunner *runner, testCase test);

void run(TestRunner *runner);