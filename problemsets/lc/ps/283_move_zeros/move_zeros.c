// PROBLEM -> https://leetcode.com/problems/move-zeroes/
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

void moveZeroes(int* nums, int numsSize) {
  // consider two pointers
  //   zptr  -> index of element zero
  //   nzptr -> index of non-zero element
  // 
  // initial start -> set zptr & nzptr = 0
  // exit condition -> break while, when zptr reach end of array
  //
  // if zptr points to zero element, then 
  //    setup loop to move until nzptr points to non-zero element
  //        if nzptr reach end of array, then return
  //    swap the elements, b/w zptr & nzptr
  // else, increment zptr
  //
  // ideal is to loop over find the non-zero elements and swap
  // with zero elements.

  int zptr = 0, nzptr = 0;

  while (zptr < numsSize) {
    if (nums[zptr] == 0) {
      while (nzptr < numsSize && nums[nzptr] == 0) {
        nzptr++;
      }

      // does nzptr reaches the end of array?
      if (nzptr >= numsSize) return;

      // swap b/w non-zero and zero elements
      nums[zptr] = nums[nzptr];
      nums[nzptr] = 0;
    }
    zptr++;
    nzptr++;
  }  
}
