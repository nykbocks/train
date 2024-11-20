#include <stdint.h>
#include <stddef.h>
#ifndef _TRAIN_STRING_
#define _TRAIN_STRING_
typedef struct {
	char *item;
	int size;
} Train_str;

Train_str *tn_str(char item[]); //Create String
void tn_ins(Train_str *str,int index,char *ins); // Insert in String
int tn_size( char *str);
char *tn_ret_print(const char *format,...);

#endif // _TRAIN_STRING_
