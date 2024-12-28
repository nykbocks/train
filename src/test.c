#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    	Train_str *test = tn_str("apluh");
    	tn_ins(test,5,"plo");
    	tn_ins(test,5,"plo");
    	tn_ins(test,5,"plo");
    	tn_ins(test,5,"plo");
    	tn_ins(test,5,"plo");
    	tn_ins(test,5,"plo");
    	tn_ins(test,5,"plo");
    	tn_ins(test,5,"plo");
    	printf("%s",test->item);
	return 0;
}
