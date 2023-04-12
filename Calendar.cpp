#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	while (true) {
		
		int year = 0, month = 0, countDays = 0, firstDay = 0;
		int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		
		printf("Press 0 if you want to exit\n");
		printf("Year : ");
		scanf("%d", &year);
		
		if(year == 0) {
			printf("exit");
			break;
		}
		printf("Month : ");
		scanf("%d", &month);
		printf("===================== %d, %d =====================\n", year, month);
		printf("SUN	MON	TUE	WED	THU	FRI	SAT\n");
	
		if ((year % 4 == 0 && year %100 != 0) || year % 400 == 0) { // 29days in FEB of a leap year 
			months[1] = 29;	
		}	
		for (int i = 1900; i < year; i++) {
			if ((i % 4 == 0 && i %100 != 0) || i % 400 == 0) {
				countDays += 366;
			} else {
				countDays += 365;
			}
		}
		for (int i = 0; i < month - 1; i++) {
			countDays += months[i];
		} 
		firstDay = (countDays + 1) % 7; // The day of the first date
	
		for (int i = 1; i <= months[month - 1]; i++) { //  print dates
			if (i == 1) { // blank before the first day
				for (int j = 0; j < firstDay; j++) {
					printf("\t");
				}
			}
			printf("%2d\t", i);
			
			if (firstDay % 7 == 6) { // new line after Saturday 
				printf("\n");
			}
			firstDay++;
		} 
		 printf("\n");
	 } 
}
