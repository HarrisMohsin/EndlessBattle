//star.c
//string array manipulation library in C

/* all strings arrays have NULL as the last element
 *
 */
#include"star.h"
#include<stdlib.h>
#include<stdio.h>

//allocate new star, set only element to NULL, and return
char** new_star(void) {

char** x =(char**)malloc(1*sizeof(char*));

if (x == NULL) {
	
	fprintf(stderr, "malloc error");
	
	exit(1);   
	
	}

	x[0] = NULL;

return(x);

}
	
//add a new allocated copy of s to star
void star_add(char*** star, char* s);

//output string array
void star_print(char** star);

//free all allocated mem
void kill_star(char** star);

//returns length of the star//
void star_len(char** star);


