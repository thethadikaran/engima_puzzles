// PROBLEM -> https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// TIME COMPLEXITY  -> O(A)   ; A - is the total number of moves
// SPACE COMPLEXITY -> O(1)   ; no matter the input size, size occupied by the board is constant

#define SIZE 3

char is_winner(char[][SIZE]);

char* tictactoe(int** moves, int movesSize, int* movesColSize) {
  // initilize board with 
  char board[SIZE][SIZE] = {1,2,3, 4,5,6, 7,8,9};
  int move = 0;

  for (; move < movesSize; move++) {
    // update the move in the board
    board[ moves[move][0] ][ moves[move][1] ] = (move % 2 == 0 ? 'X' : 'O');

    // let's check for any winners
    char winner = is_winner(board);
    if (winner == 'X') return "A";
    if (winner == 'O') return "B";

    // does the board is filled, without any winners?  
    if (move >= 8) return "Draw";
  } 
  return "Pending"; 
}



char is_winner(char board[][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    // check horizontally
    if ( (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) )
      return board[i][0];

    // check vertically
    if ( (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) )
      return board[0][i];
  }

  // diagonal - left to right
  if ( (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) )
    return board[0][0];

  // diagonal -right to left
  if ( (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) )
    return board[0][2];

  return 'N';
}
