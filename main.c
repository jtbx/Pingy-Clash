#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "battle.h"
#include "utils.h"

#define checkhp(player, enemy)             \
	if ((player).hp < 1 || (enemy).hp < 1) \
		break;


int main(int argc, char *argv[]) {
	/* The local variables defined within the main function. */
	monster player = {"_", 1, 1, 1, 1};
	monster enemy = {"Pingy Chad", 250, 250, 250, 250};
	char    input[20] = "_";
	int     points = 1000;
	/* Random module setup using the time module. */
	srand(time(0));
	/* The introduction of the game and the ASCII title. */
	printf(" _____ _                      _____ _           _          \n");
	printf("|  __ (_)                    / ____| |         | |         \n");
	printf("| |__) | _ __   __ _ _   _  | |    | | __ _ ___| |__       \n");
	printf("|  ___/ | '_ \\ / _` | | | | | |    | |/ _` / __| '_ \\    \n");
	printf("| |   | | | | | (_| | |_| | | |____| | (_| \\__ \\ | | |   \n");
	printf("|_|   |_|_| |_|\\__, |\\__, |  \\_____|_|\\__,_|___/_| |_| \n");
	printf("                __/ | __/ |                                \n");
	printf("               |___/ |___/                                 \n");
	printf("\nWelcome to Pingy Clash, a battle TUI game made with C.   \n");
	printf("The project is open source and the source code is available  ");
	printf("on my github.\nI hope you enjoy the game as much as I enjoyed");
	printf("coding it!\n");
	/* The setup of the player's monster's stats and name. */
	do {
		printf("\nYou may now enter the name of your monster > ");
		sfgets(input, 20);
	} while (strlen(input) < 1 || input[0] == '\0');
	strcpy(player.name, input);
	for (statistic s = HEALTH; s < 4; s++) {
		char str[10] = "_";
		long n; /* number of points given by user */
		strcpy(str,
			s == HEALTH ?  "health" :
			s == ATTACK ?  "attack" :
			s == DEFNSE ? "defense" :
			"speed"
		);
		do {
			printf("\nSet your monster's %s points (%d points left) > ", str, points);
			sfgets(input, 20);
			n = strtol(input, NULL, 10);
		} while (n > points || n < 0);
		points -= n;
		switch (s) {
			case HEALTH:
				player.hp += n;
			case ATTACK:
				player.atk += n;
			case DEFNSE:
				player.def += n;
			default:
				player.spd += n;
		}
	}
	showstats("Your monster's stats are:", &player);
	showstats("The enemy monster's stats are:", &enemy);
	/* The battle against the premade enemy monster bot */
	printf("\nLet the battle begin!\n\n");
	for (;;) {
		if (player.spd + (rand() % 10) >= enemy.spd + (rand() % 10)) {
			checkhp(player, enemy);
			playerturn(&player, &enemy, input);
			checkhp(player, enemy);
			enemyturn(&player, &enemy, input);
		} else {
			checkhp(player, enemy);
			enemyturn(&player, &enemy, input);
			checkhp(player, enemy);
			playerturn(&player, &enemy, input);
		}
	}
	/* The winner's hall of fame and the credits. */
	printf("%s is the winner!\n", (player.hp < 1 ? enemy : player).name);

	return 0;
}
