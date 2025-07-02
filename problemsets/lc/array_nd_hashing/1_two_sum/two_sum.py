# problem -> 
# time complexity  -> O(N)
# space complexity -> O(N)

  def twoSum(self, nums: List[int], target: int) -> List[int]:
    pair = {}

    for i, v in enumerate(nums):
      diff = target - v

      if diff in pair:
        return (pair[diff], i)

      pair[v] = i    
