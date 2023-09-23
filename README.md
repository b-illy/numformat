# numformat
numformat is a C library implementing a set of functions to shorten integers and integer strings into a more readable format (140000 -> 140k, 123456789 -> 123m etc.).

## Usage
There are several different ways to make use of this library. There is a `Makefile` with several examples which is commented and briefly explains what each task does, but here is a more in-depth explanation:

### Standalone program
For a standalone executable to use on its own, use `make standalone` and run the resulting executable. This uses a basic single-file solution that implements the library functions and wraps them for use on a command-line interface, functioning mostly as a demo.

### Via include
`exampleprog.c` is an example of how you may write a C program on top of this library to integrate the functions into your own project. Here it is done by statically compiling together using `#include "numformat.h"` in your C source file. See `make include` for an example of how to compile this way.
```c
#include "numformat.h"

int main() {
  // your code here...
  numformat(12345);
  strnumformat("12345");
  // ... more code
}
```

### As a shared object (.so file)
As with any other library that you may want to use system-wide, you can use numformat as a shared object file and have many programs link to it at use it at runtime. To do this, run `make lib` to compile to a .so file. You can then also use `make link` to compile the same `exampleprog.c` source file from before but have it link to the library dynamically instead of statically.
