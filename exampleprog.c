#include <stdio.h>
#include "numformat.h"

int main(int argc, char** argv) {
    printf("This is an example program using numformat via include\n");
    long long unsigned input = 104;
    printf("Input: %llu\n", input);
    printf("Output: %s\n", numformat(input));

    return 0;
}
