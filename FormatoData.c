/*
    AUTORA: GEOVANA PAULA DA SIVA
*/

#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int formato(char *data){
    int x;

    if(strlen(data) != 10){
        return 1;
    }

    if(data[2] != '/'){
        return 1;
    }

    if(data[5] != '/'){
        return 1;
    }

    for(x = 0; x < 10; x++){

        if(x == 2 || x == 5){
            continue;
        }

        if(!isdigit(data[x])){
            return 1;
        }        
    }

    return 0;

}