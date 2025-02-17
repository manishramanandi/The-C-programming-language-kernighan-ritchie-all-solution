/* Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent
integer value. The allowable digits are 0 through 9, a through f, and A through F. */

#include <stdio.h>

#define YES 1  // Constant to represent a valid hexadecimal digit
#define NO  0  // Constant to represent an invalid hexadecimal digit

/* htoi: Convert a hexadecimal string s to its integer equivalent */
int htoi(char s[]) {
    int hexdigit, i, inhex, n;

    i = 0;  // Start at the first character of the string

    // Check if the string starts with "0x" or "0X" (common hex prefix)
    if (s[i] == '0') { 
        ++i;  // Skip the '0'
        if (s[i] == 'x' || s[i] == 'X')  // Check for 'x' or 'X'
            ++i;  // Skip the 'x' or 'X' as well
    }

    n = 0;  // Initialize the result (integer value) to 0
    inhex = YES;  // Assume that the string contains valid hexadecimal digits initially

    // Loop through the string character by character while valid hex digits are found
    for (; inhex == YES; ++i) {
        // Check if the current character is a valid digit (0-9)
        if (s[i] >= '0' && s[i] <= '9') {
            hexdigit = s[i] - '0';  // Convert the character to its corresponding integer value (e.g., '3' becomes 3)
        }
        // Check if the current character is a valid lowercase hexadecimal letter (a-f)
        else if (s[i] >= 'a' && s[i] <= 'f') {
            hexdigit = s[i] - 'a' + 10;  // Convert it to the appropriate value (e.g., 'a' becomes 10)
        }
        // Check if the current character is a valid uppercase hexadecimal letter (A-F)
        else if (s[i] >= 'A' && s[i] <= 'F') {
            hexdigit = s[i] - 'A' + 10;  // Convert it to the appropriate value (e.g., 'A' becomes 10)
        }
        else {
            inhex = NO;  // If it's not a valid hexadecimal digit, set inhex to NO and stop the loop
            break;
        }

        // If the character was a valid hex digit, update the result
        if (inhex == YES) {
            n = 16 * n + hexdigit;  // Multiply the current result by 16 and add the current hex digit
        }
    }

    // Return the final result (integer equivalent of the hexadecimal string)
    return n;
}

int main() {
    // Example usage of the htoi function
    char hex_string[] = "0x1A3";  // Hexadecimal string to convert
    int result = htoi(hex_string);  // Convert the string to integer

    printf("The integer value of the hexadecimal string %s is: %d\n", hex_string, result);  // Print the result

    return 0;
}

