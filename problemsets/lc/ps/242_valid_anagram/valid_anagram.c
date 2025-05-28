// PROBLEM -> https://leetcode.com/problems/valid-anagram/
// TIME COMPLEXITY  -> O(N)    ; N - length of the string (assuming both strings are same len)
// SPACE COMPLEXITY -> O(1)

bool isAnagram(char* s, char* t) {
  // array act as a hashtable, where index 0 - 25 denotes alphabets a - z
  int cnt[26] = {0};

  while (*s || *t) {
    if (*s) cnt[*(s++) - 'a']++;     // increment for presence
    if (*t) cnt[*(t++) - 'a']--;     // decrement for presence
  }

  // finally, the count of letters should be zero, if anagram
  for (int i = 0; i < 26; i++) {
    if (cnt[i] != 0) return false; 
  }

  return true;
}
