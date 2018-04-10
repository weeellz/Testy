/*!
 * @author fexolm 
 * @date 08.04.18.
 *
 * @todo add doxygen comments
 */
#pragma once

#define TESTY_CASE(name) void name(testy_Runner __tcrunner)

#define END_CASE return; on_error: __registerError(__tcrunner);

typedef struct __TestRunner *testy_Runner;

typedef void (*testy_function)(testy_Runner runner);

testy_Runner testy_allocRunner();

void testy_destroyRunner(testy_Runner runner);

void testy_addCase(testy_Runner runner, testy_function test);

void testy_run(testy_Runner runner);

void __registerError(testy_Runner runner);

void testy_printErrorCount(testy_Runner runner);