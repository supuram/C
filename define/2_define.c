/*
Q)What is a preprocessor directive?
Ans)A preprocessor directive is a command in C and C++ programming languages that instructs the preprocessor to perform specific actions before the actual compilation of the source code begins. The preprocessor is a tool that processes the source code before it's passed to the compiler, and it handles tasks like macro expansion, file inclusion, and conditional compilation.

Preprocessor directives are denoted by a `#` symbol at the beginning of a line and are not considered part of the regular C/C++ syntax. They are processed before the code is compiled, and their purpose is to modify or manipulate the source code before the compiler analyzes it.

Some common preprocessor directives include:

1. `#include`: Used to include the content of another file (usually a header file) in the current source code file.

2. `#define`: Used to define macros, which are symbolic names representing values or code fragments. These macros can be replaced with their corresponding values during preprocessing.

3. `#ifdef`, `#ifndef`, `#else`, `#elif`, and `#endif`: Used for conditional compilation. Code blocks within these directives are included or excluded based on certain conditions or the definition of macros.

4. `#pragma`: A compiler-specific directive used to provide hints or instructions to the compiler about various aspects of code generation or behavior.

5. `#error` and `#warning`: Used to generate error or warning messages during preprocessing. These directives can be used to ensure certain conditions are met or to provide informative messages.

6. `#undef`: Used to undefine a previously defined macro.

Here's a simple example of using some preprocessor directives - 
*/

#include <stdio.h>

#define DEBUG

int main() {
#ifdef DEBUG
    printf("Debugging is enabled.\n");
#else
    printf("Debugging is disabled.\n");
#endif

    return 0;
}

/*
In this example, the `#include` directive is used to include the standard input/output header file. The `#define` directive defines a macro named `DEBUG`. The `#ifdef` and `#else` directives are used to conditionally include different code based on whether the `DEBUG` macro is defined.

Preprocessor directives provide powerful tools for creating adaptable and configurable code, allowing you to customize the behavior of your program based on various conditions or configurations.
*/