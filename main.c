//EndlessBattle - main.c
/* Notes

Item management setup:
player_items[BOOST][1] ==> n 
items name: boostitem_names[n]
effect: boostitem_effects[n]
if n == -1, then no item

REMOVING STAR
 */

//=================headers=================//
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>
//#include"star.h"

//==============global vars================//
int boostitem_effects[3];
int healitem_effects[3];
int dmgitem_effects[3];
const char* const dmgitem_names[] = {"grenade", "artillery","uranium"};
const char* const boostitem_names[] = {"calcium", "proteins",  "adrenaline"};
const char* const healitem_names[] = {"beer", "milk", "vodka"};


//==========function prototypes============//
void print_description();
int randrange(int min, int max);

//returns 1 if dead, otherwise 0
int battle( int* playerhealth_p, int player_items[3][3], int healpower, int patkpower );

//give random item
void obtain_item(int player_items[3][3]);

//print all items in player bag
void print_inv(int player_items[3][3]);

void use_item(char* input, int autocomplete, int player_items[3][3], int* phealth, int* ehealth, int* patk);

//macros
#define BOOST 0
#define HEAL  1
#define DMG   2


//=============main function===============//
int main (void) {

//Variables//
char* playername;
int playerhealth;
int playerattackpower;
int healpower;
int score;
int player_items[3][3]; //1st row boost items; 2nd heal; 3rd dmgitems 
char buffer[256];
int startinput;
int i, j;

srand(time(NULL));

//Game Setup//
printf("Welcome to EndlessBattle!\n");
while (1==1) {
	
	printf("Press 1 to Start\n");
	printf("Press 0 for Information\n");

	fgets(buffer, 255, stdin);

	sscanf(buffer, "%i", &startinput); 
	
	if (startinput!= 0 && startinput != 1) {
		printf("Try again bro...\n");
		
	}
	else if (startinput == 0) {
		print_description();
	}
	else {
		break;
	}
	
}  //close input while loop


//Prompt for name//
printf("What is your name: ");
fgets(buffer, 255, stdin);
playername = strdup(buffer);
printf("Hello, %s ", playername);

//Item matrix//
for (i=0; i<=3; i++) {
	for (j=0; j<=3; j++) {
		player_items[i][j] = -1;
	}
}

//Random player stat generation//
playerhealth = randrange(100,200);
playerattackpower = randrange(20,50);
healpower = randrange(10,50);

//Item Database//
//boostitem_names = new_star();
//star_add( &boostitem_names, "calcium");
boostitem_effects[0] = 10;

//star_add( &boostitem_names, "proteins");
boostitem_effects[1] = 30;

//star_add( &boostitem_names, "adrenaline");
boostitem_effects[2] = 100;

//healitem_names = new_star();
//star_add( &healitem_names, "beer");
healitem_effects[0] = -2;

//star_add( &healitem_names, "milk");
healitem_effects[1] = 20;

//star_add( &healitem_names, "vodka");
healitem_effects[2] = 100;

//dmgitem_names = new_star();
//star_add( &dmgitem_names, "grenade");
dmgitem_effects[0] = 20;

//star_add( &dmgitem_names, "artillery");
dmgitem_effects[1] = 75;

//star_add( &dmgitem_names, "uranium");
dmgitem_effects[2] = 300;

//Battle!//
while (1) {
	int is_dead = battle( &playerhealth, player_items, healpower, playerattackpower);
	if (is_dead == 1) {
		printf("Your game is over\n");
		printf("Your final score is %i\n", score);
		break;
	}
	else {
		score++;
		printf("Your score has increased and is now %i", score);
		continue;
	}
}

//kill_star(boostitem_names);
//kill_star(healitem_names);
//kill_star(dmgitem_names);
return(0);

} //close main function


//========function definitions=============//

void print_description() {
	printf("This is a text interface game in which players spawn and are immediately \n\
faced with an unending series of battles. Each battle is turn based and \n\
involves two combatants, the player and a CPU opponent. There is no way to \n\
\"beat\" the game; high scores are represented by the number of opponents\n\
defeated in a row before a player loses all health points. During each battle,\n\
\n a player has four options: \n\
  * 1) Fight using 4 preset moves. \n\
  * 2) Use healing abilities on oneself. \n\
  * 3) Randomly obtain 1 item that will be placed in the bag (examples include healing \n\
	items, attack boost items, useless dummy items, and powerful bomb items). \n \
  * 4) Use an item that is in the bag.\n\
\
When a player selects their move, they will always execute first, and the CPU will always \n\
execute afterwards. The CPU has no access to items, and can only attack using 4 preset \n\
moves or use healing abilities on itself. When the CPU opponent is defeated, a new one \n\
will immediately spawn. Each CPU opponent will have a random quantity of health points \n\
greater than 50%% but no greater than 200%% of the player's starting health point total. \n\
Attack power is randomized with certain moves having a larger range of damage with others \n\
having a smaller range of damage, thereby making some attacks high-risk, high-reward. The \n\
player and the CPU will have the same attacks with the same base power, meaning that the \n\
player will generally be outmatched when their opponent spawns with greater hp than themselves, \n\
but will have the advantage when the opponent spawns with less hp than themselves. Items will serve\n\
 as the equalizer when players are fighting opponents with greater hp totals than themselves, with certain\n \
rare items having the ability to dispatch opponents immediately. When the player loses all health points,\n\
 the game ends, and the total number of defeated opponents represents their high score. \n");
}

