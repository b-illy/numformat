#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>


int main(int argc, char** argv) {
    if (argc != 2) {
        printf("ERROR: program requires exactly one input argument.\n");
        return 100;
    }

    long long unsigned value;

    // attempt to cast input arg to long long unsigned and store result in "value"
    if (sscanf(argv[1], "%llu", &value) == 1) {
        if (value >= ULLONG_MAX) {
            printf("ERROR: inputted argument too large for long long unsigned.\n");
            return 102;
        }

        // re-parse as string to ensure no leading zeros, decimals, etc.
        char valueString[64];
        sprintf(valueString, "%llu", value); // (ignoring return value)

        // now we can get strlen which represents digit count
        unsigned length = strlen(valueString);

        // use digit count (length) to determine "magnitude"
        // i.e. 1,000,000 -> 2, 100,000,000 -> 2, 1,000 -> 1, 500 -> 0, etc.
        unsigned magnitude = (length - 1) / 3;

        // identify correct suffix
        char suffixes[] = {'k', 'm', 'b', 't', 'q'};

        if (magnitude > (sizeof(suffixes)/sizeof(suffixes[0]))) {
            printf("ERROR: number too large to have any supported suffix.\n");
            return 103;
        }

        char suffix = '\x00';
        if (magnitude != 0) {
            suffix = suffixes[magnitude - 1];
        }

        // dont apply suffix if one doesnt exist
        if (suffix != '\x00') {
            // extract the first digits to trim off all the others
            unsigned firstDigits = value / pow(10, magnitude * 3);
            printf("%u%c\n", firstDigits, suffix);
        } else {
            printf("%llu\n", value);
        }

    } else {
        printf("ERROR: inputted argument unable to be parsed as long long unsigned.\n");
        return 101;
    }

    return 0;
}
