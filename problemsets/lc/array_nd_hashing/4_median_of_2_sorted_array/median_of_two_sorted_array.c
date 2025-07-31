// PROBLEM -> https://leetcode.com/problems/median-of-two-sorted-arrays
// time complexity  -> O(M + N)
// space complexity -> O(M + N) 

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int merged_arr[nums1Size + nums2Size];

  int i = 0, j = 0, idx = 0;
  while (i < nums1Size && j < nums2Size) {
    if (nums1[i] < nums2[j])
      merged_arr[idx++] = nums1[i++];
    else
      merged_arr[idx++] = nums2[j++];
  }

  // if we have leftover elements, append it
  while (i < nums1Size) {
    merged_arr[idx++] = nums1[i++];
  }

  while (j < nums2Size) {
    merged_arr[idx++] = nums2[j++];
  }

  // return the median based on the size is odd or even
  int mid = idx / 2;
  return (idx % 2 != 0) ? merged_arr[mid] : (merged_arr[mid] + merged_arr[mid - 1] ) / 2.0;
}
