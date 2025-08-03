// PROBLEM -> https://leetcode.com/problems/reverse-string/
// time complexity  -> O(N)
// space complexity -> O(1)

void reverseString(char* s, int sSize) {
  int lptr = 0, rptr = sSize - 1;
  char swap;

  while (lptr < rptr) {
    swap = s[lptr];
    s[lptr] = s[rptr];
    s[rptr] = swap;

    lptr++;
    rptr--;
  }
}
