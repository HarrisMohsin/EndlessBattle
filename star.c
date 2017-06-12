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
fprintf(stderr, "NEW STAR CALLED\n");
char** x =(char**)malloc(1*sizeof(char*));

if (x == NULL) {
	
	fprintf(stderr, "malloc error");
	
	exit(1);   
	
	}

	x[0] = NULL;
fprintf(stderr, "NEW STAR SUCCESS\n");
return(x);

}
	
//add a new allocated copy of s to star
void star_add(char*** starp, char* s){
	fprintf(stderr, "STAR ADD CALLED\n");	
	char* copy = strdup(s);
	
	int len = star_len(*starp);
	
	*starp=(char**)realloc(*starp,(len+1)*sizeof(char*));

	(*starp)[len] = NULL;
	
	(*starp)[len-1] = copy;
	fprintf(stderr, "STAR ADD SUCCESS\n");
}
//output string array
void star_print(char** star) {
	fprintf(stderr, "STAR PRINT CALLED\n");
	int i;
	for (i = 0; star[i] != NULL; i++) {

		printf("%s, %i\n", star[i], i);

	}
	fprintf(stderr, "STAR PRINT SUCCESS\n");
}

//free all allocated mem
void kill_star(char** star) {
	int i;
	fprintf(stderr, "KILL STAR CALLED\n");
	for (i = 0; star[i]!=NULL; i++) {
		
		free(star[i]);
	
	}
	fprintf(stderr, "KILL STAR SUCCESS\n");
	free(star);
	
}

//returns length of the star//
int star_len(char** star) {
	fprintf(stderr, "STAR LEN CALLED\n");
	int i;
	for (i=0; star[i]!=NULL; i++) {
	}	
	fprintf(stderr, "STAR LEN SUCCESS\n");
	return(i+1);
}
	
	
	
	
