// How would you test the word count program? what kinds of input are most likely to uncover bugs if there are any?

/* To test the word count program first try no input. The output should be: 0 0 0 (zero newlines, zero words, zero cahracter).
 * Then try a one-character word. The output should be 1 1 2(one newline, onw word, two characters--a letter followed by newline character).
 * Then try two character word. The output should be: 1 1 3(one newline, onw word, three characters-- two characterS followed by a newline character).
 * In addition, try 2 one-cahracter words(the output should be: 1 2 4) and 2 one-character words-- onw word perline(the output should be 2 2 4).
 * The kinds of input most likely to uncover bugs are those that test boundary conditions. Some boundaries are:
 *
 * --no input
 * --no words--just newlines
 * --no words--just blanks, tabs, and newlines
 * -- one word per line--no blanks and tabs
 * --word starting at the beginning of the line
 * --word starting after some blanks
