// PROBLEM -> 
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
  // if only two points, then it will always be stright line
  if (coordinatesSize == 2) return true;

  // dy/dx = m = (y2 - y1)/(x2 - x1)
  int dy = coordinates[1][1] - coordinates[0][1];
  int dx = coordinates[1][0] - coordinates[0][0];

  // for any two points verify,
  // dy(x2 - x1) == dx(y2 - y1)

  for (int i = 1; i < coordinatesSize; i++) {
    if ( dy * (coordinates[i][0] - coordinates[i-1][0]) != dx * (coordinates[i][1] - coordinates[i-1][1]) )
      return false;
  }

  return true;   
}
