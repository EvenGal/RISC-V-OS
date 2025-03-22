#include <assert.h>
#include <string.h>

int main() {
    assert(strcmp("hello", "hello") == 0);
    assert(strcmp("abc", "def") < 0);
    assert(strcmp("def", "abc") > 0);
    return 0;
}

