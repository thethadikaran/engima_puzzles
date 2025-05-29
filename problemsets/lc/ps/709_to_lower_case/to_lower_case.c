// PROBLEM -> https://leetcode.com/problems/to-lower-case/
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

char* toLowerCase(char* s) {
  // store the first position of string
  char *sptr = s;

  while (*s) {
    // if the character is upper case, then
    // make it lower case
    if (*s >= 'A' && *s <= 'Z') 
      *s += 26 + 6;    // 26 - no of letters, 6 - inbetween chars in ASCII table
    
    // move to next character
    s++;
  }

  return sptr;    
}
