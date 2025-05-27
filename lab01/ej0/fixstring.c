#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    int i=0;

    while (s[i]!='\0'){
        i++;
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool eq=true;
    int i=0;

    while (s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]){
        i++;
    }

    eq= s1[i]==s2[i];

    return eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool less=true;
    int i=0;

    while (s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]){
        i++;
    }

    less= s1[i]<=s2[i] || s1[i]=='\0';

    return less;     
}



//int main(){

    //fixstring word1="mes";
    //fixstring word2="messi";

    //printf("%d", fstring_length(word));

    //printf("%d", fstring_eq(word1,word2));

    //printf("%d", fstring_less_eq(word1,word2));


  //  return 0;
//}
