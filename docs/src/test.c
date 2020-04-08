#include <emscripten.h>

void test(){

emscripten_run_script("alert('hi')");
}