//star.h
//string array manipulation library in C

/* all strings arrays have NULL as the last element
 *
 */

#ifndef _STAR_H_
#define _STAR_H_ 0
//allocate new star, set only element to NULL, and return
char** new_star(void);

//add a new allocated copy of s to star
void star_add(char*** star, char* s);

//output string array
void star_print(char** star);

//free all allocated mem
void kill_star(char** star);

//returns length of the star//
int star_len(char** star);

#endif

