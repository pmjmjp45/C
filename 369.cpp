#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <windows.h> 
#define G 1567.982 // sound 

int main()
{
	int input;
	char charToString[10];  
	printf("Enter the limit number : ");
	scanf("%d", &input);
	
	for (int i = 1; i <= input; i++) {
		sprintf(charToString, "%d", i); // int -> string 
		
		if (strstr(charToString, "3") != NULL || strstr(charToString, "6") != NULL || strstr(charToString, "9") != NULL) { 
			// if string includes '3/6/9'
			for (int j = 0; charToString[j] != '\0'; j++) { // one char by one char 
				if (charToString[j] == '3' || charToString[j] == '6' || charToString[j] == '9') {
				printf(">>%s<<",charToString); // print the number
				Beep(G, 500); // make beep sound
				}
			} 
			printf("\n"); 
			Sleep(500); // wait for 0.5 sec 
			
		} else {  
			printf("%s\n",charToString); 
			Sleep(500); 
		}
	}
}
