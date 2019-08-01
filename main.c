#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv) {
	int mystery, input, count, max, min;
	char again;
	const int MAX = 100, MIN = 1;
	srand(time(NULL));	// Initialisation of the seed

	do {	// While user want to play again

		mystery = (rand() % (MAX - MIN + 1)) + MIN;	// Generation of the random number
		count = 0;	// Initialisation of the number of trials

		do {	// While user do not find the mysterious number

			printf("Try a number ! ");	// Asking for the mysterious number
			scanf("%d", &input);

			count += 1;	// Incrementing the number of trials

			if (mystery > input)	// Tests between input number and mysterious number
				printf("It is more !\n\n");
			else if (mystery < input)
				printf("It is less !\n\n");
			else
				printf ("Congratulation, you have found the mystery number in %d moves !!!\n\n", count);

		} while (mystery != input);

		do {	// Asking for a new game
			printf("Do you want to play again ? (y/n) ");
			scanf(" %c", &again);
		} while (again != 'y' && again != 'n');

	} while (again == 'y');

	return 0;
}
