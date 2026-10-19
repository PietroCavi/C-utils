#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Since it's a single header library this is how to initiate it, the screen is only 1
#define TERMINAL_SCREEN_IMPLEMENTATION
#include "terminal_screen.h"

// The resolution of this example will be 16*9 (very classic resolution)
#define HEIGHT 9
#define WIDTH  16

int main(){
    
    // We initialize out "screen"
    init_terminal_screen(WIDTH,HEIGHT);

    // We create an array of pixel which will have the same resolution of our screen
    // The color of our black will be black
    int pixels[HEIGHT*WIDTH] = {0};

    // We set the two central pixel to red
    pixels[HEIGHT*WIDTH/2  ] = 0xFF0000;
    pixels[HEIGHT*WIDTH/2-1] = 0xFF0000;

    // We load out array of ints on the screen
    load_terminal_screen(pixels);

    // We are ready to print the string that contains out screen!
    printf(screen_str);
    
}

// to compile, stay in the directory of this file and the run: 
//      gcc example.c -o example
