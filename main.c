#include<stdio.h>
#include<stdlib.h>

//Variables//
char* playername;
int playerhealth;
int enemyhealth;
int playerattackpower;
int enemyattackpower;
int healpower;
int score;
int* player_boostitems;
int* player_healitems;
int* player_dmgitems; 
int* boostitem_effects;
int* healitem_effects;
int* dmgitem_effects;
char* dmgitem_names;
char* boostitem_names;
char* healitem_names;

int main void () {

char buffer[256];
int startinput;

printf("Welcome to EndlessBattle!\n");
printf("Press 1 to Start\n");
printf("Press 0 for Information\n");

fgets(buffer, 255, stdin);

sscanf(buffer, "%i", &startinput); 

if startinput == 0 {
	printf(" This is 

}

