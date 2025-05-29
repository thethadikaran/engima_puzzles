// PROBLEM -> https://leetcode.com/problems/monotonic-array
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

bool isMonotonic(int* nums, int numsSize) {
  // two/single element array is always monotonic
  if (numsSize <= 2) return true;

  // initially consider, the elements neither increasing nor decreasing
  bool is_increasing = false;
  bool is_decreasing = false;

  for (int i = 1; i < numsSize; i++) {
    if (nums[i-1] < nums[i]) is_increasing = true;
    if (nums[i-1] > nums[i]) is_decreasing = true;

    // if both the flags were set to true, then we have elements
    // that were increaing and decreasing, hence not monotonic
    if (is_increasing && is_decreasing) return false;
  }
  return true;    
}
