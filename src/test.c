#include "string.h"
#include <stdio.h>

int main(){
	Train_str *test = tn_str("HW! ");
	tn_ins(test,1,"ello ");
	tn_ins(test,7,"orld");
	printf("%s",test->item);
	return 0;
}
