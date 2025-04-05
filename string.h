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
void tn_ins_s(Train_str *str,int index,char *ins); // Insert a Strinf into Another String
void tn_ins_c(Train_str *str,int index,int ins); // Insert a Charachter into a String
void tn_del(Train_str *str,int index); // Delete in String
void tn_ret_prints(Train_str *str,const char *format,...); // Injects Formated output into specified string.
void tn_clear(Train_str *str); //Clears out a string,makes all bytes of it be zero.
int tn_apnd_s(Train_str *str,char *ins); // Appends a string 
int tn_apnd_c(Train_str *str,char ins); // Appends a charachter
int tn_cmp_s(char *a,char *b); // Compares two strings, a and b,and return 1 on success.
int tn_cmp_c(char a,char b); // Compares two charachters, a and b,and return 1 on success.
int tn_cmp_sm(char *a,char **b,int s); // Compares a,to a list of strings b and return the index of the string on success, or -1 if not equal to any
int tn_cmp_cm(char a,char b[]); // Compares a,to a list of charachters b and return 1 on success.
int tn_check_fn(Train_str *str); //checks if the String is composed of only numbers.
int tn_check_fn_c(char str); //checks if the String is composed of only numbers.
int tn_check_fl_c(char c); // check for letter
int tn_size(char *str); // Get size of ordinary string
void tn_inv_s(Train_str *str); // Inverts an string -> abcde -> edcba
char *tn_ret_print(const char *format,...); // Return formated output,works like a printf to a return variable.
char *tn_get_uc(char *str,int index,char stop_c); // Get Every charachter in a string,starting at index,until the stop_c charachter
char *tn_get_ucr(char *str,int index,char stop_c); // Get Every charachter in a string,starting at index,until the stop_c charachter,but in reverse.
#endif // _TRAIN_STRING_
