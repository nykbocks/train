#include "../string.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#define MAX_STR 65536
#define SNULL 0
char RET_SPF[MAX_STR] = {0};
int RET_SIZ = 0;
Train_str *tn_str(char *str){
	Train_str *temp = (Train_str*)malloc(sizeof(Train_str));
	temp->item = (char*)malloc(sizeof(char) * tn_size(str));
	for(int i = 0;i<=tn_size(str);i++){
		temp->item[i] = str[i];
	}
	temp->size = tn_size(temp->item);
	temp->item[tn_size(str)] = '\0';
	return temp;
}
Train_str *tn_cr_empty(int size){
	Train_str *temp = (Train_str*)malloc(sizeof(Train_str));
	temp->item = (char*)malloc(sizeof(char) * size);
	memset(temp->item,SNULL,size);
	temp->size = SNULL;
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
        va_list args;
	va_start(args,format);
	char *ret = (char*)malloc(sizeof(char) * MAX_STR);	
	vsprintf(ret,format,args);
	va_end(args);
	return ret;
}
void tn_ret_prints(Train_str *str,const char *format,...){
	va_list args;
	va_start(args,format);
	char *ret = (char*)malloc(sizeof(char) * str->size);
	//char ret[1024];
	vsprintf(ret,format,args);
	va_end(args);
	strcat(str->item,ret);
}
void tn_ins_s(Train_str *str,int index,char *ins){
	//char p1[index + len];
	//char *p1 = (char*)malloc(sizeof(char) * (index + len ) );
	//for(int i = 0;i<=index;i++){
	//	p1[i] = str->item[i];
	//}
	//for(int i = 1;i<=len+1;i++){
	//	p1[index + i] = ins[i];
	//}
	//
	//char p2[str->size - index];
	//for(int i = 0;i<=(str->size - index);i++){
	//	p2[i] = str->item[index+i];
	//}
	//str->item = tn_ret_print("%s%s",p1,p2);
	//str->size = tn_size(str->item);
	//free(p1);
	if(index == tn_size(str->item)){
    		tn_apnd_s(str,ins);
    		return;
	}
	int len = tn_size(ins);
	char *p1 = (char*)malloc(sizeof(char) * (index + len ) );
	for(int i = 0;i<index;i++){
		p1[i] = str->item[i];
	}
	for(int i = 0;i<=len;i++){
        	p1[index + i] = ins[i];
	}
	char *p2 = (char*)malloc(sizeof(char) * (tn_size(str->item) - index ) );
	memcpy(p2,&str->item[index],tn_size(str->item) - index);
        //memset(str->item,0,sizeof(str->item));
	str->item = tn_ret_print("%s%s",p1,p2);
	str->size = tn_size(str->item);
	free(p1);
	free(p2);
	return;
}
void tn_ins_c(Train_str *strc,int index,int ins){
    /*
	if(index == tn_size(str->item)){
    		tn_apnd_c(str,ins);
    		return;
	}
	char *p1 = (char*)malloc(sizeof(char) * (index + sizeof(ins)) );
	for(int i = 0;i<index;i++){
		p1[i] = str->item[i];
	}
	p1 = tn_ret_print("%s%c",p1,ins);
	printf("%s",p1);
	//char *p2 = (char*)malloc(sizeof(char) * (tn_size(str->item) - index ) );
	char p2[256];	
	printf("size %d\n",tn_size(str->item) - index);
	for(int i = index;i < tn_size(str->item);i++){
		p2[i - index] = str->item[i];
	}
        //memset(str->item,0,sizeof(str->item));
	printf("p2: %s\n",p2);
        printf("AH: %s\n",(&str->item));
	str->item = tn_ret_print("%s%s",p1,&str->item[index]);
	printf("%s",str->item);
	str->size = tn_size(str->item);
	//free(p1);
	//free(p2);
   */
   	//char *buf = (char*)malloc(strlen(str->item) + sizeof(ins) + 5);
   	//memset(buf,0,(strlen(str->item) + sizeof(ins) + 5));
/*   	char buf[strlen(str->item) + sizeof(ins) + 5];
   	memset(buf,0,strlen(buf));
	strncpy(buf,str->item,index);
	int len = tn_size(buf);
	char *i = (char*)malloc(sizeof(ins));
	i[0] = ins;
	strcpy(buf+len,i);
	len = tn_size(buf);
	strcpy((buf+len),str->item);
	for(int i = 0;str->item[index + i] != '\0';i++){
		buf[(len + i)] = str->item[index + i];
		//printf("%c",buf[len + i]);
	}
*//*   	char *final = (char*)malloc(sizeof(char) * (strlen(str->item) + sizeof(ins) + 5));
   	memset(final,0,(strlen(str->item) + sizeof(ins) + 5));
*/   
	Train_str *str = tn_str(strc->item);
	char final[strlen(str->item) + sizeof(ins) + 5];	
	memset(final,0,strlen(str->item) + sizeof(ins) + 5);
	strncpy(final,str->item,index);
	char fina[strlen(str->item) + sizeof(ins) + 5];	
	memset(fina,0,strlen(str->item) + sizeof(ins) + 5);
	strcpy(fina,&str->item[index]);
/*   	printf("\nFINAL: %s\n",final);
   	printf("\nFINA: %s\n",&fina[0]);
   	printf("\nRESULT: %s%c%s\n",final,ins,&fina[0]);
*/    	str->item = tn_ret_print("%s%c%s",final,ins,&fina[0]);
	return;
}
void tn_del(Train_str *str,int index){
	//char p1[index];
	char *p1 = (char*)malloc(sizeof(char) * index-1);
	for(int i = 0;i<index - 1;i++){
		p1[i] = str->item[i];
	}
	char p2[str->size - index];
	for(int i = 0;i<=(str->size - index);i++){
		p2[i] = str->item[index+i];
	}
	str->item = tn_ret_print("%s%s",p1,p2);
	str->size = tn_size(str->item);
//	free(p1);
}
int tn_cmp_s(char *a,char *b)
{
	int max = (tn_size(a) > tn_size(b)) ? tn_size(b) : tn_size(a);
	int i = 0;
	while(i<=max){
		if(a[i] == b[i]){i++;continue;};
		return 0;
	}
	return 1;
}
int tn_cmp_cm(char a,char b[])
{
	int i = 0;
	while(i<=tn_size(b)){
		if(a == b[i]){i++;continue;};
		return 0;
	}
	return 1;
}
int tn_cmp_sm(char *a,char *b[],int s)
{
    	for (int i = 0;i<=s;i++){
        	int max = (tn_size(a) > tn_size(b[i])) ? tn_size(b[i]) : tn_size(a);
        	int j = 0;
        	while(j<=max){
        		if(a[j] == b[i][j]){j++;continue;};
        		return 0;
        	}
    	}
	return 1;
}
int tn_cmp_c(char a,char b)
{
	if(a == b){return 1;};
	return 0;
}
int tn_apnd_s(Train_str *str,char *ins){
    	//free(str->item);
       	str->item = tn_ret_print("%s%s",str->item,ins);
	str->size = tn_size(str->item);
	if(str->size > 0) return 0;
	return 1;
}
int tn_apnd_c(Train_str *str,char ins){
    	free(str->item);
       	str->item = tn_ret_print("%s%c%c",str->item,ins,'\0');
	str->size = tn_size(str->item);
	if(str->size > 0) return 0;
	return 1;
}
char *tn_get_uc(char *str,int index,char stop_c){
	// Train_str *str = tn_str(strc->item);
	Train_str *out = tn_cr_empty(tn_size(str));	
	for(int i = index;str[i-1] != stop_c;i++){
    		if(i == tn_size(str)) {printf("TN_GET_UC ERROR:The specified charachter is not on the string.\n"); break;}
		tn_ret_prints(out,"%c",str[i]);
	}
	return out->item;
}
void tn_clear(Train_str *str){
  char ret[1024];
	//memset(str->item,0,tn_size(str->item));
	str->size = 0;
	str->item = tn_ret_print("%c",'\0');
}
int tn_check_fn(Train_str *str){
	for(int i = 0;i < str->size;i++){
    		int c = (int)str->item[i];
		if('0' < c && c < '9'){
			continue;
		}
		return 0;
	}
	return 1;
}
int tn_check_fn_c(char str){
	int c = (int)str;
	if('0' <= c && c <= '9'){
    		return 1;
	}
	return 0;
}
