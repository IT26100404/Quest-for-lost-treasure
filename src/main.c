#include <stdio.h>

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
int main (){

	initializeMap();
	printMap();

	return 0;

}
