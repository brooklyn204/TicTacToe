#include <stdio.h>
#include<stdlib.h>

void printBoard(char b[3][3]) {
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (j == 2) {
        printf(" %c ",b[i][j]);
      } else {
        printf(" %c |",b[i][j]);
      }
    }
    if (i != 2) {
        printf("\n-----------\n"," ");
    }
  }
}

void makeMove(int player, char b[3][3]) {
  if (player == 1) { // Player 1
    char prompt[] = "\n\nIt's player one's turn. Enter your move in the format [row,col].\n";
    printf("%s", prompt);
    int row;
    int col;
    char temp;
    int legalInput = 1;
    scanf("%d", &row);
    if (row > 2 || row < 0) {
      legalInput = 0;
    } else {
      scanf("%c", &temp);
      scanf("%d", &col);
      if (col > 2 || col < 0 || b[row][col] != ' ') {
        legalInput = 0;
      }
    }
    char illegalPrompt[] = "\nInvalid move! Try again. Enter your move in the format [row,col].\n";
    while (legalInput == 0) {
      printf("%s", illegalPrompt);
      scanf("%d", &row);
      scanf("%c", &temp);
      scanf("%d", &col);
      legalInput = 1;
      if ((row > 2 || row < 0 || col > 2 || col < 0) || b[row][col] != ' ') {
        legalInput = 0;
      }
    }
    b[row][col] = 'X';
  } else if (player == 2) { // Player 2
    char prompt[] = "\n\nIt's player two's turn. Enter your move in the format [row,col].\n";
    printf("%s\n",prompt);
    int row;
    int col;
    char temp;
    int legalInput = 1;
    scanf("%d", &row);
    if (row > 2 || row < 0) {
      legalInput = 0;
    } else {
      scanf("%c", &temp);
      scanf("%d", &col);
      if (col > 2 || col < 0 || b[row][col] != ' ') {
      legalInput = 0;
      }
    }
    char illegalPrompt[] = "\nInvalid move! Try again. Enter your move in the format [row,col].\n";
    while (legalInput == 0) {
      printf("%s", illegalPrompt);
      scanf("%d", &row);
      scanf("%c", &temp);
      scanf("%d", &col);
      legalInput = 1;
      if (row > 2 || row < 0 || col > 2 || col < 0 || b[row][col] != ' ') {
        legalInput = 0;
      }
    }
    b[row][col] = 'O';
  }
}

// Returns an integer to represent whether or not the game is over. 0 = game not over. 1 = player 1 won. 2 = player 2 won. 3 = tie. -1 = error.
int isGameOver(char b[3][3]) {
  int flag = 0; // Flag variable to check if there are any white spaces on the board
  // Variables to track the first item in a row and how many of that item are in the row, respectively.
  char row;
  int numRow;
  // Iterate through the rows and columns to determine if there is three in a row or if there are no moves remaining
  for (int i=0; i<3; i++) {
    row = b[i][0];
    numRow = 0;
    for (int j=0; j<3; j++) {
      if (b[i][j] == ' ') {
        flag = 1;
      }
      if (b[i][j] == row) {
        numRow++;
      }
    }
    if (numRow == 3) { // Case 1: all the squares in a row are the same. The game is over.
      if (row == 'X') {
        return 1;
      } else if (row == 'O') {
        return 2;
      }
    }
  }
  if (flag == 0) { // Case 2: no empty space left on the board. The game is over.
    return 3;
  }
  // Variables to track the first item in a column and how many of that item are in the column, respectively.
  char col;
  int numCol;
  // Iterate through the columns and rows to determine if there is three in a column.
  for (int i=0; i<3; i++) {
    col = b[0][i];
    numCol = 0;
    for (int j=0; j<3; j++) {
      if (b[j][i] == col) {
        numCol++;
      }
    }
    if (numCol == 3) { // Case 3: All the items in a column are the same. The game is over.
      if (col == 'X') {
        return 1;
      } else if (col == 'O') {
        return 2;
      }
    }
  }
  // Case 4: all the items along one diagonal are the same. The game is over.
  if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
    if (b[0][0] == 'X') {
      return 1;
    }
    if (b[0][0] == 'O') {
      return 2;
    }
  }
  // Case 5: all the items along the other diagonal are the same. The game is over.
  if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
    if (b[0][2] == 'X') {
      return 1;
    }
    if (b[0][2] == 'O') {
      return 2;
    }
  }
  // Case 6: None of the above conditions are true. The game is not over.
  return 0;
}

int main() {
  // Print intro
  char welcome[] = "Welcome to Tic Tac Toe. Player one is X, player two is O.\n\n";
  printf("%s",welcome);
  // Create and print an empty board
  char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
  printBoard(board);
  // Until the game is over, let each player take turns playing
  int player = 1;
  int isOver = 0;
  while (isOver == 0) {
    makeMove(player,board);
    printBoard(board);
    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }
    isOver = isGameOver(board);
  }
  if (isOver == 1) {
    printf("\nPlayer One wins!");
  } else if (isOver == 2) {
    printf("\nPlayer Two wins!");
  } else if (isOver == 3) {
    printf("\nIt was a tie!");
  }
  printf("\nHit any key and enter to quit.");
  scanf("%s");
  return 0;
}