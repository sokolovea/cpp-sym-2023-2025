#include <stdio.h>

int main() {
	int a, b;
	a = 17;
	b = 31;
	printf("a < b: %d\n", a < b);
	printf("a > b: %d\n", a > b);
	int numericResult = a < b; //1
	// bool booleanResult = a < b; //#include <stdbool.h> для использования в языке C
	
	int weekday = 5;
	
	if (weekday == 6 || weekday == 7)
	{
		printf("It is Saturday or Sunday.\n");
	}
	else if (weekday <= 3)
	{
		printf("It is Monday or Tuesday or Wednesday.\n");
	}
	else if (4 == weekday) 
	{
		printf("It is Thursday.\n");
	}
	else
	{
		printf("It is Friday.\n");	
	}
	
	printf("---\n");
	
	switch(weekday)
	{
		case 1:	printf("It is Moday.\n");
				break; 
		case 2: printf("It is Moday.\n");
				break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		default:
				printf("It is another day.\n");
				//break;
	}
	
	printf("---\n");
	printf("%d\n", !3); //0
	printf("%d\n", !0 && 1 || 30); //1
	printf("%d\n", 1 > 2 && (4 / 0) != 1); // :-)
	printf("---\n");
	
	a = 7;
	if ((a = 5)) {
		printf("YES!\n");
	}
	printf("%d\n", a);

	return 0;
}
