#include <stdio.h>
#include <math.h>

const double EPS = 1e-5;

int printMenu()
{
	printf("--MENU--\n");
	printf("1) A\n");
	printf("2) B\n");
	printf("3) C\n");
	printf("4) Exit\n");
	printf("Input number:\n");
	int result;
	int scanCode = scanf("%d", &result);
	fflush(stdin); //очистка буфера, для std::cin необходимо использовать std::cin.clear() перед fflush(stdin)
	if (scanCode != 1 || result < 1 || result > 4) {
		return -1;
	}
	return result;
}

int main()
{
	int result;
	do
	{
		result = printMenu();
		if (result == -1)
		{
			printf("Wrong number! Retry input.\n");
		}
		else if (result == 1)
		{
			printf("Calculations for A.\n");
		}
		else if (result == 2)
		{
			printf("Calculations for B.\n");
		}
		else if (result == 3)
		{
			printf("Calculations for C.\n");
		}
		else
		{
			printf("Exit...\n");
			return 0;
		}
	} while (result != 4);
}
