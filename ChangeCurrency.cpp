#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int money, num, foreignMoney, change, han1000, han500, han100, han50, han10;
	double rate; 

	printf("How much money do you want to change? (Korean won -> foreign currency)\n");
	scanf("%d", &money);

	printf("1. US dollar \n2. Japan Yen \n3. China Yuan \n4. Europe Euro \n5. UK Pound \n");
	printf("Which currency do you want?\n");
	scanf("%d", &num);
	
	if (num < 1 || num > 5) {
		printf("Choose from 1 to 5");
	} else {
		if (num == 1) {
			rate = 0.00076;
			printf("Dollar : ");	
		} else if (num == 2) {
			rate = 0.1;
			printf("Yen : ");
		}
		else if (num == 3) {
			rate = 0.0052;
			printf("Yuan : ");
			}
		else if (num == 4) { 
			rate = 0.00069;
			printf("Euro : ");
		}
		else if (num == 5) {
			rate = 0.00061;
			printf("Pound : ");
		}
		
		foreignMoney = (int)(money * rate); // drop decimal places 
		change = money - (foreignMoney / rate);
	
		change = (change / 10) * 10; // drop under 10 won
	
		han1000 = change / 1000;
		han500 = (change % 1000) / 500;
		han100 = (change % 500) / 100;
		han50 = (change % 100) / 50;
		han10 = (change % 50) / 10;
		
		printf("%d, Change : %dwon\n", foreignMoney,change);
		printf("1000won - %d\n", han1000);
		printf("500won - %d\n", han500);
		printf("100won - %d\n", han100);
		printf("50won - %d\n", han50);
		printf("10won - %d\n", han10);
	}

	
}
