#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFSIZE 64
#define FLAGSIZE 64

void callMe(int arg1) {
  char buf[FLAGSIZE];
  FILE *f = fopen("flag.txt","r");
  if (f == NULL) {
    printf("No flag contact an admin.\n");
    exit(0);
  }
  if(arg1 == 0xdeadbeef){
  	fgets(buf,FLAGSIZE,f);
  	printf(buf);
  }
}

void ignore_me_init_buffering() {
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
}

void portalGun(){
  char buf[BUFFSIZE];
  gets(buf);

}

int main(int argc, char **argv){
  ignore_me_init_buffering();
  setvbuf(stdout, NULL, _IONBF, 0);
  puts("hey Morty give an adress for my portal Gun");
  portalGun();
  return 0;
}

