#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char* str1=(char *)malloc(10 * sizeof(char));
    char* str2=(char *)malloc(800 * sizeof(char));
    char* next_binary=(char *)malloc(800 * sizeof(char));
    if (argc != 2){
        printf("missing arguments!!\n");
        return 0;
    }
    str1=argv[0];
    str2=argv[1];
    int i = (str1[strlen(str1)-3]-48)*100+(str1[strlen(str1)-2]-48)*10+(str1[strlen(str1)-1]-48);
    sprintf(next_binary,"./out%03d %s",i+1,&(str2[2]));
    int cnst = 500;
    if ((str2[0]+cnst+str2[1]) >> 4 == 500 && str2[0]+(str2[0]^str2[1]) == 500 && str2[0]*str2[1] == 500){
        if (strlen(str2)==2){
            if (!strncmp(next_binary,"./out400",8)){
                printf("the end\n");
                printf("GOOOOOOOOOOOOOOOOOOOD\n");
                return 1;
            }else{
                printf("NOOOOOOOOOOOOOOOOOOOO1\n");
                return 0;
            }
        }
        system(next_binary);
        return 1;

    }else{
        printf("NOOOOOOOOOOOOOOOOOOOO\n");
        return 0;
    }
    return 0;

}