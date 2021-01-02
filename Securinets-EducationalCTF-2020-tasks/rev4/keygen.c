#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define FLAGSIZE 64

int check1(char* arg1) {

  if (strlen(arg1)==20)
  {
    if (*(arg1+4)==95 && (int)*(arg1+(strlen(arg1)>>1)-1)==95 && (int)*(arg1+14)==95)
    {
      return 1;
    }
  }
  return 0;

}

int check2(char* arg1) {

  int cnt=0;
  int v1=0;
  while (cnt < strlen(arg1)){
    v1+=arg1[cnt];
    cnt++;
  }
  return v1==0x5f4;
}

int check3(char* arg1, char* arg2, int arg3){
  return arg1[arg3]==arg2[arg3];
}

void win() {
  char buf[FLAGSIZE];
  FILE *f = fopen("flag.txt","r");
  if (f == NULL) {
    printf("no Flag contact an admin\n");
    exit(0);
  }
  fgets(buf,FLAGSIZE,f);
  printf("%s\n",buf);
}
void ignore_me_init_buffering() {
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
}

int main(int argc, char **argv){
  ignore_me_init_buffering();
  char* s = (char *)malloc(20 * sizeof(char));
  char* key="H4MA";
  printf("Hello hello give the secret word:");
  scanf("%s",s);
  if (check1(s))
  {
    if (check2(s))
    {
      if (check3(s,key,0) && check3(s+5,key,1) && check3(s+strlen(s)/2,key,2) && check3(s+15,key,3))
      {
        printf("You win!!\n");
        win();
      }else{
        printf("ghalit\n");
        return 0;
      }
    }else{
      printf("ghalit\n");
      return 0;
    }
  }else{
    printf("ghalit\n");
    return 0;
  }
}
