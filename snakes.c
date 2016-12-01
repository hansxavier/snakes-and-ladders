#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//linked list for players
typedef struct players{
	char name[50];
	char symbol;
	struct players *nextPlayer;
}playerData;

//definitions
void Menu();
void Tutorial();
int gameboard();

//main function
int main(){
	int choice;
	playerData *player;
	player = NULL;

		do{
		Menu();
		scanf("%d", &choice);

			if(choice==1){
				printf("\n");
				gameboard();
			}
			else if(choice==2){
				Tutorial();
				return main();
			}
			else if(choice==3){
				return 0;
			}
			else{
				printf("Error! choose again!\n");
			}
		}while(choice!=3);
}

//menu screen & choices
void Menu(){
	printf("\n_______________________________________________\n");
	printf("\n[1] Start the game\n");
	printf("[2] Tutorial\n");
	printf("[3] Exit\n");
	printf("Choice: ");
}

//tutorial screen choice
void Tutorial(){
	system("cls");
	printf("\nHello and welcome to Snakes and Ladders!\n");
	printf("Before starting, please ensure that you enter player data first ^^\n");
	printf("If not, chances are the game will crash and you won't have a fun time >_>\n");
	printf("Enjoy and have fun!\n");
}

//snakes and ladders main display board
int gameboard(){
	char board[8][8];
	char piece;
	int row, column;
	int rowpos = 7, colpos = 0;
//clears screen
	system("cls");
//asks for character piece
	printf("Enter character piece: ");
	scanf("%s", &piece);
	printf("\n");
//sets elements of array as blank
	   for(row = 0; row <9; row++){
	   	for(column = 0; column <9; column++){
	   		board[row][column] = '@';
	   	}
	   }
//display character piece
	board[rowpos][colpos] = piece;
//displays board
	   for(row = 0; row < 8; row++){
	   	for(column = 0; column < 8; column++){
	        printf("|%c", board[row][column]);
	    }
	    printf("|\n");
	   }
//______________________________________________________________
//moving the piece
	int dice, roll;
	printf("\nEnter 1 to roll the dice: ");
	scanf("%d", &dice);

	if(dice == 1){
		roll = rand() % 6 + 1;
		printf("You roll a %d!\n", roll);
		colpos = colpos + roll;
		
	}else{
		printf("Error!");
	}

}
