#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>

/*Variables
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
*/
int print_description();
int randrange(int min, int max);

int main (void) {
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

char buffer[256];
int startinput;



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
	//Prompt for name//
	printf("What is your name");
	fgets(buffer, 255, stdin);
	playername = strdup(buffer);
	printf("Hello, %s ", playername);
	// 
}
}
int print_description() {
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
greater than 50% but no greater than 200% of the player's starting health point total. \n\
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




