//Area filling algorithm
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void flood(int seed_x, int seed_y, int foreground_col, int background_col);

void main() {
    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "\\TURBOC3\\bgi");
    rectangle(50, 50, 100, 100);
    flood(55, 55, 4, 15);
    getch(); 
    closegraph(); 
} 

void flood(int seed_x, int seed_y, int foreground_col, int background_col) { 
    if (getpixel(seed_x, seed_y) != background_col && 
        getpixel(seed_x, seed_y) != foreground_col) { 
        putpixel(seed_x, seed_y, foreground_col); 
        flood(seed_x + 1, seed_y, foreground_col, background_col); 
        flood(seed_x - 1, seed_y, foreground_col, background_col); 
        flood(seed_x, seed_y + 1, foreground_col, background_col); 
        flood(seed_x, seed_y - 1, foreground_col, background_col); 
        flood(seed_x + 1, seed_y + 1, foreground_col, background_col); 
        flood(seed_x - 1, seed_y - 1, foreground_col, background_col); 
        flood(seed_x + 1, seed_y - 1, foreground_col, background_col); 
        flood(seed_x - 1, seed_y + 1, foreground_col, background_col); 
    } 
}
