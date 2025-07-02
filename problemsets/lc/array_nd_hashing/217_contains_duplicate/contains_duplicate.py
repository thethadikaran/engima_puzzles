# problem -> https://leetcode.com/problems/contains-duplicate/
# time complexity  -> O(N)
# space complexity -> O(N)

class Solution:
  def containsDuplicate(self, nums: List[int]) -> bool:
    return len(nums) != len( set(nums) )
        
