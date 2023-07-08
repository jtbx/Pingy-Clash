#include "utils.h"

#ifndef _BATTLE_H_

#define _BATTLE_H_

typedef struct monster {
	char  name[20];
	float hp;
	float atk;
	float def;
	float spd;
} monster;

typedef enum statistic {
	HEALTH,
	ATTACK,
	DEFNSE,
	SPEED
} statistic;

void beginturn(monster *, monster *, monster *);
void playerturn(monster *, monster *, char *);
void enemyturn(monster *, monster *, char *);
void showstats(char *, monster *);

#endif
