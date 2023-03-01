# C-ASM Interface

## Description
This project contains three exercises demonstrating the interface between C and Assembly language. Each exercise includes a C program and an Assembly routine to perform specific tasks, showcasing how C and Assembly can work together.

### Exercise 1: "holaxd.c" and "imp.asm"
This exercise demonstrates a simple function call from C to Assembly that prints a message.

#### holaxd.c
```c
#include <stdio.h>

int main() {
    extern int imprimo();
    int y;
    printf("Programa que hace el llamado de la función imprime\n");
    imprimo();
    return 0;
}
```

This C code declares an external function `imprimo` and calls it to print a message.

#### imp.asm

```asm
global imprimo
extern printf

section .data
    msg db "hola mundo!!", 0

section .text
imprimo:
    push dword msg
    call printf
    add esp, 4
    ret
```

This Assembly code defines the `imprimo` function, which prints "hola mundo!!" using the `printf` function from the C standard library.

### Exercise 2: "variable.c" and "pasoparam.asm"

This exercise shows how to pass parameters from C to Assembly and return the result back to C.

#### variable.c

```c
#include <stdio.h>

extern int suma(int v1, int v2);

int main() {
    int v1, v2, sum;
    printf("Dame un dato para sumar\n");
    scanf("%d", &v1);
    printf("Dame otro numero para sumar\n");
    scanf("%d", &v2);
    sum = suma(v1, v2);
    printf("El resultado de la suma es = %d\n", sum);
    return 0;
}
``` 

This C code reads two integers from the user, calls the `suma` function, and prints the result.

#### pasoparam.asm

```asm
global suma

suma:
    push dword ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    mov edx, [ebp + 12]
    add eax, edx
    pop dword ebp
    ret
```

This Assembly code defines the `suma` function, which takes two integers as parameters, adds them, and returns the result.

### Exercise 3: "collatz.c" and "half.asm"

This exercise implements the Collatz conjecture, using a combination of C and Assembly to process the sequence.

#### collatz.c

```c
#include <stdio.h>

extern int half(int x);

int main() {
    int count, x, y;
    count = 0;
    printf("Entra un número: ");
    scanf("%d", &x);
    while (x != 1) {
        count++;
        y = half(x);
        printf("\nDevuelve %d\n", y);
        if (y != 0)
            x = y;
        else
            x = x * 3 + 1;
        printf("\nX = %d\n", x);
    }
    printf("\nHay %d iteracciones.\n\n", count);
    return 0;
}
```

This C code reads an integer from the user, repeatedly applies the Collatz function, and prints the number of iterations.

#### half.asm

```asm
global half

half:
    push ecx
    mov ecx, [esp + 8]
    mov eax, 0
agn:
    inc eax
    sub ecx, 2
    jg agn
    jz dun
    mov eax, 0
dun:
    pop ecx
    ret
```

This Assembly code defines the `half` function, which performs integer division by 2 and returns the result.

## How to Use

1.  **Compilation**: Each C file can be compiled with the corresponding Assembly file using `gcc` and `nasm`.
    
```bash
    gcc -o holaxd holaxd.c imp.o
    nasm -f elf32 imp.asm
    
    gcc -o variable variable.c pasoparam.o
    nasm -f elf32 pasoparam.asm
    
    gcc -o collatz collatz.c half.o
    nasm -f elf32 half.asm
``` 
    
2.  **Execution**: Run the compiled programs to see the output of the C-Assembly interactions.
    
```bash
    ./holaxd
    ./variable
    ./collatz
```