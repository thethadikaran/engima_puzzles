// PROBLEM -> https://leetcode.com/problems/sign-of-the-product-of-an-array
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

int arraySign(int* nums, int numsSize) {
  int val = 1;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0) return 0;
    if (nums[i] < 0) val *= -1;
  }

  return val;    
}
