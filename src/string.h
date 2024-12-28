#include <stdint.h>
#include <stddef.h>
#ifndef _TRAIN_STRING_
#define _TRAIN_STRING_
typedef struct {
	char *item;
	int size;
} Train_str;

Train_str *tn_str(char *str); //Create String object.
Train_str *tn_cr_empty(int size); //Create empty string with defined size
char *tn_get_uc(char *str,int index,char stop_c); // Get Every charachter in a string,starting at index,until the stop_c charachter
void tn_ins_s(Train_str *str,int index,char *ins); // Insert a Strinf into Another String
void tn_ins_c(Train_str *str,int index,int ins); // Insert a Charachter into a String
void tn_del(Train_str *str,int index); // Delete in String
int tn_apnd_s(Train_str *str,char *ins); // Appends a string 
int tn_apnd_c(Train_str *str,char ins); // Appends a charachter
int tn_cmp(char *a,char *b);// Compares two strings, a and b.
int tn_size( char *str); // Get size of ordinary string
char *tn_ret_print(const char *format,...); // Return formated output,works like a printf to a return variable.
void tn_ret_prints(Train_str *str,const char *format,...); // Injects Formated output into specified string.
#endif // _TRAIN_STRING_
