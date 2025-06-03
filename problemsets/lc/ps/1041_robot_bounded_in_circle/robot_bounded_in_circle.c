// PROBLEM -> https://leetcode.com/problems/robot-bounded-in-circle/
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

bool isRobotBounded(char* instructions) {
  int x = 0, y = 0;
  char face = 'N';

  while (*instructions) {
    if (*instructions == 'G') {
      switch (face) {
        case 'N': y++; break;
        case 'S': y--; break;
        case 'W': x--; break;
        case 'E': x++; break;
      }
    }
    else if (*instructions == 'L') {
      switch (face) {
        case 'N': face = 'W'; break;
        case 'W': face = 'S'; break;
        case 'S': face = 'E'; break;
        case 'E': face = 'N'; break;
      }
    }
    else if (*instructions == 'R') {
      switch (face) {
        case 'N': face = 'E'; break;
        case 'E': face = 'S'; break;
        case 'S': face = 'W'; break;
        case 'W': face = 'N'; break;
      }
    }
    instructions++;
  }

  // the robot will exist in circle loop if
  //  1. change of distance - return back to origin
  //  2. change of direction - head points in direction other that starting direction (North)

  if (x == 0 && y == 0) return true;
  if (face != 'N') return true;

  return false;
}
