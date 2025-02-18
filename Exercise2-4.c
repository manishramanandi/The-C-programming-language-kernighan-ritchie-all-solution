/* write an alternative version of squeeze(s1, s2) that delet each character in s1 that matches any character in the string s2. */

/*squeeze: delete eaxh char in s1 which is in s2 */

#include <stdio.h>

/* Function to remove characters from s1 that appear in s2 */
void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int found;

    k = 0;  // Index for storing non-matching characters

    for (i = 0; s1[i] != '\0'; i++) { 
        found = 0;  // Flag to check if s1[i] is in s2

        // Check if s1[i] exists in s2
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) { 
                found = 1;  // Mark character for removal
                break;
            }
        }

        // If character was not found in s2, keep it in s1
        if (!found) {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';  // Null-terminate the modified string
}

/* Test the squeeze function */
int main() {
    char str1[] = "hello world";
    char str2[] = "lo";  // Characters to remove

    printf("Original: %s\n", str1);
    squeeze(str1, str2);
    printf("Modified: %s\n", str1);

    return 0;
}

