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
		if (birthMonth < t->tm_mon + 1) {
			age = t->tm_year - birthYear;
		} else if (birthMonth == t->tm_mon + 1) {
			if (birthDay <= t->tm_mday) {
				age = t->tm_year - birthYear;
			} else {
				age = t->tm_year - birthYear - 1;
			}
		} else {
			age = t->tm_year - birthYear - 1;
		}
		birthYear += 1900; 
		
	} else if (gender == 3 || gender == 4) { // born in 20xx
		t->tm_year -= 100; // submit 100 from the this year 
		
		if (birthMonth < t->tm_mon + 1) {
			age = t->tm_year - birthYear;
		} else if (birthMonth == t->tm_mon + 1) {
			if (birthDay <= t->tm_mday) {
				age = t->tm_year - birthYear;
			} else {
				age = t->tm_year - birthYear - 1;
			}
		} else {
			age = t->tm_year - birthYear - 1;
		}
		birthYear += 2000; 
	} else {
		printf("error! enter correctly");
	}	
	printf("Birthday: %d-%d-%d\n", birthYear,birthMonth,birthDay);	
	printf("age: %d\n", age);	
}

