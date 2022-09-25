# numformat
c function to shorten number strings (i.e. 140520 -> 140k)

## usage
### standalone
For a standalone executable to use on the command-line, use `make standalone` and run the resulting executable.

### via include
See `exampleprog.c` for an example of integrating this function into your own project.
In summary:
```c
#include "numformat.h"
```
... then call the `numformat(long long unsigned x)` or `strnumformat(char* x)` functions in your program.
