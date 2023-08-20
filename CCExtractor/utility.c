/**
*! Line 495 - 521. See 11_Pointer_char.c in my personal folder for demo
*! strcpy 
*? Yes, `strcpy` is a predefined function in the C programming language. It is part of the C standard library (string.h header) and is used to copy the contents of one string to another string, including the null-terminator character.

Here's the basic syntax of the `strcpy` function:

#include <string.h>
char *strcpy(char *destination, const char *source);

- `destination` is a pointer to the destination buffer where the copied string will be stored. The destination buffer must be large enough to accommodate the source string.
- `source` is a pointer to the null-terminated string that you want to copy.

The function returns a pointer to the destination buffer (`destination`), which now contains the copied string.

Here's an example usage:

#include <stdio.h>
#include <string.h>

int main() {
    const char *source = "Hello, world!";
    char destination[20]; // Make sure the buffer is large enough to hold the source string

    strcpy(destination, source);

    printf("Source:      %s\n", source);
    printf("Destination: %s\n", destination);
    
    return 0;
}

Keep in mind that you need to ensure that the destination buffer is large enough to hold the contents of the source string along with the null-terminator. If the destination buffer is not large enough, it can lead to buffer overflows and undefined behavior.

*! The function returns a pointer to the destination buffer - this means what ?? So the destination will hold the address of the first character of the string
*? Ans)Yes, that's correct. When you use the `strcpy` function, it returns a pointer to the destination buffer. This returned pointer is the same as the `destination` pointer you passed as the first argument to the function.

In other words, the `destination` pointer points to the beginning of the destination buffer where the string was copied. This behavior allows you to continue working with the copied string if needed.

Here's an example to illustrate this:

#include <stdio.h>
#include <string.h>

int main() {
    const char *source = "Hello, world!";
    char destination[20]; // Make sure the buffer is large enough to hold the source string

    char *result = strcpy(destination, source);

    printf("Source:      %s\n", source);
    printf("Destination: %s\n", destination);
    
    printf("Result:      %s\n", result); // Same as destination
    
    return 0;
}
In this example, the `result` pointer will point to the same memory location as the `destination` pointer, because `strcpy` returns the `destination` pointer. Both `result` and `destination` point to the beginning of the copied string in the `destination` buffer.

*! is basefilename + len a number ? 
*? Ans)basefilename + len is not a number, but rather a pointer expression that points to a memory location in your string buffer. It's the address of the memory location that is calculated by adding the length of the string (len) to the base address of the basefilename pointer.

*! c > basefilename means what ? Both c and basefilename are pointers. How can you check which pointer is greater than the other as pointers point to memory location ?
*? Ans)In the context of C programming, when you compare two pointers using the `>` operator, you are actually comparing their memory addresses. The comparison is based on the memory layout of your system. If `c` and `basefilename` are pointers to elements in the same array or block of memory, then comparing them with `>` can determine their relative positions in memory.
In the loop you provided:
for (c = basefilename + len; c > basefilename && *c != '.'; c--)
{
    ;
}

`c` is initialized to point to the end of the `basefilename` string (i.e., the memory location of the null-terminator). `basefilename` is a pointer to the beginning of the string.

During each iteration of the loop, `c` is decremented to move to the previous character in memory. The loop continues as long as `c` is greater than `basefilename` (i.e., there are more characters to process) and the character pointed to by `c` is not a period `'.'`.

The comparison `c > basefilename` is valid because it's comparing the memory addresses pointed to by `c` and `basefilename`. It's important to note that the loop is using pointer arithmetic and memory addresses to iterate through the characters in the string, rather than numerical values.

Remember that in this context, `>` is comparing the memory addresses, not the characters themselves.

*! So if example.txt is passed in get_basename, at the end of the loop, c points to the '.' and then is set to 0. But how come basefilename becomes only example ?
*? Ans)The loop in the `get_basename` function is designed to truncate the string stored in `basefilename` by removing the file extension (everything after the last dot `'.'`). Let's break down how this works step by step:  1. The input filename, such as "example.txt," is copied into the dynamically allocated memory of `basefilename`.  2. The loop starts with `c` pointing to the end of the `basefilename` string (i.e., the null-terminator `'\0'` that indicates the end of the string).                                                                                 3. The loop condition `c > basefilename && *c != '.'` ensures that the loop will run as long as `c` points to a character that is not a dot `'.'`, and as long as `c` is still within the bounds of the `basefilename` string (i.e., greater than `basefilename`).                                                                                 4. The loop decrements `c` to move it backward through the string, character by character.                        5. When `c` points to the dot `'.'`, the loop terminates because the condition `*c != '.'` becomes `false`.       6. If the loop terminated due to encountering a dot `'.'`, the dot is replaced with a null-terminator `'\0'` to effectively truncate the string at that point. This removes everything from the dot onwards.

As a result, after the loop, the memory contents pointed to by `basefilename` are modified, and the string is effectively truncated to remove the file extension. For example, if the input was "example.txt," after the loop, the memory contents pointed to by `basefilename` would become "example\0" (where `\0` represents the null-terminator).

*? So, in the end, `basefilename` holds the address of the first character of the modified string "example\0," and printing it using `%s` in a `printf` statement will display "example." The null-terminator indicates the end of the string in C, so the string functions know where the string ends.
*/