#include <stdio.h>
#include <string.h>

int palindromo(char* s){
    char* l = s;
    char* r = s + strlen(s) - 1;
    while(l < r){
        if(*l != *r){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int main(int argc, char** argv){
    char *pali = argv[1];
    if(palindromo(pali)){
        printf("Es palindormo \n");
    } else{
        printf("No es palindromo \n");
    }
    return 0;
}