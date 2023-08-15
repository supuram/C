// See ccx_decoders_xds.c in CCExtractor

#include <stdio.h>

int main(){
    static const char *XDSclasses[] =
    {
        "Current",
        "Future",
        "Channel",
        "Miscellaneous",
        "Public service",
        "Reserved",
        "Private data",
        "End"
    };
    for (int i = 0; i < sizeof(XDSclasses) / sizeof(XDSclasses[0]); i++) {
        printf("Value at index %d is %s and its address is %p and the address of the pointer XDSclasses[i] is stored in %p\n", i, XDSclasses[i], (void *)XDSclasses[i], &XDSclasses[i]);
    }

    return 0;
}

/*
Q)If XDSclasses is an array of pointers then it has addresses in its array. then where do the string literals reside ?
Ans)String literals in C are stored in a region of memory known as the "data segment" or "read-only data segment." When you define a string literal like `"Current"` or `"Future"` in your code, the compiler places these literals in a dedicated section of memory that is separate from the stack or heap.

Here's how it works:

1. String literals are stored in a read-only section of memory to ensure their immutability. This means you cannot modify the content of a string literal at runtime.

2. When you define an array of pointers like `static const char *XDSclasses[]`, each element of this array holds the address of a string literal.

3. The pointers in the `XDSclasses` array point to the memory locations where the string literals are stored, typically in the data segment.

So, in your code, the `XDSclasses` array contains pointers, and these pointers point to the memory locations where the string literals `"Current"`, `"Future"`, and so on, are stored.

For example:
- `XDSclasses[0]` points to the memory location where `"Current"` is stored.
- `XDSclasses[1]` points to the memory location where `"Future"` is stored.
- And so on for the rest of the elements.

To summarize, the `XDSclasses` array contains pointers to the memory locations of the string literals, and the string literals themselves are stored in a separate read-only data segment of memory.
------------------------------------------------------------------------------------------------------------
In C, the expression &XDSclasses[i] and (void *)XDSclasses[i] have different meanings and do not necessarily represent the same value.

&XDSclasses[i]: This expression takes the address of the i-th element in the array XDSclasses. The result is a pointer to a pointer to a string (const char **). It refers to the memory location where the pointer XDSclasses[i] is stored.

(void *)XDSclasses[i]: This expression casts the pointer XDSclasses[i] to a void* type, which can be used to print the address of the string pointed to by XDSclasses[i]. The result is a pointer to the actual string data (const char *).

So, while both expressions involve pointers, they point to different memory locations:

&XDSclasses[i] points to the memory location where the pointer XDSclasses[i] is stored.
(void *)XDSclasses[i] points to the memory location where the string pointed to by XDSclasses[i] is stored.
*/

/*
In the provided code snippet, `XDSclasses` is not a pointer that directly points to a variable. Instead, it is an array of pointers to constant strings (`const char *`). Each element of the array is a string literal, and `XDSclasses` itself is an array of pointers to these string literals.

Here's how it works:

1. `const char *XDSclasses[]` declares an array of pointers to constant characters (strings).

2. The array `XDSclasses` contains elements, each of which is a pointer to a constant string. The strings are defined within the curly braces `{}`.

3. Each element in the array is a string literal (e.g., `"Current"`, `"Future"`, etc.). These string literals are stored in a read-only section of memory, and the pointers in the `XDSclasses` array point to these locations.

So, `XDSclasses` itself is not a pointer to a single variable; it's an array of pointers to strings. Each element in the array points to one of the string literals. For example, `XDSclasses[0]` points to the string `"Current"`, `XDSclasses[1]` points to the string `"Future"`, and so on.
*/