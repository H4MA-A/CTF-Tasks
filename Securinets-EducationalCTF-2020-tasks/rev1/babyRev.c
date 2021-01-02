#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char* s = (char *)malloc(50 * sizeof(char));
	printf("Show me WHAT u got!!: ");
	scanf("%s",s);
	int cnt=0;
	while (cnt < strlen(s)){
			s[cnt]^=cnt;
		cnt++;
	}
	if(!strcmp(s,"Sdavvlhb|zq:Sa?d#NE{ AIBG^*O=<c")){
		printf("Get schwifty\n");
		printf("Submit!!\n");
	}else{
		printf("wubba lubba dub dub\n");
	}
}

//Securinets{1_l1k3_Wh4T_U_G0T!!}
