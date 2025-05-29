// PROBLEM -> https://leetcode.com/problems/length-of-last-word
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

int lengthOfLastWord(char* s) {
  char *last_token = NULL;

  // split the string at the space and
  // returns the first token
  char *token = strtok(s, " ");  

  // loop over to get the last token (word)
  while (token != NULL) {
    last_token = token;    
    token = strtok(NULL, " ");   // get the next token
  }

  return strlen(last_token);
}
