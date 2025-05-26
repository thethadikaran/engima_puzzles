// PROBLEM -> https://leetcode.com/problems/find-the-difference
// TIME COMPLEXITY  -> O(N)    ; N - length of s
// SPACE COMPLEXITY -> O(1)

char findTheDifference(char* s, char* t) {
  int additional_char = 0;

  // t contains one char more than s and the order is shuffled.
  // substract all the chars from s with t, and the final result
  // is the ASCII code for additonal char
  while (*s) 
    additional_char += *(t++) - *(s++);

  // since t has one char more than s, updating the last char
  additional_char += *t;

  return additional_char;
}

/*
One other way of solving it to do XOR b/w the character of the string
XOR - cancels out the similar char in both string
and the result will be the additonal char

char findTheDifference(char* s, char* t) {
    char additional_char = 0;

    // XOR all characters in both strings
    while (*s) {
        additional_char ^= *s++;
    }
    while (*t) {
        additional_char ^= *t++;
    }

    return additional_char;
}
*/
