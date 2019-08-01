#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
	printf("//////////////////////////////////\n");
	printf("////////////////MENU//////////////\n");
	printf("//////////////////////////////////\n");
	printf("Adjust difficulty        - press d\n");
	printf("Play                     - press p\n");
	printf("Quit                     - press q\n");
}

void difficulty() {
	printf("//////////////////////////////////\n");
	printf("////////////DIFFICULTY////////////\n");
	printf("//////////////////////////////////\n");
	printf("Level 1                  - press 1\n");
	printf("Level 2                  - press 2\n");
	printf("Level 3                  - press 3\n");
}

void clearBuffer() {
	int c = getchar();
	while (c != EOF && c != '\n')
		c = getchar();
}

int main(int argc, char** argv) {
	int mystery, number, count, max = 100, again, quit = 0;
	const int min = 1;
	char input;
	srand(time(NULL));	// Initialisation of the seed

	do {
		menu();
		scanf(" %c", &input);
		while (input != 'd' && input != 'p' && input != 'q') {
			printf("please select between d, p and q\n");
			clearBuffer();
			scanf(" %c", &input);
		}

		if (input == 'd') {
			difficulty();
			scanf(" %c", &input);
			while (input != '1' && input != '2' && input != '3') {
				printf("please select between 1, 2 and 3\n");
				clearBuffer();
				scanf(" %c", &input);
			}
			if (input == '1')
				max = 100;
			else if (input == '2')
				max = 1000;
			else
				max = 10000;
		}

		else if (input == 'p') {
			printf("//////////////////////////////////\n");
			do {	// While user want to play again

				mystery = (rand() % (max - min + 1)) + min;	// Generation of the random number
				count = 0;	// Initialisation of the number of trials

				do {	// While user do not find the mysterious number

					printf("Try a number ! ");	// Asking for the mysterious number
					scanf("%d", &number);

					count += 1;	// Incrementing the number of trials

					if (mystery > number)	// Tests between input number and mysterious number
						printf("It is more !\n\n");
					else if (mystery < number)
						printf("It is less !\n\n");
					else
						printf ("Congratulation, you have found the mystery number in %d moves !!!\n\n", count);

				} while (mystery != number);

				do {	// Asking for a new game
					printf("Do you want to play again ? (y/n) ");
					scanf(" %c", &input);
				} while (input != 'y' && input != 'n');

				again = input == 'y' ? 1 : 0;

			} while (again);
		}

		else {
			quit = 1;
		}

		clearBuffer();

	} while (!quit);

	printf("Bye-Bye !\n");

	return 0;
}
