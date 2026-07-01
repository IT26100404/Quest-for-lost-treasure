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
char hiddenTrap[SIZE][SIZE];

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
			break;
		}
	}
}
void processTile(){

	int r = player1.row;
	int c = player1.col;

	if (map[r][c] == 'T'){

		player1.score += 10;
		map[r][c] = '.';
		printf("Treasure collected! +10 score\n");
	}
	else if (map[r][c] == 'H'){

		player1.health += 20;

		if(player1.health > 100)
			player1.health = 100;
		
		map[r][c] = '.';
		printf("Health restored! +20 HP\n");
	}else if (map[r][c] == 'K'){

		player1.keys++;

		map[r][c] = '.';
		printf("Key collected!\n");
	}else if(hiddenTrap[r][c] == 'X'){

		player1.health -= 20;

		hiddenTrap[r][c] = '.';

		printf("Trap triggered! -20 HP\n");

		if(player1.health < 0){

			player1.health = 0;
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
	}else if (map[newRow][newCol] =='D'){

		if (player1.keys > 0)
		{
			player1.keys--;
			map[newRow][newCol] = '.';
			printf("Door unlocked!\n");
		}
		else {
			printf("You need a key!\n");
			return;
		}
	}

	player1.row = newRow;
	player1.col = newCol;

	processTile();
}
void initializeMap(){

	int i, j;

	for (i = 0; i < SIZE; i++){
		for (j = 0; j < SIZE; j++){

			hiddenTrap[i][j] = '.';

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
			if (i == player1.row && j == player1.col)
				printf("1 ");
			else
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
void placeHealthPacks(){

	int count = 0;

	while(count < 5){

		int x = rand() % SIZE;
		int y = rand() % SIZE;

		if(map[x][y] == '.'){

			map[x][y] = 'H';
			count++;
		}
	}
}
void placeKeys(){

	int count = 0;

	while (count < 3){

		int x = rand() % SIZE;
		int y = rand() % SIZE;

		if (map[x][y] == '.'){

			map[x][y] = 'K';
			count++;

		}
	}
}
void placeTraps(){

	int count = 0;

	while(count < 10){

		int x = rand() % SIZE;
		int y = rand() % SIZE;

		if(map[x][y] == '.' && hiddenTrap[x][y] == '.')
		{
			hiddenTrap[x][y] = 'X';
			count++;
		}
	}
}
void placeDoors(){

	int count = 0;

	while(count < 3){

		int x = rand() % SIZE;
		int y = rand() % SIZE;

		if (map[x][y] == '.'){

			map[x][y] = 'D';
			count++;
		}
	}
}
int remainingTreasures(){

	int i, j;
	int count = 0;

	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			if (map[i][j] =='T'){

				count++;
			}
		}
	}
	return count;
}
void gameLoop(){

	while(remainingTreasures() > 0){

		printf("\n");
		printf("Remaining treasures = %d\n", remainingTreasures());
		printMap();
		movePlayer();
	}

	printf("\nCongratulations!\n");
	printf("All treasures collected!\n");
}
			
int main (){

	printf("\nQuest for the Lost Treasure\n");

	srand(time(NULL));

	initializeMap();
	placeWalls();
	placeTreasures();
	placeHealthPacks();
	placeKeys();
	placeTraps();
	placeDoors();
	placePlayer();
	
	gameLoop();
	
	return 0;

}
