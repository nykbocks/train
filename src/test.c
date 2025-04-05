#include "../string.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    	char **list = malloc(5 * sizeof(char*));
    	if(list){
		for(int i;i<5;i++){
			list[i] = (char*)malloc(sizeof(char) * 5);
		}
    	}
    	list[0] = "testa"; 
    	list[1] = "testb";  
    	list[2] = "testc";
    	list[3] = "testd";
    	list[4] = "teste";
    	printf("%s\n",list[1]);
    	printf("%d\n",tn_cmp_sm("teste",list,5));
	return 0;
}
