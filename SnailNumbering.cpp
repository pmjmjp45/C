#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int input;
	
	printf("Size of the table you want : ");
	scanf("%d", &input); 
	
	int directionX[] = {1,0,-1,0};
	int directionY[] = {0,1,0,-1};
	int place[100][100]; // !!!!initializing of Arrayshould be integer!!!! or use malloc 
	int newX= 0, newY = 0, x = 0, y = 0, d = 0;

	for (int i = 1; i <= (input * input); i++) { // numbering
		place[x][y] = i;
	
		newX = x + directionX[d];
		newY = y + directionY[d];
		
		// condition of the corner
		if (newX < 0 || newX >= input || newY < 0 || newY >= input || place[newX][newY] != 0) {
			d = (d + 1) % 4;
			newX = x + directionX[d];
			newY = y + directionY[d];	
		} 
		x = newX;
		y = newY;
	}
	for (int i = 0; i < input; i++) { // print out in order of the array 
		for (int j = 0; j < input; j++) {
			printf("%3d ", place[j][i]);
			
		}
		printf("\n");
	} 
}
