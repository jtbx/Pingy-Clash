#include <stdlib.h>
#include <stdio.h>

#include "battle.h"
#include "utils.h"


void beginturn(monster *player, monster *enemy, monster *active) {
	char tmp[2];

    printf("| %s's HP: %.0f | %s's HP: %.0f |\n", player->name, player->hp, enemy->name, enemy->hp);
    printf("It's %s's turn!    \n", active->name);
    printf("Press the enter key to continue\n\n");
    sfgets(tmp, 2);
}

/* The function that executes the player's turn. */
void playerturn(monster *player, monster *enemy, char *input) {
	beginturn(player, enemy, player);
    enemy->hp -= (((player->atk / enemy->def) * 10) + rand() % 15);
}

/* The function that executes the enemy's turn. */
void enemyturn(monster *player, monster *enemy, char *input) {
	beginturn(player, enemy, enemy);
    player->hp -= (((enemy->atk / player->def) * 10) + rand() % 15);
}

/* The function that shows the monster's stats */
void showstats(char *str, monster *monster) {
    printf("\n%s                  \n", str);
    printf("   Name: %s \n", monster->name);
    printf(" Health: %.0f \n", monster->hp);
    printf(" Attack: %.0f\n", monster->atk);
    printf("Defense: %.0f\n", monster->def);
    printf("  Speed: %.0f\n", monster->spd);
}