int randrange(int min, int max) {
	
	int ret = rand() % (max-min) + min;

	return(ret);
 
}

int battle( int* playerhealth_p, int player_items[3][3], int healpower, int playerattackpower ) {
	
	int enemyhealth;
	int enemyattackpower;
	char* playerdecision;
	const char* const moves[] = { 
		"attack",
		"use item",
		"get item",
		 "heal",
		 "crushattack",
		 "stabattack",
		 "slashattack",
		 "swingattack"
		};
	int playerhealth = *playerhealth_p;
	char buffer[256];
	char* p;
	int autocomplete;
	int damage;
	int regain;
	//Player obtains item//
	//player uses item//
	
	enemyhealth = randrange(playerhealth*.5,playerhealth*2);
	enemyattackpower = playerattackpower*.5;
	
	printf("Battle has begun\n");
	while (enemyhealth >= 0 && playerhealth >= 0) {
		
		printf("Player health:%i\n", playerhealth);
		printf("Enemy health:%i\n", enemyhealth);
		
		printf("Choose a move\n");
		printf("\tattack\n\tget item\n\tuse item\n\theal\n");
		fgets(buffer, 255, stdin);
		*strchr(buffer,'\n') = '\0';
		if( strchr(buffer,'*')!=NULL ) {
			p = strchr(buffer, '*');
			autocomplete = (int)(p-buffer) - 1;
		}
		else {
			autocomplete = strlen(buffer);
		}
		
		if( strncmp("attack",buffer,autocomplete)==0 ) {
			printf("Choose an attack\n");
			printf("\tcrushattack\n\tstabattack\n\tslashattack\n\tswingattack\n");
			
			fgets(buffer, 255, stdin);
			*strchr(buffer,'\n') = '\0';
			if( strchr(buffer,'*')!=NULL ) {
				p = strchr(buffer, '*');
				autocomplete = (int)(p-buffer) - 1;
			}
			
			if( strncmp("crushattack",buffer,autocomplete)==0 ) {
				damage = playerattackpower*.65+14;
				enemyhealth = enemyhealth - damage;
				printf("You used crushattack, inflicting %i damage\n", damage);
				printf("The enemy has %i health left\n", enemyhealth);
			}
			else if( strncmp("stabattack",buffer,autocomplete)==0 ) {
				damage = playerattackpower*.55+18;
				enemyhealth = enemyhealth - damage;
				printf("You used stabattack, inflicting %i damage\n", damage);
				printf("The enemy has %i health left\n", enemyhealth);
			}
			else if( strncmp("slashattack",buffer,autocomplete)==0 ) {
				damage = playerattackpower*.75+12;
				enemyhealth = enemyhealth - damage;
				printf("You used slashattack, inflicting %i damage\n", damage);
				printf("The enemy has %i health left\n", enemyhealth);
			}
			else if( strncmp("swingattack",buffer,autocomplete)==0 ) {
				damage = playerattackpower*.85+8;
				enemyhealth = enemyhealth - damage;
				printf("You used swingattack, inflicting %i damage\n", damage);
				printf("The enemy has %i health left\n", enemyhealth);
			}
		}
		else if( strncmp("use item",buffer,autocomplete)==0 ) {
			printf("Player selected use item\n");
			print_inv(player_items);
			printf("Choose an Item\n");
			
			fgets(buffer, 255, stdin);
			*strchr(buffer,'\n') = '\0';
			if( strchr(buffer,'*')!=NULL ) {
				p = strchr(buffer, '*');
				autocomplete = (int)(p-buffer) - 1;
			}
			else {
				autocomplete = strlen(buffer);
			}
			
			use_item(buffer, autocomplete, player_items, &playerhealth, &enemyhealth, &playerattackpower);
		}
		else if( strncmp("get item",buffer,autocomplete)==0 ) {
				obtain_item(player_items);
		}
		else if( strncmp("heal",buffer,autocomplete)==0 ) {
			regain = 0.5*healpower;
			playerhealth += regain;
			printf("Player regained %i health\n", regain);
		}
		else {
			printf("Player's confused...\n");
		}
		
		if (enemyhealth<=0) {
			return(0);
		}
			
		//ENEMY ATTACKS THE PLAYER
		playerhealth = playerhealth - (enemyattackpower*.7);
		printf("The enemy has attacked you, you now have only %i health points left\n", playerhealth);
		if (playerhealth<=0) {
				return(1);
		}
		
	} //close turns loop

	*playerhealth_p = playerhealth;
	
}  //close battle function

