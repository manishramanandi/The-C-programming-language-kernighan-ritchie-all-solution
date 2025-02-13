// Write a program to chaeck a C program for reduimentary syntax error like unbalanced parentehses, brackets, and braces. Don't forget about quptes, borh single and double, escape sequences, and comments. 

#include <stdio.h>

#define MAX_STACK 1000

char stack[MAX_STACK];
int top = -1;

/* Push a character onto the stack */
void push(char c) {
    if (top < MAX_STACK - 1)
        stack[++top] = c;
}

/* Pop a character from the stack */
char pop() {
    return (top >= 0) ? stack[top--] : '\0';
}

/* Check if the stack is empty */
int is_empty() {
    return top == -1;
}

/* Get the top character of the stack without popping */
char peek() {
    return (top >= 0) ? stack[top] : '\0';
}

/* Function to check if characters are balanced */
void check_syntax() {
    int c, prev;
    int in_single_quote = 0, in_double_quote = 0, in_comment = 0;
    
    prev = 0;

    while ((c = getchar()) != EOF) {
        /* Handle single-line comments (//) */
        if (in_comment == 0 && prev == '/' && c == '/') {
            in_comment = 1;
        }

        if (in_comment == 0 && prev == '/' && c == '*') {
            in_comment = 2;
        }

        /* End of single-line comment */
        if (in_comment == 1 && c == '\n') {
            in_comment = 0;
        }

        /* End of multi-line comment */
        if (in_comment == 2 && prev == '*' && c == '/') {
            in_comment = 0;
            c = 0;  // Prevent false detection of '/' after "*/"
        }

        /* Ignore characters inside comments */
        if (in_comment) {
            prev = c;
            continue;
        }

        /* Handle escape sequences */
        if (c == '\\') {
            getchar(); // Skip the next character (escape sequence)
            continue;
        }

        /* Handle quotes */
        if (c == '\'' && !in_double_quote) {
            in_single_quote = !in_single_quote;
        } 
        else if (c == '"' && !in_single_quote) {
            in_double_quote = !in_double_quote;
        }

        /* Ignore characters inside quotes */
        if (in_single_quote || in_double_quote) {
            prev = c;
            continue;
        }

        /* Handle opening brackets */
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        
        /* Handle closing brackets */
        if (c == ')' || c == '}' || c == ']') {
            char last = pop();
            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                printf("Unbalanced %c\n", c);
                return;
            }
        }

        prev = c;
    }

    /* Check if stack is empty at the end */
    if (!is_empty()) {
        printf("Unbalanced %c\n", peek());
    } else {
        printf("Syntax is correct\n");
    }
}

/* Main function */
int main() {
    printf("Enter C code (Ctrl+D to end input):\n");
    check_syntax();
    return 0;
}

