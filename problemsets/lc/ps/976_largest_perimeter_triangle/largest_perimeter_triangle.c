// PROBLEM -> https://leetcode.com/problems/largest-perimeter-triangle/
// TIME COMPLEXITY  -> O(N Log N)  ; for sorting
// SPACE COMPLEXITY -> O(Log N)    ; for qsort 

int comp(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}


int largestPerimeter(int* nums, int numsSize) {
  // sort the elements
  qsort(nums, numsSize, sizeof(int), comp);

  // start from the biggest numbers
  for (int s = numsSize - 3; s >= 0; s--) {
    // check if the value forms a triangle
    if ( (nums[s] + nums[s+1]) > nums[s+2])
      return (nums[s] + nums[s+1] + nums[s+2]);
  }

  return 0;
}
