#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
char map[SIZE][SIZE];

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
	printMap();

	return 0;

}
