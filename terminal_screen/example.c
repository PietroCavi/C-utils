#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TERMINAL_SCREEN_IMPLEMENTATION
#include "terminal_screen.h"

int main(){
    
    init_terminal_screen(3,3);

    int pixels[9] = {0};
    pixels[4] = 0xFF0000;

    load_terminal_screen(pixels);

    printf(screen_str);
    
}

