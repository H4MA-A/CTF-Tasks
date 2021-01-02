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
     fprintf(stderr,"malloc has failed in stringToBinary(%s): %s\n",s, strerror(errno));
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

int oneround(int* x1, int* x2, int* x3, int* x4, int k1, int k2, int k3, int k4, int k5, int k6){

	int aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8,aux9,auxa;
	aux1 = (*x1*k1)%17;
	aux2 = (*x2+k2)%16;
	aux3 = (*x3+k3)%16;
	aux4 = (*x4*k4)%17;
	aux5 = aux1^aux3;
	aux6 = aux2^aux4;
	aux7 = (aux5*k5)%17;
	aux8 = (aux6+aux7)%16;
	aux9 = (aux8*k6)%17;
	auxa = (aux7+aux9)%16;
	*x1 = aux1^aux9;
	*x2 = aux3^aux9;
	*x3 = aux2^auxa;
	*x4 = aux4^auxa;
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
	flag = "FwordCTF{asba_lik}";
	char* key[9] = {"ham", "ker", "her", "kol", "mbz", "hfl", "arc", "asb", "ctf"};
	char* binFlag = (char *)malloc(180 * sizeof(char));
	binFlag = stringToBinary(flag);
	char* binKey = (char *)malloc(180 * sizeof(char));
	int x1,x2,x3,x4;
	int k1,k2,k3,k4,k5,k6;
	char* output = (char *)malloc(180 * sizeof(char));
	int j=0;
	for (int i = 0; i < strlen(binFlag); i+=16){
		binKey = stringToBinary(key[i%9]);
		k1 = giveit2me(binKey);
		k2 = giveit2me(binKey+4);
		k3 = giveit2me(binKey+8);
		k4 = giveit2me(binKey+12);
		k5 = giveit2me(binKey+16);
		k6 = giveit2me(binKey+20);
		x1 = giveit2me(binFlag+i);
		x2 = giveit2me(binFlag+i+4);
		x3 = giveit2me(binFlag+i+8);
		x4 = giveit2me(binFlag+i+12);
		oneround(&x1, &x2, &x3, &x4, k1, k2, k3, k4, k5, k6);

		printf("%d %d %d %d ", x1, x2, x3, x4);
		/*printf("%d\n", x1);
		printf("%d\n", x2);
		printf("%d\n", x3);
		printf("%d\n", x4);
		j+=2;*/
		/*strcat(output,itoa(x1,10));
		strcat(output,itoa(x2,10));
		strcat(output,itoa(x3,10));
		strcat(output,itoa(x4,10));*/
	}

}