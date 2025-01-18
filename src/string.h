#include <stdint.h>
#include <stddef.h>
#ifndef _TRAIN_STRING_
#define _TRAIN_STRING_
typedef struct {
	char *item;
	int size;
} Train_str;

Train_str *tn_str(char *str); //Create String
Train_str *tn_cr_empty(void); //Create empty string
void tn_ins(Train_str *str,int index,char *ins); // Insert in String
int tn_size( char *str); // Get size of ordinary string
char *tn_ret_print(const char *format,...); // Return format string input
int tn_str_cmp(Train_str *a,Train_str *b); // Compares two strings and return 0/1

#endif // _TRAIN_STRING_
