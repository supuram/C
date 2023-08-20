/**
*! Line 59 
*! if (!ctx->inputfile || !ctx->inputfile[0]){} | Why here again we have written  !ctx->inputfile[0] as  !ctx->inputfile also points to the first character of the string. Then whats the difference between the two ?
*? Ans)In the code snippet `if (!ctx->inputfile || !ctx->inputfile[0])`, `ctx->inputfile` is a pointer to an array of strings, and `ctx->inputfile[0]` is a pointer to the first string (character array) in that array. The condition is checking two things:

1. `!ctx->inputfile`: This checks whether `ctx->inputfile` is a null pointer (i.e., it hasn't been allocated any memory or initialized). If it's null, this part of the condition evaluates to true.

2. `!ctx->inputfile[0]`: This checks whether the first string pointed to by `ctx->inputfile` is an empty string (i.e., the first character of the string is the null-terminator `\0`). If it's empty, this part of the condition evaluates to true.

These two conditions are combined using the logical OR operator `||`. The entire condition `if (!ctx->inputfile || !ctx->inputfile[0])` evaluates to true if either of the two conditions is true:

- If `ctx->inputfile` is null (not allocated or initialized), the condition is true.
- If the first string pointed to by `ctx->inputfile` is empty (null-terminated at the first character), the condition is true.

*? The code is using this condition to check whether the `ctx->inputfile` array is not allocated or doesn't contain any valid strings, implying that there are no input file names provided. If either of these conditions is true, it suggests that there are no input files to process, and the code takes appropriate action based on that information.

*! Line 46 - 81 - the function returns 0 when it successfully initializes the basefilename field in the context structure. If there's any error in the initialization process, it returns -1 to indicate the error.
==================================================================================================================
*! ccx_common_logging.debug_ftn = &dbg_print; - address of dbg_print function is stored in pointer debug_ftn

The debug_ftn field is defined as a function pointer that matches the signature of the dbg_print function. This allows you to later use the debug_ftn function pointer to call the dbg_print function indirectly through the ccx_common_logging structure.

This kind of setup allows you to customize the behavior of the logging functions at runtime by assigning different functions to these function pointers. It's a way of providing flexibility and allowing different logging implementations to be used without having to modify the code that calls these logging functions.
-------------------------------------------------------------------------------------------------------------------
*! Lines 105, 106
struct lib_ccx_ctx *ctx = malloc(sizeof(struct lib_ccx_ctx));
	if (!ctx){.....}
Here already ctx has been defined in struct lib_ccx_ctx *ctx. Why then again write if(!ctx). this is always false?

Ans)if (!ctx): This if statement checks if the value of ctx is NULL. In C, when malloc fails to allocate memory (due to insufficient memory), it returns NULL.
------------------------------------------------------------------------------------------------------------------
*! we have 
void(*fatal_ftn) (int exit_code, const char *fmt, ...);  
	ccx_common_logging.fatal_ftn = &fatal;
if (!ctx)
		ccx_common_logging.fatal_ftn(EXIT_NOT_ENOUGH_MEMORY, "init_libraries: Not enough memory allocating lib_ccx_ctx context.");

*! So how can you pass init_libraries: Not enough memory allocating lib_ccx_ctx context. inside fatal_ftn as the second argument as inside fatal_ftn is const char *fmt which is character pointer  type ? So what you pass should also be a pointer ?

*? Ans)You're absolutely correct. The `fatal_ftn` function pointer expects a `const char *fmt` parameter for the format string, which means that you should indeed pass a pointer to the string `"init_libraries: Not enough memory allocating lib_ccx_ctx context."` in order to match the expected argument type.

In the code you provided - The `fatal_ftn` function pointer is expected to match a function with the signature `void(int, const char *, ...)`, which means it takes an integer and a format string followed by variable arguments.

*? When you call `ccx_common_logging.fatal_ftn`, you are indeed passing the format string `"init_libraries: Not enough memory allocating lib_ccx_ctx context."` as a pointer to a character array. This is perfectly fine because in C, string literals like `"init_libraries: Not enough memory allocating lib_ccx_ctx context."` are automatically treated as pointers to the first character of the string.

So, the string literal itself is passed as a pointer, and there is no issue with the `const char *fmt` parameter type in the `fatal_ftn` function pointer.
-------------------------------------------------------------------------------------------------------------------
*! Yes, `memset` is a predefined function in C. It is part of the C Standard Library and is used to set a block of memory to a specific value, typically zero.

The `memset` function is typically declared in the `<string.h>` header file, and its signature is:

void *memset(void *ptr, int value, size_t num);

- `ptr`: A pointer to the memory block to be filled.
- `value`: The value to be set. It is usually of type `int` and is cast to `unsigned char` internally.
- `num`: The number of bytes to be set.

The `memset` function is commonly used to initialize structures, arrays, or dynamically allocated memory to a specific value, often zero, which can be useful to ensure that memory is in a known state.

For example, in your code snippet:
memset(ctx, 0, sizeof(struct lib_ccx_ctx));
You are using `memset` to set the memory block pointed to by `ctx` (a pointer to `struct lib_ccx_ctx`) to all zeros, effectively initializing the memory to a default state before using it.
-------------------------------------------------------------------------------------------------------------------
*! ctx->epg_buffers = (struct PSI_buffer *)malloc(sizeof(struct PSI_buffer) * (0xfff + 1)); Meaning of the above line.

*? Ans)ctx->epg_buffers = (struct PSI_buffer *)malloc(sizeof(struct PSI_buffer) * (0xfff + 1)); This line is allocating memory dynamically using the `malloc` function to create an array of `struct PSI_buffer` structures and assigning the address of the allocated memory to the `epg_buffers` pointer inside the `ctx` structure.

Here's what's happening step by step:

1. `(0xfff + 1)` calculates the number of elements you want in the array. In this case, it's `(0xfff + 1)`, which is 4096. You're adding 1 to 0xfff (which is 4095 in hexadecimal) to get a total of 4096 elements.

2. `sizeof(struct PSI_buffer)` calculates the size, in bytes, of a single `struct PSI_buffer` structure.

3. `sizeof(struct PSI_buffer) * (0xfff + 1)` calculates the total size, in bytes, needed for the entire array of `struct PSI_buffer` structures.

4. `malloc(sizeof(struct PSI_buffer) * (0xfff + 1))` allocates memory of the calculated size. This dynamically allocated memory will be able to hold an array of `struct PSI_buffer` structures.

5. `(struct PSI_buffer *)` is casting the result of `malloc` to a pointer of type `struct PSI_buffer *`. This is necessary because `malloc` returns a `void *` (generic pointer) which needs to be explicitly cast to the correct pointer type.

6. Finally, `ctx->epg_buffers` is assigned the address of the dynamically allocated memory. This updates the `epg_buffers` pointer in the `ctx` structure to point to the beginning of the allocated memory block, effectively creating an array of `struct PSI_buffer` structures.

This code allocates memory for an array of `struct PSI_buffer` structures with a size of 4096 elements and updates the `epg_buffers` pointer in the `ctx` structure to point to this memory. Each element of the array will be of type `struct PSI_buffer`, as defined in your provided code snippet.

*? When you allocate memory using the malloc function in C, it returns a pointer of type void *. This is a generic pointer type that doesn't have any specific type information associated with it. However, when you're working with that allocated memory, you often want to treat it as a specific type, such as a structure or an array of structures.

*? The expression (struct PSI_buffer *) is used to explicitly cast (convert) the void * pointer returned by malloc into a pointer of type struct PSI_buffer *. This cast informs the compiler that you intend to treat the allocated memory as an array of struct PSI_buffer structures.

*! Line 117 - ctx->epg_buffers = (struct PSI_buffer *)malloc(sizeof(struct PSI_buffer) * (0xfff + 1));          memset(ctx->epg_buffers, 0, sizeof(struct PSI_buffer) * (0xfff + 1));                                              Here , why do we need to write ctx->epg_buffers inside memset . We could have written just epg_buffers as it is a pointer and will point to the memory designated in memset ?
*? Ans)In the code snippet you provided, it seems like you are allocating and initializing memory for an array of `struct PSI_buffer` using dynamic memory allocation (`malloc`) and then initializing the allocated memory to zero using `memset`.

When you allocate memory using `malloc`, it returns a pointer to the allocated memory block. In your case, `ctx->epg_buffers` is a pointer that holds the address of the allocated memory block.

When you use `memset` to initialize the memory block to zero, you need to provide the starting address of the memory block to be initialized, along with the size of the memory block and the value you want to set (in this case, zero).

*? So, even though `ctx->epg_buffers` holds the address of the allocated memory, you still need to use it to indicate the starting address of the memory block you want to initialize with `memset`. If you were to use just `epg_buffers`, it would not be sufficient to indicate the correct memory location to initialize, and it might lead to undefined behavior or incorrect memory initialization.

*? In short, you need to use `ctx->epg_buffers` in the `memset` function call to ensure that you are correctly initializing the memory block pointed to by that pointer.

*! struct ccx_decoder_608_report *report_608 = malloc(sizeof(struct ccx_decoder_608_report));                    Here the result of malloc is not casted on any other things like int or pointer ? Why ?

*? Ans)In C, when you use the `malloc` function to allocate memory, the result is a pointer to the allocated memory block. The pointer is of type `void *`, which is a generic pointer type that can point to any data type. Since C allows implicit conversion from `void *` to other pointer types, it's not necessary to explicitly cast the result of `malloc` to the destination pointer type.

In your code snippet:

*? The `malloc` function returns a pointer to a memory block that is the size of `sizeof(struct ccx_decoder_608_report)`, which is determined by the size of the structure `struct ccx_decoder_608_report`. The returned pointer is assigned to the variable `report_608`, which is declared as a pointer to `struct ccx_decoder_608_report`.

There's no need to explicitly cast the result of `malloc` in this case, because C allows the implicit conversion from `void *` to `struct ccx_decoder_608_report *`. The assignment itself ensures that the pointer type matches the destination type, and the size of the memory block is determined correctly based on the size of the structure.

*? Explicitly casting the result of `malloc` is considered unnecessary and potentially error-prone in modern C programming, as it can hide potential issues with type mismatches and make the code less readable. The implicit conversion provided by C is safer and clearer.

*! Q)Is free a predefined function in C ?
*? Ans)Yes, `free` is a predefined function in C. It is part of the C Standard Library and is used to deallocate memory that was previously allocated using functions like `malloc`, `calloc`, or `realloc`. Properly freeing allocated memory is important to prevent memory leaks in your program.

The syntax of the `free` function is simple:

#include <stdlib.h>
void free(void *ptr);

*? Here, `ptr` is a pointer to the memory block that you want to deallocate. After calling `free(ptr)`, the memory block pointed to by `ptr` is released, and the pointer `ptr` becomes invalid. It's important to note that you should not access the memory pointed to by `ptr` after it has been freed, as doing so can lead to undefined behavior.

For example, if you allocate memory using `malloc` like this:

int *arr = (int *)malloc(sizeof(int) * 10);

You should free the allocated memory when you're done using it:

free(arr);

Remember to always pair memory allocation (`malloc`, `calloc`, `realloc`) with memory deallocation (`free`) to ensure proper memory management and prevent memory leaks in your C programs.
*! ----------------------------------------------------------------------------------------------------------------
*TODO See 10_Pointer.c to more understand line 149

*! In line 157 - ctx->freport.data_from_608 = report_608;  
*? Ans)We have , struct file_report freport inside struct lib_ccx_ctx in lib_ccx.h | struct file_report is there in lib_ccx.h | Then inside struct file_report we have - struct ccx_decoder_608_report *data_from_608; | And ccx_decoder_608_report is inside ccx_decoders_608.h

*! In line 158 - ctx->dec_global_setting->settings_608->report = report_608;
*? Ans)Inside struct lib_ccx_ctx in lib_ccx.h we have - struct ccx_decoders_common_settings_t *dec_global_setting; | Inside struct ccx_decoders_common_settings_t in ccx_decoders_structs.h we have - struct ccx_decoder_608_settings *settings_608; | Inside struct ccx_decoder_608_settings in ccx_decoders_608.h we have - struct ccx_decoder_608_report *report; | struct ccx_decoder_608_report is inside ccx_decoders_608.h

*! In line 159 - ctx->freport.data_from_708 = report_dtvcc;
*? Ans)struct file_report freport is inside struct lib_ccx_ctx in lib_ccx.h | struct file_report is there in lib_ccx.h | Inside struct file_report we have - struct ccx_decoder_dtvcc_report *data_from_708; | struct ccx_decoder_dtvcc_report is in ccx_decoders_708.h

*! In line 160 - ctx->dec_global_setting->settings_dtvcc->report = report_dtvcc;
*? Ans)Inside struct lib_ccx_ctx in lib_ccx.h we have - struct ccx_decoders_common_settings_t *dec_global_setting; | Inside struct ccx_decoders_common_settings_t in ccx_decoders_structs.h we have - struct ccx_decoder_dtvcc_settings *settings_dtvcc; | Inside struct ccx_decoder_dtvcc_settings in ccx_decoders_708.h we have ccx_decoder_dtvcc_report *report; | struct ccx_decoder_dtvcc_report is in ccx_decoders_708.h

*! In line 161 - ctx->mp4_cfg.mp4vidtrack = opt->mp4vidtrack;
*? Ans)Inside struct lib_ccx_ctx in lib_ccx.h we have - struct ccx_s_mp4Cfg mp4_cfg; | Inside struct ccx_s_mp4Cfg in lib_ccx.h we have mp4vidtrack | mp4vidtrack is also in ccx_s_options in ccx_common_option.h
--------------------------------------------------------------------------------------------------------------------

*/