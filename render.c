#include "render.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>


void render(char board[3][3]) {
  for (int i = 0; i < ROWS; i++) {
    if(i != 0) {
      printf("----------\n");
    }
    for (int j = 0; j < COLS; j++) {
      if(j != 2) {
      printf("%c | ", board[i][j]);
      }
    }
    printf("\n");
  }
}

