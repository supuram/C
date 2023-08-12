/* 
In C and C++ programming languages, defined is not a function or a keyword in the same sense as other constructs like variables or functions. Instead, it is a preprocessor directive used for conditional compilation.

The defined directive is used with #if, #elif, and #ifdef directives to check if a macro is defined. It allows you to conditionally include or exclude portions of code during the preprocessing phase before actual compilation. It is commonly used for creating platform-specific or configuration-dependent code.
*/

#include <stdio.h>

#define ENABLE_FEATURE_A
#define _WIN32

int main() {
#ifdef ENABLE_FEATURE_A
    printf("Feature A is enabled.\n");
#endif

#if defined(ENABLE_FEATURE_A) && defined(_WIN32)
    printf("Both Feature A and Windows platform are enabled.\n");
#endif

    return 0;
}

/*
In this example, ENABLE_FEATURE_A and _WIN32 are defined using #define. The #ifdef directive checks if ENABLE_FEATURE_A is defined, and the #if defined(ENABLE_FEATURE_A) && defined(_WIN32) directive checks if both ENABLE_FEATURE_A and _WIN32 are defined before including or excluding the associated code.
*/