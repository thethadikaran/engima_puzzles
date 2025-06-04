// PROBLEM -> https://leetcode.com/problems/matrix-diagonal-sum/
// TIME COMPLEXITY  -> O(N)   ; N - size of the matrix
// SPACE COMPLEXITY -> O(1)

int diagonalSum(int** mat, int matSize, int* matColSize) {
  int sum = 0;

  // if the size of matrix is odd, then prevent adding the
  // center element twice
  bool is_odd_size = (matSize % 2 != 0);

  for (int i = 0; i < matSize; i++) {
    // summing elements along the primary diagonal
    sum += mat[i][i];

    // summing elements along the secondary diagonal
    // if even size matrix and index of row & col are not same
    if (is_odd_size && matSize-1-i == i) 
      continue;

    sum += mat[i][matSize - 1 - i];

  }
  return sum;
}
