#include <curses.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define COLS 3
#define ROWS 3
#define getsy(n) ((n == 1) ? 'X' : 'O')

int CURRENT_KEY = 0;

typedef struct Array {
  char board[ROWS][COLS];
} Board;

void set_key(int value) { CURRENT_KEY = value; }

void rscr() {
  int DEFAULT;

  DEFAULT = CURRENT_KEY == 1 ? 0 : 1;

  printw("\n");
  printw(" > %c \n", getsy(CURRENT_KEY));
  printw("  %c", getsy(DEFAULT));
}

char get_player() {
  int c;

  printw("%s", "Choose your player");

  while (1) {
    c = getch();

    clear();

    switch (c) {
    case KEY_UP:
      set_key(0);
      rscr();
      break;
    case KEY_DOWN:
      set_key(1);
      rscr();
      break;
    default:
      clear();
      printw("Not valid key");
    }

    refresh();
  }

  return c;
}

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
  initscr();
  keypad(stdscr, TRUE);
  get_player();
  return 0;
}
