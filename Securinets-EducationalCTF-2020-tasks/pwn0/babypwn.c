#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

char flag[40];

void ignore_me_init_buffering() {
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
}

int main(int argc, char **argv){
  ignore_me_init_buffering();
  int a = 0;
  char s[40];
  FILE *file = fopen("flag.txt","r");
  if (file == NULL) {
    printf("no flag please contact an admin!!\n");
    exit(0);
  }
  fgets(flag,40,file);
  gets(s);
  if (a == 0xdeadbeef){
    printf("%s\n",flag );
  }else{
    printf("nope\n");
  }
  
  return 0;
}