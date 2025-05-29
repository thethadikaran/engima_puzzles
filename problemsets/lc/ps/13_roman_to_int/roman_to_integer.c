// PROBLEM -> https://leetcode.com/problems/roman-to-integer
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

int int_val(char ch) {
  switch (ch) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}


int romanToInt(char* s) {
  int ival = 0, last_encounter = 0;

  // roman letters are ordered form higher to lower symbol 
  // left to right. if the order mismatches then do substract
  for (int i = strlen(s); i >= 0; i--) {
    int current = int_val(s[i]);

    if (current < last_encounter) ival -= current;
    else ival += current;

    last_encounter = current;
  }

  return ival;    
}
