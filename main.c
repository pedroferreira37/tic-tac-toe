#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "config.h"
#include "render.h"
#include <stdbool.h>


typedef struct Array {
  char board[3][3];
} Game;


Game create_game(int rows, int cols) {
  Game game; 

  for(int i = 0; i < rows; i++) {

    for(int j = 0; j < cols; j++) {

      game.board[i][j] = ' ';

    }
  }

  return game;
}


char player_select() {

  char choosed_player;

  printf("Choose you player (X or O): ");
  scanf("%c", &choosed_player);
  
  return choosed_player;
}


void start_game(Game game, char player) {
  int turn = 0;
  int choosed_row;
  int choosed_col;

  system("clear");
  render(game.board);


  while(true) {
    

    printf("Choose a row (1, 2, 3): ");
    scanf("%d", &choosed_row);


    printf("Choose a col(1, 2, 3): ");
    scanf("%d", &choosed_col);


    game.board[choosed_row - 1][choosed_col - 1] = turn ? 'O': player;


    system("clear");
    render(game.board);



    turn = turn ? 0 : 1;

  }


}



int main(int argv, char **argc) {

  Game game = create_game(ROWS, COLS);

  char player = player_select();

  render(game.board);

  start_game(game, player);
  return 0;
}
