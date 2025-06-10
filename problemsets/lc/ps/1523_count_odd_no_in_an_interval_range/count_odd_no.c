// PROBLEM -> https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
// TIME COMPLEXITY  -> O(1)
// SPACE COMPLEXITY -> O(1)

int countOdds(int low, int high){
  // count total no b/w the range including the limits
  int count = (high - low ) + 1;

  // if high and low are odd, then do (count / 2) + 1
  // else just count / 2
  return ( (low % 2 != 0 && high % 2 != 0) ? count/2 + 1 : count/2);
}
