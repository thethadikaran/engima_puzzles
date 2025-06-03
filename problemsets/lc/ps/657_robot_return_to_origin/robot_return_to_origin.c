// PROBLEM -> https://leetcode.com/problems/robot-return-to-origin/
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY ->O(1)

bool judgeCircle(char* moves) {
  int ver = 0, hor = 0;

  while (*moves) {
    switch (*moves) {
      case 'R': hor++; break;
      case 'L': hor--; break;
      case 'U': ver++; break;
      case 'D': ver--; break;
    }
    moves++;
  }

  return (ver == 0 && hor == 0);    
}
