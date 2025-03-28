#include <stdio.h>

void to_lower(char* s){
    while(*s != 0){
        if(*s >= 'A' && *s <= 'Z'){
            *s += ('a' - 'A');
        }
        s++;
    }
    return;

}

void to_upper(char* s){
    while(*s != 0){
        if(*s >= 'a' && *s <= 'z'){
            *s += ('A' - 'a');
        }
        s++;
    }
    return;
}

int main(){
    char s[] = "HolA A TOdoS";
    to_upper(s);
    printf("%s \n", s);
    to_lower(s);
    printf("%s \n", s);
    return 0;
}