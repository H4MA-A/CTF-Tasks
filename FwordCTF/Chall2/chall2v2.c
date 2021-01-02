#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <math.h>


char *stringToBinary(char *s)
{
  if (s == NULL) {
    return NULL;
  }
  size_t slen = strlen(s);

  errno = 0;
  char *binary = malloc(slen * CHAR_BIT + 1);
  if(binary == NULL){
     fprintf(stderr,"malloc has failed(%s): %s\n",s, strerror(errno));
     return NULL;
  }
  if (slen == 0) {
    *binary = '\0';
    return binary;
  }
  char *ptr;
  char *start = binary;
  int i;
  for (ptr = s; *ptr != '\0'; ptr++) {
    for (i = CHAR_BIT - 1; i >= 0; i--, binary++) {
      *binary = (*ptr & 1 << i) ? '1' : '0';
    }
  }
  *binary = '\0';
  binary = start;
  return binary;
}

int convert(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
} 

int mul(int a,int b){
	int x=(a*b)%17;
	if (a==0){
		x=(16*b)%17;
	}
	if (x==16){
		x=0;
	}
	return x;
}
  
int do_it(int* x1, int* x2, int* x3, int* x4, int* k){
	int aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8,aux9,auxa;
	int j = 0;
	for (int i = 0; i < 4; ++i){	
		aux1 = mul(*x1,k[j]);
		aux2 = (*x2+k[j+1])%16;
		aux3 = (*x3+k[j+2])%16;
		aux4 = mul(*x4,k[j+3]);
		aux5 = aux1^aux3;
		aux6 = aux2^aux4;
		aux7 = mul(aux5,k[j+4]);
		aux8 = (aux6+aux7)%16;
		aux9 = mul(aux8,k[j+5]);
		auxa = (aux7+aux9)%16;
		*x1 = aux1^aux9;
		*x2 = aux2^auxa;
		*x3 = aux3^aux9;
		*x4 = aux4^auxa;
		j+=6;
	}
	*x1 = mul(*x1,k[24]);
	*x2 = (*x2+k[25])%16;
	*x3 = (*x3+k[26])%16;
	*x4 = mul(*x4,k[27]);
	return 0;

}

int giveit2me(char* str){

	char* aux = (char *)malloc(16 * sizeof(char));
	int n;
	strncpy(aux,str,4);
	sscanf(aux,"%d",&n);
	return convert(n);

}

int main(int argc, char **argv){

	char* flag = (char *)malloc(16 * sizeof(char));
	FILE * filePointer; 
	filePointer = fopen("flag.txt", "r");
	fscanf(filePointer, "%s", flag);
	char* binFlag = (char *)malloc(180 * sizeof(char));
	binFlag = stringToBinary(flag);
	int x1,x2,x3,x4;
	int k[28]={13, 12, 6, 15, 3, 15, 5, 9, 1, 11, 12, 15, 13, 6, 7, 7, 15, 3, 15, 5, 9, 13, 12, 6, 15, 13, 6, 7};
	char* output = (char *)malloc(180 * sizeof(char));
	char* aux = (char *)malloc(180 * sizeof(char));
	for (int i = 0; i < strlen(binFlag); i+=16){
		x1 = giveit2me(binFlag+i);
		x2 = giveit2me(binFlag+i+4);
		x3 = giveit2me(binFlag+i+8);
		x4 = giveit2me(binFlag+i+12);
		do_it(&x1, &x2, &x3, &x4, k);
		sprintf(aux, "%d %d %d %d ", x1, x2, x3, x4);
		strcat(output,aux);
	}
	printf("%s\n", output);

}
//gcc chall2v2.c -o out -lm