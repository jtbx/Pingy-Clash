#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils.h"

int main(void) {
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
    printf("coding it!                                                \n");
    /* The setup of the player's monster's stats and name. */
    do {
        printf("\nYou may now enter the name of your monster > ");
        sfgets(input, 20);
    } while (strlen(input) < 1 || input[0] == '\0');
    strcpy(player.name, input);
    for (int i = 0; i < 4; i++) {
        char str[10] = "_";
		long n; /* number of points given by user */
        if (i == 0) strcpy(str, "health");
        else if (i == 1) strcpy(str, "attack");
        else if (i == 2) strcpy(str, "defense");
        else strcpy(str, "speed");
        do {
            printf("\nSet your monster's %s points (%d points left) > ", str, points);
            sfgets(input, 20);
			n = strtol(input, NULL, 10);
        } while (n > points || n < 0);
        points -= n;
        if (i == 0) player.hp += n;
        else if (i == 1) player.atk += n;
        else if (i == 2) player.def += n;
        else player.spd += n;
    }
    showstats("Your monster's stats are:", &player);
    showstats("The enemy monster's stats are:", &enemy);
    /* The battle against the premade enemy monster bot */
    printf("\nLet the battle begin!\n\n");
    for (;;) {
        if ((player.spd + (rand() % 10)) >= (enemy.spd + (rand() % 10))) {
            if (player.hp < 1 || enemy.hp < 1) break;
            else playerturn(&player, &enemy, input);
            if (player.hp < 1 || enemy.hp < 1) break;
            else enemyturn(&player, &enemy, input);
        }
        else {
            if (player.hp < 1 || enemy.hp < 1) break;
            else enemyturn(&player, &enemy, input);
            if (player.hp < 1 || enemy.hp < 1) break;
            else playerturn(&player, &enemy, input);
        }
    }
    /* The winner's hall of fame and the credits. */
    if (player.hp < 1) printf("\n%s is the winner!", enemy.name);
    else printf("%s is the winner!\n", player.name);
    return 0;
}

/* The function that executes the player's turn. */
int playerturn(monster* player, monster* enemy, char* input) {
    printf("|%s's HP: %.0f| - |%s's HP: %.0f|\n", player->name, player->hp, enemy->name, enemy->hp);
    printf("It's %s's turn!   \n", player->name);
    printf("Press the enter key to continue\n\n");
    sfgets(input, 20);
    enemy->hp -= (((player->atk / enemy->def) * 10) + rand() % 15);
    return 1;
}

/* The function that executes the enemy's turn. */
int enemyturn(monster* player, monster* enemy, char* input) {
    printf("|%s's HP: %.0f| - |%s's HP: %.0f|\n", player->name, player->hp, enemy->name, enemy->hp);
    printf("It's %s's turn!    \n", enemy->name);
    printf("Press the enter key to continue\n\n");
    sfgets(input, 20);
    player->hp -= (((enemy->atk / player->def) * 10) + rand() % 15);
    return 1;
}

/* The function that shows the monster's stats */
int showstats(char* str, monster* monster) {
    printf("\n%s                  \n", str);
    printf("Name:    %s \n", monster->name);
    printf("Health:  %.0f \n", monster->hp);
    printf("Attack:  %.0f\n", monster->atk);
    printf("Defense: %.0f\n", monster->def);
    printf("Speed:   %.0f\n", monster->spd);
    return 1;
}

// vi: ff=dos
