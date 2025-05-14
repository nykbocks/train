#ifndef TRAIN_INC
#define TRAIN_INC
#include <stdio.h>
#include <stdlib.h>
#define CAP_S 8 // cappacity addition small;

/*
 * Train is an array and string manipulation library with abilty to copy,append,delete,split,search,etc (WIP)
 */



typedef struct Tstr {
	char *i; // item
	int   s; // size
	int   c; // capacity
} Tstr; // Train str ing
// voids
void t_app_cn(Tstr *s,char ch); // train append char null: appends a char to end of string (and adds null byte \0).
void t_app_sn(Tstr *s,char *sa); // train append str null: appends a string to s and adds a null byte.
// ints
int t_size(char *str); // Returns the size of an ordinary Cstr.
// tstr's
Tstr *t_str(char *s); // initiate the string. Takes a string and puts it into the Tstr.

#ifdef TRAIN_DEF
/*
 * UTIL START; this unit for mostly just useful stuff that you technically dont need.
 * ----------------------------------------
 */




void TN_reac(Tstr *s,int ns){  // TN_ means that the user should no use it! ns -> new size.
	s->i = realloc(s->i,ns);
	s->c = ns;
}


int t_size(char *str){
	int str_size = 0;
	for(int i = 0;*(str + i) != '\0';i++){
		str_size++;
	};
	return str_size; 
}



/*
 * UTIL END
 * ----------------------------------------
 */ 




void t_app_sn(Tstr *s,char *sa){
	if(s->s + t_size(sa) >= s->c) // size is equal to capacity;if append will cause overflow
		TN_reac(s,s->s + t_size(sa) + CAP_S  + 1); // update size
	int i = 0;
	for(;i<=t_size(sa)-1;i++){
		s->i[i+s->s] = sa[i];
	}
	s->s += t_size(sa);
	s->i[s->s] = '\0';

}

void t_app_cn(Tstr *s,char ch){
	if(s->s == s->c) // size is equal to capacity;if appended will cause overflow.
		TN_reac(s,s->c + CAP_S); // update size.
	s->i[s->s] = ch; // set s->i at its size plus one the charachter.
	s->i[s->s+1] = '\0';
	s->s++;
}
Tstr *t_str(char *s){
	Tstr *t = (Tstr*)malloc(sizeof(Tstr));
	t->i = (char*)malloc((t_size(s) + CAP_S + 1) * sizeof(char));
	for(int i = 0;i<=t_size(s);i++){
		t->i[i] = s[i];
	}
	t->s = t_size(s);
	t->c = t_size(s) + CAP_S + 1;
	return t;
}


#endif


#endif//TRAIN_INC
