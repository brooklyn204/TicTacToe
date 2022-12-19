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
    scanf("%d", &row);
    scanf("%c", &temp);
    scanf("%d", &col);
    b[row][col] = 'X';
  } else if (player == 2) { // Player 2
    char prompt[] = "\n\nIt's player two's turn. Enter your move in the format [row,col].\n";
    printf("%s",prompt);
    int row;
    int col;
    char temp;
    scanf("%d", &row);
    scanf("%c", &temp);
    scanf("%d", &col);
    b[row][col] = 'O';
  }
}

int main() {
  char welcome[] = "Welcome to Tic Tac Toe. Player one is X, player two is O.\n\n";
  printf("%s",welcome);
  char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
  printBoard(board);
  int x = 2;
  makeMove(x, board);
  printBoard(board);
  return 0;
}