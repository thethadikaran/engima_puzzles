// PROBLEM -> https://leetcode.com/problems/plus-one/
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(N)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  int *res = malloc(sizeof(int) * (digitsSize + 1) );
  int carry = 1;

  for (int i = digitsSize - 1; i >= 0; i--) {
    // if no carry is present, then copy the digit to res
    // and continue
    if (!carry) {
      res[i + 1] = digits[i];
      continue;
    }

    // if we have carry, then add it to digit
    // check if it overflow and if so set carry
    if (digits[i] + 1 < 10) {
      res[i + 1] = digits[i] + 1;
      carry = 0;          // reset carry, as we don't have overflow
    }
    else
      res[i + 1] = 0;     // don't reset the carry 
  }

  // finally, if we have carry, update first element
  if (carry) {
    res[0] = 1;
    *returnSize = digitsSize + 1;
    return res;
  }

  // if no carry, then first element position don't have any value
  // so, increment the res pointer to fist element
  *returnSize = digitsSize;  
  return ++res;    
}
