// PROBLEM -> https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence
// TIME COMPLEXITY  -> O(N log N)    ; for sorting the array
// SPACE COMPLEXITY -> O(1)

int compare (const void * num1, const void * num2) {
  return (*(int*)num1 > *(int*)num2) ? 1 : -1;
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
  // ignore array of elements with size 2 or less
  if (arrSize <= 2) return true;

  // sort the elements first
  qsort(arr,  arrSize, sizeof(int), compare);

  int diff = arr[0] - arr[1];

  for (int i = 2; i < arrSize; i++ ) {
    if ((arr[i-1] - arr[i]) != diff) return false;
  }

  return true;   
}
