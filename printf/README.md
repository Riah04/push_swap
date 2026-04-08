*This project has been created as part of the 42 curriculum by nmariah.*

# ft_printf

## 📝 Description

`ft_printf` is a custom implementation of the famous `printf` function from the C standard library (`libc`). The goal of this project is to understand the mechanics behind **variadic functions** and to build a robust, extensible formatting engine.

While `printf` seems simple on the surface, its implementation requires a deep understanding of how arguments are stored in memory and how different data types (integers, pointers, strings) are converted into human-readable text.

### Key Technical Challenges
* **Variadic Arguments:** Mastering the `<stdarg.h>` macros (`va_start`, `va_arg`, `va_end`) to handle an unknown number of parameters.
* **Base Conversion:** Implementing recursive algorithms to convert numbers into decimal and hexadecimal representations.
* **Buffer & Counting:** Ensuring the function accurately returns the total number of characters printed, a critical requirement for `printf` compliance.

---

## Instructions

### Syntax
```c
int printf(const char *format, ...);

format – A string containing text and format specifiers.

... – A variable number of arguments corresponding to the format specifiers.
```
### 🛠️ Supported Specifiers
| Specifier | Data Type      | Description                           | Example                    | Output  |
| --------- | -------------- | ------------------------------------- | -------------------------- | ------- |
| `%d`      | int            | Signed decimal integer                | `printf("%d", 10);`        | `10`    |
| `%i`      | int            | Signed decimal integer (same as `%d`) | `printf("%i", -5);`        | `-5`    |
| `%u`      | unsigned int   | Unsigned decimal integer              | `printf("%u", 42);`        | `42`    |
| `%p`      | void*          | The void * argument is printed in hexadecimal| `printf("%p", ptr);`       | `0x1000`|
| `%c`      | char           | Single character                      | `printf("%c", 'A');`       | `A`     |
| `%s`      | char*          | String                                | `printf("%s", "Hello");`   | `Hello` |
| `%x`      | unsigned int   | Unsigned hexadecimal (lowercase)      | `printf("%x", 255);`       | `ff`    |
| `%X`      | unsigned int   | Unsigned hexadecimal (uppercase)      | `printf("%X", 255);`       | `FF`    |
| `%%`      | -              | Literal `%` character                 | `printf("%%");`            | `%`     |

### Compilation

The project comes with a Makefile that compiles the source files into a library named libftprintf.a.

#### Compile the library

| Command | Action | Description |
| :--- | :--- | :--- |
| `make` | **Compile** | Compiles all `.c` source files into object files and creates the `libftprintf.a` library. |
| `make clean` | **Cleanup** | Deletes all object files (`.o`) generated during compilation, leaving the library intact. |
| `make fclean` | **Full Cleanup** | Deletes all object files **and** the compiled library (`libftprintf.a`). Resets the folder to its initial state. |
| `make re` | **Recompile** | Executes `fclean` followed by `make`. Useful for ensuring a completely fresh build of the project. |

---

### How to use:

1.  **To build the library:**
    ```bash
    make
    ```
2.  **To clean up your workspace after compilation:**
    ```bash
    make clean
    ```
3.  **To start fresh (re-compile everything):**
    ```bash
    make re
    ```

### Installation

#### Clone the repository

```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere intra-uuid-9a4a676c-d480-433e-b3df-e5f7356e01e3-7325388-nmariah  ft_printf
```

```bash
cd ft_printf
```

## Ressources

42 Norminette - Coding standard compliance.

Variadic Functions in C - Official documentation on stdarg.h.

https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/les-fonctions-a-nombre-variable-darguments/

https://openclassrooms.com/forum/sujet/fonction-variadique-et-non-pod-44635

### 🤖 AI Usage & Methodology

During the development of `ft_printf`, Artificial Intelligence was utilized as a technical collaborator to enhance code quality and solve complex algorithmic challenges.

#### How AI was integrated:
* **Logic Debugging:** AI assisted in identifying edge cases in recursive functions, particularly for hexadecimal conversions and pointer address handling.
* **Refactoring:** AI was used to peer-review the "Dispatcher" architecture (`ft_check_format`), ensuring a clean separation of concerns between parsing and execution.
* **Documentation:** This documentation and technical explanations were refined with AI to ensure clarity and professional standards.

#### Human-AI Collaboration:
While AI provided insights into standard `printf` behaviors and C edge cases, every line of code was **manually reviewed, tested, and integrated** to ensure compliance with the 42 Norminette and project constraints. The core architecture remains a human-driven design focused on modularity and reusability.

## The algorithm

 ### 🏗️ Technical Architecture

This implementation follows a highly modular **Dispatcher Pattern**, ensuring the code is easy to read, debug, and maintain.

#### 1. The Router: `ft_check_format`
To keep the main loop clean, I grouped all specifier checks into a single file named `ft_check_format`. 
* When the `%` character is detected, this file parses the subsequent character.
* It acts as a **central dispatcher**, routing the program flow to the specific logic file required for that conversion.

#### 2. Modular Specifiers
Each format specifier is isolated in its own file (e.g., `ft_putchar.c` for `%c`, `ft_conv.c` for hexadecimals). This ensures that the algorithm for one type doesn't interfere with another.

#### 3. Return Value Logic
Following the `libc` standard, `ft_printf` returns an `int` representing the total length of the output. 
* Every sub-function is designed to return the number of characters it printed. 
* These values are bubbled up through the dispatcher to the main function to provide an accurate final count.

---