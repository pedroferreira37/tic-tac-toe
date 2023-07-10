#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define COLS 3
#define ROWS 3

enum Player { PLAYER_X, PLAYER_O };

enum Player current_player;

char board[3][3];

void initialize() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = ' ';
    }
  }
}

void get_player() {
  char player_choice;

  do {
    printf("Choose your player (X or O): ");

    scanf(" %c", &player_choice);
  } while (player_choice != 'X' && player_choice != 'O');

  current_player = (player_choice == 'X') ? PLAYER_X : PLAYER_O;
}

void render() {
  for (int i = 0; i < ROWS; i++) {
    if (i != 0) {
      printf("----------\n");
    }
    for (int j = 0; j < COLS; j++) {

      if (j != 0) {
        printf("| ");
      }
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

bool is_move_valid(int row, int col) {
  return (row >= 0 && row < ROWS && col >= 0 && col < COLS &&
          board[row][col] == ' ');
}
void make_move() {
  int row, col;

  do {
    printf("Choose a row (1-3): ");
    scanf("%d", &row);
    row--;

    printf("Choose a column (1-3): ");
    scanf("%d", &col);
    col--;

    if (!is_move_valid(row, col)) {
      printf("Invalid move. Please try again.\n");
    }
  } while (!is_move_valid(row, col));

  board[row][col] = (current_player == PLAYER_X) ? 'X' : 'O';
}

bool is_board_full() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

bool has_won(enum Player player) {

  for (int i = 0; i < ROWS; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2] &&
        board[i][0] != ' ') {
      return true;
    }
  }

  for (int j = 0; j < COLS; j++) {
    if (board[0][j] == board[1][j] && board[0][j] == board[2][j] &&
        board[0][j] != ' ') {
      return true;
    }
  }

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] &&
      board[0][0] != ' ') {
    return true;
  }
  if (board[0][2] == board[1][1] && board[0][2] == board[2][0] &&
      board[0][2] != ' ') {
    return true;
  }

  return false;
}

void run_game() {
  initialize();
  get_player();

  while (true) {
    render();
    make_move();

    if (has_won(current_player)) {
      printf("Player %c has won!\n", (current_player == PLAYER_X) ? 'X' : 'O');
      break;
    } else if (is_board_full()) {
      printf("It's a draw!\n");
      break;
    }

    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    system("clear");
  }
}

int main(int argv, char **argc) {
  run_game();
  return 0;
}
