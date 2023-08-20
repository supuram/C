/**
*! Line 140 - opt->inputfile = (char **)realloc(opt->inputfile, sizeof(char *) * inputfile_capacity); What is happening in this line ?
*? Ans)In the given line of code, a reallocation of memory is being performed for the `inputfile` array within the `opt` structure. Here's a breakdown of what's happening:

1. `opt->inputfile`: This refers to a dynamically allocated array of pointers to characters (strings). It likely holds the filenames or paths of input files.

*? 2. `realloc(opt->inputfile, sizeof(char *) * inputfile_capacity)`: The `realloc` function is used to resize the dynamically allocated memory block pointed to by `opt->inputfile`. The new size of the memory block is calculated as `sizeof(char *) * inputfile_capacity`.

   - `sizeof(char *)`: This is the size (in bytes) of a pointer to a character. It represents the size required to store an individual string in the array.
   
   - `inputfile_capacity`: This is the desired new capacity (number of elements) for the `inputfile` array.

3. `(char **)`: This is a typecast that ensures that the return value of `realloc` is interpreted as a pointer to a pointer to a character (i.e., a pointer to a string).

*? The purpose of this line of code is to resize the memory allocated for the `inputfile` array to accommodate a potentially larger number of input file names or paths. This resizing ensures that the array can hold the required number of elements without causing memory issues like buffer overflows or memory leaks.

*? After this line of code is executed, `opt->inputfile` will point to the new memory block with the adjusted size, and the contents of the old memory block will be copied to the new block if possible. If the reallocation fails (e.g., due to insufficient memory), `opt->inputfile` will remain unchanged, and you should check the return value of `realloc` to handle such cases properly.
*! -----------------------------------------------------------------------------------------------------------------
*! Line 1242- 1244 . Explain
#ifdef WIN32
	setmode(fileno(stdin), O_BINARY);
#endif 

*? Ans)The code you provided is using preprocessor directives to conditionally execute specific code depending on whether the program is being compiled on a Windows platform (`WIN32` defined) or not. Let's break it down step by step:

*? 1. `#ifdef WIN32`: This is a preprocessor directive that checks if the macro `WIN32` is defined. `WIN32` is often defined by default when compiling on Windows platforms. If it's defined, the code between `#ifdef` and `#endif` will be included during compilation.

*? 2. `setmode(fileno(stdin), O_BINARY);`: This code is attempting to set the mode of the standard input stream (`stdin`) to binary mode. This is relevant when working with binary files in Windows, as text mode and binary mode handle line-ending characters (`\n`) differently. In binary mode, line-ending characters are not automatically translated.

   - `fileno(stdin)` retrieves the file descriptor for the standard input stream.
   - `O_BINARY` is a constant that represents binary mode. It is typically used with functions that handle file modes, like the `setmode` function.

*? So, in summary, the code is checking if the program is being compiled on a Windows platform (`WIN32` is defined), and if so, it's setting the standard input stream (`stdin`) to binary mode using the `setmode` function. This is done to ensure consistent handling of binary data when reading from the standard input stream.

*! Is setmode predefined ?
*? Ans)The `setmode` function is not a standard C library function. It is a function provided by the Microsoft C Runtime Library (CRT) on Windows platforms. This function is used to set the file translation mode for file descriptors opened in text mode. Specifically, it's used to set the translation mode between text mode (`O_TEXT`) and binary mode (`O_BINARY`).

Here's the typical syntax of the `setmode` function:
int setmode(int filedes, int mode);
- `filedes`: The file descriptor for which you want to set the mode.
- `mode`: The mode you want to set, such as `O_TEXT` for text mode or `O_BINARY` for binary mode.

*? It's important to note that `setmode` is specific to Windows platforms and is not available on all systems. If you're writing cross-platform code, you might need to use conditional compilation directives like `#ifdef WIN32` to include or exclude code that uses `setmode` based on the platform you're targeting.

*! Is fileno predefined ?
*? Ans)`fileno` is a standard C library function. It's used to obtain the file descriptor associated with a `FILE` stream. In other words, it returns the integer file descriptor that corresponds to a `FILE` pointer. The file descriptor is an integer that is commonly used for low-level file operations, especially when working with system calls.

The typical syntax of the `fileno` function is as follows:

int fileno(FILE *stream);

- `stream`: A pointer to a `FILE` stream for which you want to obtain the file descriptor.

Here's a brief example of how `fileno` can be used:

#include <stdio.h>
#include <fcntl.h>  // Include for O_BINARY on Windows

int main() {
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int fd = fileno(fp);  // Get the file descriptor

#ifdef WIN32
    // Set the file to binary mode using setmode
    setmode(fd, O_BINARY);
#endif

    // Now you can use the file descriptor for low-level operations

    fclose(fp);
    return 0;
}

*? Keep in mind that `fileno` is part of the C standard library, so it's predefined and available on most systems that support the C programming language.

*! What is the meaning of integer file descriptor ? (Line 29 in this)
*? Ans)An integer file descriptor is a unique identifier assigned by the operating system to an open file or data stream. It's used to manage and track open files within a process. In Unix-like operating systems, including Linux, file descriptors are fundamental for performing I/O operations on files, sockets, pipes, and other input/output resources.

The concept of file descriptors stems from the Unix philosophy of treating all I/O as file operations. This abstraction allows different types of I/O resources, such as regular files, devices, and network sockets, to be treated uniformly using a consistent set of operations.

In Unix-based systems, three standard file descriptors are commonly used:

1. **Standard Input (stdin, file descriptor 0):** This file descriptor is associated with the input stream, typically the keyboard. Programs read data from this stream by default.

2. **Standard Output (stdout, file descriptor 1):** This file descriptor is associated with the output stream, typically the console or terminal. Programs write data to this stream by default.

3. **Standard Error (stderr, file descriptor 2):** This file descriptor is also associated with the output stream, specifically for error messages and diagnostics. It's separate from `stdout` to allow the separation of normal program output and error messages.

*? Additionally, non-negative integers greater than or equal to 3 are used to represent user-defined open files and resources, such as files opened using the `fopen` function, network sockets, and pipes. The operating system manages these integers and the corresponding resources behind the scenes.                                      Functions like `fileno` and system calls like `open` provide ways to obtain or create file descriptors. Once you have a file descriptor, you can use it with various system calls and library functions to perform read and write operations, manage file positions, and perform other I/O-related tasks.                                           In summary, an integer file descriptor is a unique identifier that the operating system uses to keep track of open files and I/O resources, enabling programs to interact with various types of data sources and sinks in a standardized way.

*! What is a file stream ?
*? Ans)A file stream is a concept used in programming to abstract the interaction with files, allowing you to perform input and output operations on files in a more convenient and unified way. In C programming, file streams are represented using the `FILE` data type, which is a structure defined in the standard library.

A file stream represents an open file and contains information about the file's status, current position, buffering, and other attributes. It provides a higher-level interface for reading from or writing to files, hiding many of the low-level details involved in file I/O.

Here are some of the commonly used file stream functions in C:

- `fopen`: Opens a file and returns a `FILE` pointer.
- `fclose`: Closes the file associated with a `FILE` pointer.
- `fprintf`, `fscanf`: Formatted input/output functions that work with files.
- `fputc`, `fgetc`: Writes and reads a single character to/from a file.
- `fgets`, `fputs`: Reads and writes a string from/to a file.
- `fwrite`, `fread`: Writes and reads binary data from/to a file.

Here's a simple example of using file streams to read and write text to a file:

#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "w"); // Open file for writing
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(fp, "Hello, world!\n"); // Write to the file

    fclose(fp); // Close the file

    fp = fopen("example.txt", "r"); // Open file for reading
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Read: %s", buffer); // Print the content read from the file
    }

    fclose(fp); // Close the file

    return 0;
}

*? In this example, `FILE *fp` represents a file stream associated with the file "example.txt." The functions `fprintf`, `fgets`, and `fclose` operate on this file stream. This abstraction simplifies working with files and allows you to perform input/output operations using a consistent interface.

*! setmode(fileno(stdin), O_BINARY); - So here the fileno gets the integer file descriptor of stdin. So say the user inputs - "My name is hulukuti" and the fileno sets some integer which is specific to the paticular sentence the user has entered ? And setmode will convert this particular sentence of the user , first by finding the corresponding integer value in the operating system and then converting that to binary ? Is this the case ?
*? Ans)`setmode(fileno(stdin), O_BINARY)` is a code snippet that is commonly used on Windows systems to change the mode of the standard input stream (`stdin`) to binary mode. This code is specific to Windows and addresses a difference in how text mode and binary mode are handled on Windows compared to Unix-like operating systems.

*? On Windows, text mode and binary mode affect how newline characters (`\n`) are handled in input and output streams. In text mode, newline characters are automatically converted between the Windows `\r\n` format and the Unix `\n` format. In binary mode, no such automatic conversion occurs, and data is read and written as-is.

Here's what the code does step by step:

1. `fileno(stdin)`: This function call returns the file descriptor associated with the standard input stream (`stdin`). A file descriptor is an integer value that represents an open file or stream in a program.

2. `setmode(...)`: This function sets the mode of the given file descriptor. The specific details of `setmode` may vary depending on the environment, but in this case, it's likely setting the mode to binary mode for the standard input stream.

3. `O_BINARY`: This is a constant that typically represents binary mode. It's a flag used to specify that the file should be treated as a binary file, meaning no newline conversions should be performed.

*? So, the code doesn't convert the user's input sentence to binary; rather, it modifies how newline characters are treated when reading from the standard input stream. The purpose of using `setmode` in this context is to ensure that newline characters are not automatically converted on Windows systems, as it might cause issues when reading or writing binary data.

Here's a simplified explanation:

- Text mode: Automatic newline conversion between different newline formats (`\n` to `\r\n` and vice versa) occurs.
- Binary mode: No automatic newline conversion occurs; data is read and written as-is.

*? This code is typically used when working with binary data or when you want to control newline handling explicitly. It's not about converting a specific sentence to binary; rather, it's about controlling how newline characters are handled in the input and output streams.

*! What is the meaning of - setting the mode to binary mode for the standard input stream ?
*? Ans)Setting the mode of a standard input stream (stdin) to binary mode means that when data is read from stdin, no automatic conversion of newline characters will occur. In other words, the content of the input will be treated as-is, without any modifications to newline characters.

In text mode, when data is read from stdin, the operating system may perform automatic newline character conversion. This means that if you read a file that contains newline characters in the Unix `\n` format (line feed), the operating system may automatically convert them to the Windows `\r\n` format (carriage return followed by line feed) or vice versa, based on the platform's newline conventions.

For example, consider a file with the following content:

Hello
World

In text mode, when this file is read, the operating system might convert the newline character `\n` to `\r\n` on Windows or vice versa on Unix-like systems.

*? However, in binary mode, no such automatic conversion takes place. Data is read exactly as it exists in the file, including newline characters. So, in the above example, if you read the file in binary mode, you would see the exact characters "Hello\nWorld\n".

*? Setting the standard input stream to binary mode can be useful when you want to handle binary data or text data with specific newline conventions. It ensures that the data is read exactly as it appears in the file, without any automatic transformations.

*? In the code snippet you provided (`setmode(fileno(stdin), O_BINARY)`), this operation is particularly important when working with binary data from the standard input stream, as the program wants to prevent any automatic newline character conversions that might occur in text mode.
*! -----------------------------------------------------------------------------------------------------------------

*! Line 1240 - if (strcmp(argv[i], "-") == 0 || strcmp(argv[i], "-stdin") == 0)                                 Here what is stdin ? Is it the user input and stdin holds that value ?
*? Ans)In C, `stdin` is a predefined file stream that represents the standard input stream. It is associated with the keyboard or another input source from which a program reads data. When you run a program from the command line, the standard input stream (`stdin`) is used to read input data that you provide.

In the code snippet you provided:
if (strcmp(argv[i], "-") == 0 || strcmp(argv[i], "-stdin") == 0)
{
    // ...
    opt->input_source = CCX_DS_STDIN;
    // ...
}

*? This code is checking whether the command-line argument `argv[i]` is equal to "-" or "-stdin". If either of these conditions is true, it means that the program should read input data from the standard input stream (`stdin`). The line `opt->input_source = CCX_DS_STDIN;` sets the `input_source` option to indicate that the program should read data from `stdin`.

*? By setting `opt->input_source` to `CCX_DS_STDIN`, the program will later recognize that it needs to read input data from the `stdin` stream. This is commonly used when a program is designed to process input either from a file or from standard input, allowing users to input data interactively via the keyboard or by redirecting input from a file.

*! So if the user uploads a .mp4 file it is a standard input stream ? 
*? Ans)No, when a user uploads a `.mp4` file, it is not considered a standard input stream (`stdin`). The term "standard input stream" (`stdin`) typically refers to the default input source for a program when it is run interactively from the command line.

When a user uploads a file, such as a `.mp4` file, the file is considered an external input file. The program can read data from this file by opening it and reading its contents. This is distinct from reading input interactively from the keyboard, which is what the standard input stream (`stdin`) is used for.

In the context of the code snippet you provided earlier, the program is checking whether the command-line argument corresponds to reading data from the standard input stream (`stdin`). If the user runs the program with the argument `-` or `-stdin`, it means the program should read data from `stdin`. If the user provides the name of a file as an argument, the program will read data from that file instead.

*! So the user actually types stdin ? Or the user enters the name of the file ?
*? Ans)In most cases, the user does not actually type the word "stdin" as an input. Instead, when the user wants to indicate that the program should read data from the standard input stream (`stdin`), they use a special symbol or command-line argument.

For example:
- If the user provides a hyphen `-` as a command-line argument, it's a convention in many command-line programs to interpret that as a request to read data from `stdin`.
- Similarly, some programs use a specific command-line argument like `-stdin` to indicate that the program should read data from `stdin`.

*? So, when you see code like `strcmp(argv[i], "-") == 0 || strcmp(argv[i], "-stdin") == 0`, it's checking whether the user provided either a hyphen or the specific command-line argument `-stdin`. If either of these conditions is met, the program knows to read data from the standard input stream (`stdin`). If the user provides the name of a file as an argument, the program reads data from that file instead.

*! When the user types stdin, from where will the code read the input stream - which file ? Because the user only entered stdin.
*? Ans)When the user specifies "stdin" as an input source, the code will read input data from the standard input stream (`stdin`), which is a fundamental concept in Unix-like operating systems. `stdin` is a predefined file descriptor that represents the standard input device, typically the keyboard or any other input source that provides data to the program.

When the user types something in the console and presses Enter, the entered text is sent to the program as input through the `stdin` stream. This is how interactive programs read user input from the command line. So, in the context of your code:

#ifdef WIN32
setmode(fileno(stdin), O_BINARY);
#endif
opt->input_source = CCX_DS_STDIN;

*? The code sets the input source to `CCX_DS_STDIN`, indicating that the program should read input data from the standard input stream. The `setmode` function with `O_BINARY` ensures that the standard input stream is treated as binary data, which can be important for programs that handle non-textual data.

*? To provide input via `stdin`, the user would typically run the program and then type or paste the desired input into the console. The program will then read that input from `stdin` and process it accordingly.
*! -----------------------------------------------------------------------------------------------------------------
*/