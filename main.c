#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define COLS 3
#define ROWS 3

typedef struct Array {
  char board[3][3];
} Board;

Board create_game() {
  Board game;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      game.board[i][j] = ' ';
    }
  }

  return game;
}

char select_player() {
  char choosed_player;

  printf("Choose you player (X or O): ");
  scanf("%c", &choosed_player);

  return choosed_player;
}

void clear() { system("clear"); }

void render(Board game) {
  for (int i = 0; i < ROWS; i++) {
    if (i != 0) {
      printf("----------\n");
    }
    for (int j = 0; j < COLS; j++) {

      if (j != 2) {
        printf("%c | ", game.board[i][j]);
      }
    }
    printf("\n");
  }
}

void start_game(Board game, char player) {
  int turn = 0;
  int c_row;
  int c_col;

  clear();
  render(game);

  while (true) {

    printf("Choose a row (1, 2, 3): ");
    scanf("%d", &c_row);

    printf("Choose a col(1, 2, 3): ");
    scanf("%d", &c_col);

    game.board[c_row - 1][c_col - 1] = turn ? 'O' : player;

    clear();
    render(game);

    turn = turn ? 0 : 1;
  }
}

int main(int argv, char **argc) {

  Board game = create_game();

  char player = select_player();

  render(game);

  start_game(game, player);
  return 0;
}
