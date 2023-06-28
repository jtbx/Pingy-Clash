typedef struct monster {
    char  name[20];
    float hp;
    float atk;
    float def;
    float spd;
} monster;

int   sfgets(char*, int);
char* wait(unsigned int);
int   wprint(char*, int);
int   playerturn(monster*, monster*, char*);
int   enemyturn(monster*, monster*, char*);
int showstats(char*, monster*);