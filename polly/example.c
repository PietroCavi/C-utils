#include <stdio.h>
#include <unistd.h>

#include "polly.h"

int main(){
    
    start_polly();

    while(!is_down(KEY_Q)){
        if(is_down(KEY_W)){
            printf("W is held\n");
        }
        if(is_down(KEY_A)){
            printf("A is held\n");
        }
        if(is_down(KEY_S)){
            printf("S is held\n");
        }
        if(is_down(KEY_D)){
            printf("D is held\n");
        }
        usleep(10000);
    }    

    printf("Hello\n");
    
    stop_polly();

}


// to compile, stay in the directory of this file and the run: 
//      gcc example.c polly.c -o example

// running this program normally will probalby result in a failure
// permission to read the keyboard file is needed, I suggest to run it
// as root, so:
//      sudo ./example
