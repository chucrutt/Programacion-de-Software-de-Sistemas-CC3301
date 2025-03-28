#include <stdio.h>
#include <string.h>

void reverse(char* s){
    char* l = s;
    char* r = s + strlen(s) - 1;
    while(l < r){
        char tmp = *l;
        *l = *r;
        *r = tmp;
        l++;
        r--;
    }
}

int main(int argc, char** argv){
    char *s = argv[1];
    reverse(s);
    printf("%s \n", s);
    return 0;
}