// PROBLEM -> https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// TIME COMPLEXITY  -> O(M x N)   ; M - len of haystack, N - len of needle, due to nested loop
// SPACE COMPLEXITY -> O(1)

int strStr(char* haystack, char* needle) {
  int hlen = strlen(haystack), nlen = strlen(needle);
  int hptr = 0, nptr = 0;     // haystack and needle pointers

  while (hptr < hlen) {
    // at every start of iteration, we start from first
    nptr = 0;

    while (nptr < nlen && haystack[hptr + nptr] == needle[nptr]) nptr++;

    // needle has reached the end, means we got a match
    if (nptr == nlen) return hptr;

    hptr++;
  }

  return -1;    
}
