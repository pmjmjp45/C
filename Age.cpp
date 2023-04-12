#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
 
int main() 
{
	int number, age, birthYear, birthMonth, birthDay, gender;
	struct tm* t; 
	time_t base = time(NULL); 
	t = localtime(&base); 
	
	printf("Enter the first 7 digits of your social number\n");
	printf("example) 9001011, 0001014\n"); 
	scanf("%d", &number);
	
	gender = number % 10;
	number /= 10;
	birthDay = number % 100;
	number /= 100;
	birthMonth = number % 100;
	number /=100;
	birthYear = number;
	
	if(gender == 1 || gender == 2) { // born in 19xx 
		birthYear += 1900;
	} else if (gender == 3 || gender == 4) { // born in 20xx
		birthYear += 2000;
	} else {
		printf("error! enter correctly");
	}	
	
	age = t->tm_year + 1900 - birthYear;
    
	if (birthMonth > t->tm_mon + 1 || (birthMonth == t->tm_mon + 1 && birthDay > t->tm_mday)) {
        age--; // before the birthday, age--
    }
	printf("Birthday: %d-%d-%d\n", birthYear,birthMonth,birthDay);	
	printf("age: %d\n", age);	
}

