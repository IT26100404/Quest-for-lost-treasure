#include <stdio.h>
#include <stdlib.h>
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

int main (){

	printf("\nQuest for the Lost Treasure\n");

	srand(time(NULL));

	initializeMap();
	placeWalls();
	placePlayer();
	printMap();

	return 0;

}
