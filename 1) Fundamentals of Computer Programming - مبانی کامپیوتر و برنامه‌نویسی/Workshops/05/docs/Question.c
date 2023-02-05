#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() {
	int goal;
	int player_choice, bot_choice;
	int player_score = 0, bot_score = 0;

	printf("Enter the Goal:\n");
	scanf("%d", &goal);
	
	while (player_score < goal && bot_score < goal) {
		//print the scores at the top of the window
		printf("Your score : %d\t\tBot score : %d\n\n", player_score, bot_score);

		//get player choice
		printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n");
		scanf("%d", &player_choice);

		//make a random choice for the computer
		srand(time(NULL));
		bot_choice = rand() % 3 + 1;

		// Update players' scores with correct conditions.
        // 
        // if (/* condition */) {
		//      Write your code here
		// }
		// else if (/* condition */) {
        //      Write your code here
        // }
        // ...

		//clear the console
		Sleep(2000);
		system("cls");
	}

	//print final result
	printf("Your score : %d\t\tBot score : %d\n\n", player_score, bot_score);

    // Check who is the winner and congrats him/her/it!!
	// Write your code here
}