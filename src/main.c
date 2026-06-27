#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 15

typedef struct {

	char name[50];
	int row;
	int col;
	int score;
	int health;
	int keys;
	char symbol;

}Player;

char map[SIZE][SIZE];

Player player1;

void placePlayer(){

	int x, y;

	while(1){
		x = rand() % SIZE;
		y = rand() % SIZE;

		if(map[x][y] == '.'){

			player1.row = x;
			player1.col = y;
			player1.score = 0;
			player1.health = 100;
			player1.keys = 0;
			player1.symbol = '1';

			map[x][y] = player1.symbol;
			break;
		}
	}
}
void movePlayer() {
	
	char move;
	int newRow = player1.row;
	int newCol = player1.col;

	printf("\nEnter move (W/A/S/D): ");
	scanf(" %c", &move);

	switch(move)
	{
		case 'W':
		case 'w':
			newRow--;
			break;
		case 'S':
		case 's':
			newRow++;
			break;
		case 'A':
		case 'a':
			newCol--;
			break;
		case 'D':
		case 'd':
			newCol++;
			break;
		default:
			printf("Invalid move\n");
			return;
	}
	if (map[newRow][newCol] == '#'){

		printf("Wall hit\n");
		return;
	}
	map[player1.row][player1.col] = '.';

	player1.row = newRow;
	player1.col = newCol;

	map[player1.row][player1.col] = player1.symbol;
}

void initializeMap(){

	int i, j;

	for (i = 0; i < SIZE; i++){
		for (j = 0; j < SIZE; j++){
			if (i == 0 || i == SIZE - 1 || j == 0 || j == SIZE - 1){
				map[i][j] = '#';
			}
			else {
				map[i][j] = '.';
			}
		}
	}
}
void printMap(){
	
	int i, j;

	for (i = 0; i < SIZE; i++){
		for (j = 0; j < SIZE; j++){
			printf("%c ", map[i][j]);
		}
	printf("\n");
	}

	printf("\n---------------------------------------\n");
	printf("Player Information\n");
	printf("-----------------------------------------\n");
	printf("Health : %d\n", player1.health);
	printf("Score  : %d\n", player1.score);
	printf("Keys   : %d\n", player1.keys);
	printf("-----------------------------------------\n");
}
void placeWalls(){
	int count = 0;

	while (count < 30){
		int x = rand() % SIZE;
		int y = rand() % SIZE;

		if (x == 0 || x == SIZE - 1 || y == 0 || y == SIZE - 1)
			continue;
		if (map[x][y] == '.')
		{
			map[x][y] = '#';
			count++;
		}
	}
}
void placeTreasures(){

	int count = 0;

	while(count < 12){
		int x = rand() % SIZE;
		int y = rand() % SIZE;

		if(x == 0 || x == SIZE - 1 || y == 0 || y == SIZE - 1)
			continue;
		if(map[x][y] == '.'){

			map[x][y] = 'T';
			count++;
		}
	}
}
int main (){

	printf("\nQuest for the Lost Treasure\n");

	srand(time(NULL));

	initializeMap();
	placeWalls();
	placeTreasures();
	placePlayer();
	
	printMap();
	
	movePlayer();

	printf("\nAfter Move:\n");
	
	printMap();

	return 0;

}
