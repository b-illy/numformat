#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

char* numformat(long long unsigned input) {
    // re-parse as string to ensure no leading zeros, decimals, etc.
    char valueString[64];
    sprintf(valueString, "%llu", input); // (ignoring return value)

    // now we can get strlen which represents digit count
    unsigned length = strlen(valueString);

    // use digit count (length) to determine "magnitude"
    // i.e. 1,000,000 -> 2, 100,000,000 -> 2, 1,000 -> 1, 500 -> 0, etc.
    unsigned magnitude = (length - 1) / 3;

    // identify correct suffix
    char suffixes[] = {'k', 'm', 'b', 't', 'q'};

    if (magnitude > (sizeof(suffixes)/sizeof(suffixes[0]))) {
        printf("ERROR: number too large to have any supported suffix.\n");
        exit(103);
    }

    char suffix = '\x00';
    if (magnitude != 0) {
        suffix = suffixes[magnitude - 1];
    }

    // note: this must be allocated on the heap, stack (local) variables are destroyed on function return
    char* output = malloc(sizeof(char) * 64);

    // dont apply suffix if one doesnt exist
    if (suffix != '\x00') {
        // extract the first digits to trim off all the others
        unsigned firstDigits = input / pow(10, magnitude * 3);
        sprintf(output, "%u%c", firstDigits, suffix);
    } else {
        sprintf(output, "%llu", input);
    }

    return output;
}


char* strnumformat(char* input) {
    long long unsigned value;

    // attempt to cast input arg to long long unsigned and store result in "value"
    if (sscanf(input, "%llu", &value) == 1) {
        if (value >= ULLONG_MAX) {
            printf("ERROR: inputted argument too large for long long unsigned.\n");
            exit(102);
        }

        return numformat(value);

    } else {
        printf("ERROR: inputted argument unable to be parsed as long long unsigned.\n");
        exit(101);
    }
}
