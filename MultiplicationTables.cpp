#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int number;
	
	printf("How many colums do you want in one line? : ");
	scanf("%d", &number);
	
	if(number > 0 && number < 10) {
		for (int i = 1; i < 10; i += number) {
			for (int j = 1; j < 10; j++) { 
				for (int k = 0; k < number; k++) {
					printf("%d * %d = %d\t", (i + k), j, ((i + k) * j));
					if ((i + k) >= 9) break;  
				}	
				printf("\n");
			}
			printf("\n");
		}
	} else {
		printf("Choose from 1 to 9");
	}
}

