#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <conio.h>
#include <stdbool.h>


struct Config {
  int ROWS;
  int COLS;
};

struct Players {
  char player1;
  char player2;
  int current;
};


struct State {
  char board[3][3];
  int keyPressed;
};


struct Game {
  struct Config config;
  struct Players players;
  struct State state;
};


void clear_screen() {
  system("cls");
}



void render(struct Game* game) {
  for(int i = 0; i < game->config.ROWS; i ++)  {

    for(int j = 0; j < game->config.COLS; j++) {

     
      if(game->state.keyPressed == 1) {
        printf("> _%c_", game->state.board[i][j]);
      }
 
      if(game->state.keyPressed == 2) {
        printf("> _%c_", game->state.board[i][j]);
      }

     if(game->state.keyPressed == 3) {
        printf("> _%c_", game->state.board[i][j]);
      }

      printf("%d", game->state.keyPressed);

     printf(" _%c_", game->state.board[i][j]);

        if(j != game->config.COLS - 1)
        {
          printf("|");
        }     
    
    }

      printf("\n");
    
  }
}


//baixo 80 
//cima 72

void gameControl(struct Game *game) {
  render(game);
  while(true) {

      game->state.keyPressed = getch();
    
      if(game->state.keyPressed == 13) {
          break;
      }
    printf("%d", game->state.keyPressed);
      //
    //  if(game->state.keyPressed == 72) {
    //       game->players.current = game->players.current++;
    // } 
    //
    //   if(game->state.keyPressed == 80) {
    //       game->players.current = game->players.current--;
    //   }
    //
    clear_screen();
    render(game);

  }

    printf("%d", game->state.keyPressed);



}




void showPlayers(struct Game* game) {
  clear_screen();

  printf("Choose one:\n");
  printf("%c %c \n" , (game->players.current == 1 ? '>' : ' '), game->players.player1);
  printf("%c %c \n", (game->players.current == 2 ? '>' : ' '), game->players.player2);

}



void init(struct Game* game) {

    showPlayers(game);

    while(true) {

      game->state.keyPressed = getch();
    
      if(game->state.keyPressed == 13) {
        
          break;

      } 
    
      if(game->state.keyPressed == 72) {
      
          game->players.current = game->players.current == 1 ? 2 : 1;

      } 

      if(game->state.keyPressed == 80) {

          game->players.current = game->players.current == 2 ? 1 : 2;

      }


      showPlayers(game);

  }
  clear_screen();

}





int main() {
      struct Config config = { 3, 3 };
      struct Players players = { 'X', 'O', 1};
      struct State state = { 
    { 
      { ' ', ' ', ' '}, 
      {' ', ' ', ' ' }, 
      { ' ', ' ', ' '} 
    },
    0
  };

  struct Game game = { config, players, state};

  init(&game);
  gameControl(&game);
  printf("%d", game.players.current);
  // run();
  return 0;
}