//randomly adds item to player inventory
//prints item obtained to screen
//equal chance of getting anything
//if first time calling function, make first_call = 1; otherwise 0
void obtain_item(int player_items[3][3]) {
	
	int pc_boost_item = 33;
	int pc_heal_item = 33;
	//chance_dmg_item = 1 - chance_boost_item - chance_heal_item

	int r = randrange(0,100);
	int to_obtain;
	int item_type;
	int obtained = 0;
	int i, j;
	
	print_inv(player_items);
	/*
	printf("Items:====\n");
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%i_", player_items[i][j]);
		}
		printf("\n");
	}
	*/
	//generate item
	if( r<pc_boost_item ) {
		item_type = BOOST;
		to_obtain = rand()%3;  //0=calcium,1=proteins,2=adrenaline, 
	}
	else if( r<(pc_boost_item + pc_heal_item) ) {
		item_type = HEAL;
		to_obtain = rand()%3;  //0=beer,1=milk,2=vodka
	}
	else {
		item_type = DMG;
		to_obtain = rand()%3;  //0=granade,1=artillery,2=uranium
	}

	//search for empty spot
	for(i=0; i<3; i++) {
		if( player_items[item_type][i]==-1 ) {
			player_items[item_type][i] = to_obtain;
			switch(item_type) {
				case BOOST:
					printf("Player obtained %s!\n", boostitem_names[to_obtain]);
					break;  //exits switch-case
				case HEAL:
					printf("Player obtained %s!\n", healitem_names[to_obtain]);
					break;  //exits switch
				case DMG:
					printf("Player obtained %s!\n", dmgitem_names[to_obtain]);
					break;  //exits switch
				default:
					break;  //exits switch
			}
			obtained = 1;
			break;  //exits for-loop
		}
	}
	
	if( !obtained ) {  //inventory was full
		printf("Your inventory is already full! Too bad.\n");
	}
	
}

//print all items in player bag
void print_inv(int player_items[3][3]) {
	int i, j;
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			if( player_items[i][j]!=-1 ) {
				switch(i) {
					case BOOST:
						printf("%s\n", boostitem_names[ player_items[i][j] ]);
						break;
					case HEAL:
						printf("%s\n", healitem_names[ player_items[i][j] ]);
						break;
					case DMG:
						printf("%s\n", dmgitem_names[ player_items[i][j] ]);
						break;
					default:
						break;
				} //close switch
			}  //close if
		}  //close inner for-loop
	}   //close outer for-loop
}

void use_item(char* input, int autocomplete, int player_items[3][3], int* phealth, int* ehealth, int* patk) {
	
	int i, j;
	int item;
	int resolved = 0;
	
	for(i=0; i<3; i++) {
		for(j=0; j<5; j++) {
			if( (player_items[i][j]!=-1) ) {
				item = player_items[i][j];
				switch(i) {
					case BOOST:
						if( strncmp(boostitem_names[item],input,autocomplete)==0 ) {
							player_items[i][j] = -1;
							*patk = *patk + boostitem_effects[item];
							printf("Player injected some %s!\n", boostitem_names[item]);
							printf("The power of nutrition empowers you!\n");
							printf("Attack boosted by %i.\n", boostitem_effects[item]);
							resolved = 1;
						}
						break;
					case HEAL:
						if( strncmp(healitem_names[item],input,autocomplete)==0 ) {
							player_items[i][j] = -1;
							*phealth = *phealth + healitem_effects[item];
							printf("Player drank some %s!\n", healitem_names[item]);
							printf("You can feel drugs numbing the pain.\n");
							printf("Health restored by %i.\n", healitem_effects[item]);
							resolved = 1;
						}
						break;
					case DMG:
						if( strncmp(dmgitem_names[item],input,autocomplete)==0 ) {
							player_items[i][j] = -1;
							*ehealth = *ehealth - dmgitem_effects[item];
							printf("Player fired some %s!\n", dmgitem_names[item]);
							printf("The enemy explodes!\n");
							printf("Enemy lost %i health.\n", dmgitem_effects[item]);
							resolved = 1;
						}
						break;
					default:
						break;
				}
			}
			if( resolved ) {
				break;  //end loop
			}
		}
	}
	
}


