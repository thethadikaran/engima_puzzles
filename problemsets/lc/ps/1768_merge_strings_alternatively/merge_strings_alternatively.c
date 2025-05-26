// PROBLEM -> https://leetcode.com/problems/merge-strings-alternately/
// TIME COMPLEXITY  -> O(M + N)    ; M, N - length of word1 & word2
// SPACE COMPLEXITY -> O(M + N)

char * mergeAlternately(char * word1, char * word2){
  int merged_str_size = strlen(word1) + strlen(word2) + 1;  // +1 is for '\0'
  char *merged = malloc(sizeof(char) * merged_str_size);

  // need to note the string's initial position. When doing pointer
  // manipultaion we lost the address to initial position of string
  char *merged_str_start = merged; 

  // loop will terminate when end of both words is reached
  while (*word1 || *word2) {
    if (*word1)
      *(merged++) = *(word1++);   // assigning and updating pointer position

    if (*word2)
      *(merged++) = *(word2++);
  }

  // updating the end of string 
  *merged = '\0';

  return merged_str_start;
}
