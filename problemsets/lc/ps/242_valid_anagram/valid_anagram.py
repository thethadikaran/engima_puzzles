# problem -> https://leetcode.com/problems/valid-anagram/
# time complexity -> O(M + N);  M, N - length of the string
# space compelxity -> O(1)

from collections import Counter
class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    return Counter(s) == Counter(t)
