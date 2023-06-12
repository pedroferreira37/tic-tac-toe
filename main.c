#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <conio.h>
#include <stdbool.h>


const int BOARD_ROWS = 3;
const int BOARD_COLS = 3;
int MOVES = BOARD_ROWS * BOARD_COLS;

char PLAYER_ONE = 'X';
char PLAYER_TWO = 'O';
int PLAYER_SELECTED = 1;

int keyPressed;


char board[3][3] = { 
  {' ', ' ', ' '}, 
  {' ', ' ', ' '}, 
  {' ', ' ', ' '}
};


void clear() {
  system("cls");
}



void render(char board[3][3]) {
  for(int i = 0; i < BOARD_ROWS; i ++)  {
    for(int j = 0; j < BOARD_COLS; j++) {
      printf("_%c_", board[i][j]);
      if(j != BOARD_ROWS - 1)
      {
        printf("|");
      }     
    }

    printf("\n");
  }
}


void showAvailablePlayers() {
  clear();

  printf("Choose one:\n");
  printf("%c %c \n" , (PLAYER_SELECTED == 1 ? '>' : ' '), PLAYER_ONE);
  printf("%c %c \n", (PLAYER_SELECTED== 2 ? '>' : ' '), PLAYER_TWO);

}

void init() {
  showAvailablePlayers();


  while(true) {
    keyPressed = getch();
    
    if(keyPressed == 13) {
      break;
    } 
    
    if(keyPressed == 72) {
      PLAYER_SELECTED = PLAYER_SELECTED == 1 ? 2 : 1;
    } 

    if(keyPressed == 80) {
      PLAYER_SELECTED = PLAYER_SELECTED == 2 ? 1 : 2;
    }

    showAvailablePlayers();

  }


  clear();

  printf("%c" , PLAYER_SELECTED == 1 ? PLAYER_ONE : PLAYER_TWO);
}





void run() {
  int row;
  int col;

  while(MOVES > 0) {


    // remove this to make the same as the options
    printf("Enter row position(only number): ");
    scanf("%d", &row);


    // remove this to make the same as the options
    printf("Enter column position(only number): ");
    scanf("%d", &col);
    

    if(board[row - 1][col - 1] == ' ') {
      board[row - 1][col - 1] = PLAYER_SELECTED == 1 ? PLAYER_ONE : PLAYER_TWO;
    }

    clear();
    render(board);

    MOVES--;
  }

}

int main() {
  init();
  run();
  return 0;
}
