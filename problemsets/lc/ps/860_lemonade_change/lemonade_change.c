// PROBLEM -> https://leetcode.com/problems/lemonade-change/
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

bool lemonadeChange(int* bills, int billsSize) {
  int bill5 = 0, bill10 = 0;

  for (int c = 0; c < billsSize; c++) {
    if (bills[c] == 5) {
      bill5++;
      continue;
    }

    if (bills[c] == 10) {
      if (bill5 < 1) return false;
      bill5--;
      bill10++;
      continue;
    }

    if (bills[c] == 20) {
      if (bill10 >= 1 && bill5 >= 1) {
        bill10--;
        bill5--;
      } else if (bill5 >= 3) {
        bill5 -= 3;
      } else
        return false;
    }
  }

  return true;    
}
