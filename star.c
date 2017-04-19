//star.c
//string array manipulation library in C

/* all strings arrays have NULL as the last element
 *
 */
#include"star.h"
#include<stdlib.h>
#include<stdio.h>
#include<strings.h>

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
void star_add(char*** starp, char* s){
	
	char* copy = strdup(s);
	
	int len = star_len(s);
	
	*starp=(char**)realloc(*starp,(len+1)*sizeof(char*));

	(*starp)[len] = NULL;
	
	(*starp)[len-1] = copy;
	
}
//output string array
void star_print(char** star) {
	int i;
	for (i = 0; *star[i] != NULL; i++) {

		printf("%s, %i\n", star[i], i);

	}

}

//free all allocated mem
void kill_star(char** star) {
	int i;
	for (i = 0; *star[i]!=NULL; i++) {
		
		free(star[i]);
	
	}

	free(star);
	
}

//returns length of the star//
int star_len(char** star) {
	int i;
	for (i=0; star[i]!=NULL; i++) {
	}	
	return(i+1);
}
	
	
	
	