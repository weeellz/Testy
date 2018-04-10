/*!
 * @author fexolm 
 * @date 08.04.18.
 *
 * @todo add doxygen comments
 */
#pragma once

#include <setjmp.h>
extern jmp_buf __tc_jmp_lbl;

#define TESTY_INIT jmp_buf __tc_jmp_lbl;

#define TESTY_CASE(name) void name(testy_Runner __tcrunner) { \
     int error = 0; \
     if(setjmp(__tc_jmp_lbl)) {  \
        error = 1;  \
        goto __testy_cleanup; \
     }


#define TEASTY_CLEANUP __testy_cleanup: if(error) __registerError(__tcrunner);

#define END_CASE  }

typedef struct __TestRunner *testy_Runner;

typedef void (*testy_function)(testy_Runner runner);

testy_Runner testy_allocRunner();

void testy_destroyRunner(testy_Runner runner);

void testy_addCase(testy_Runner runner, testy_function test);

void testy_run(testy_Runner runner);

void __registerError(testy_Runner runner);

int testy_errorCount(testy_Runner runner);