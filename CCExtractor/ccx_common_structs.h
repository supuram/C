/**
*! void(*fatal_ftn) (int exit_code, const char *fmt, ...);  

*? Explanation - The type of function `void(*fatal_ftn) (int exit_code, const char *fmt, ...);` is a function pointer type in C. Let's break down the components of this declaration:

1. `void`: This is the return type of the function. It indicates that the function returns no value (i.e., it has a `void` return type).

2. `(*fatal_ftn)`: This is the function pointer declaration. It declares a pointer named `fatal_ftn` that points to a function. The parentheses are used to indicate that this is a pointer to a function.

3. `(int exit_code, const char *fmt, ...)`: This is the parameter list of the function that the pointer `fatal_ftn` points to. It specifies the parameters that the function takes. In this case, it takes an integer `exit_code`, a pointer to a constant character array (`const char *fmt`), and an ellipsis `...` indicating that the function can take a variable number of additional arguments.

So, the type `void(*fatal_ftn) (int exit_code, const char *fmt, ...);` represents a pointer to a function that takes an integer and a format string (for variable arguments) as parameters and returns nothing (`void`). This function pointer type allows you to assign a pointer to a function that matches this signature, and then you can use that pointer to call the corresponding function with the specified parameters.
-------------------------------------------------------------------------------------------------------------------
*/