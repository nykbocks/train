#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#define MAX_STR 65536
char RET_SPF[MAX_STR] = {0};
Train_str *tn_str(char *str){
	Train_str *temp = (Train_str*)malloc(sizeof(Train_str));
	temp->item = str;
	int str_size;
	for(int i = 0;*(str + i) != '\0';i++){
		str_size++;
	};
	temp->size = str_size;
	return temp;
}
int tn_size(char *str){
	int str_size = 0;
	for(int i = 0;*(str + i) != '\0';i++){
		str_size++;
	};
	return str_size; 
}
char *tn_ret_print(const char *format,...){
	memset(RET_SPF,tn_size(RET_SPF),0);
	va_list args;
	va_start(args,format);
	//char *ret = (char*)malloc(sizeof(char) * MAX_STR);	
	vsprintf(RET_SPF,format,args);
	va_end(args);
	return RET_SPF;
}
void tn_ins(Train_str *str,int index,char *ins){
	uint32_t len = tn_size(ins);
	//char p1[index + len];
	char *p1 = (char*)malloc(sizeof(char) * (index + len));
	for(int i = 0;i<index;i++){
		p1[i] = str->item[i];
	}
	for(int i = 0;i<len;i++){
		p1[index + i] = ins[i];
	}
	
	char p2[str->size - index];
	for(int i = 0;i<=(str->size - index);i++){
		p2[i] = str->item[index+i];
	}
	str->item = tn_ret_print("%s%s",p1,p2);
	str->size = tn_size(str->item);
}
