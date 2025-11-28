#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <math.h>
#define MAP_WIDTH 16
#define MAP_HEIGHT 16
#define FOV 60
#define DEPTH 16.0
#define PI 3.14159265
char map [MAP_HEIGHT][MAP_WIDTH];
float playerX = 8.0f, playerY = 8.0f;
float angle = 0.0f;
int look_offset = 0;
void init_map () {
    for (int y = 0; y < MAP_HEIGHT; y++)
        for (int x = 0; x < MAP_WIDTH; x++)
            map [y][x] = (x == 0 || x == MAP_WIDTH-1 || y == 0 || y == MAP_HEIGHT-1) ? '#' : '.';
} char get_input () {
    struct termios oldt, newt;
    char ch;
    tcgetattr (STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr (STDIN_FILENO, TCSANOW, &newt);
    ch = getchar ();
    tcsetattr (STDIN_FILENO, TCSANOW, &oldt);
    return ch;
} void draw_screen () {
    system ("clear");
    int width = 80;
    int height = 24;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float rayAngle = (angle - FOV / 2.0) + ((float) x / (float) width) * FOV;
            float rayX = cos (rayAngle * PI / 180.0);
            float rayY = sin (rayAngle * PI / 180.0);
            float distance = 0.0f;
            while (distance < DEPTH) {
                int testX = (int) (playerX + rayX * distance);
                int testY = (int) (playerY + rayY * distance);
                if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT) break;
                if (map [testY][testX] == '#') break;
                distance += 0.1f;
            } int wallHeight = (int) (height / distance);
            int ceiling = (height / 2 - wallHeight / 2) + look_offset;
            int floor = (height / 2 + wallHeight / 2) + look_offset;
            if (y < ceiling) putchar (' ');
            else if (y >= ceiling && y <= floor) putchar ('#');
            else putchar ('.');
        } putchar ('\n');
    } printf ("\nWASD=Move | IJKL=Look | P=Place | R=Remove | Q=Quit\n");
} void move (float dx, float dy) {
    float newX = playerX + dx;
    float newY = playerY + dy;
    if (map [(int) newY][(int) newX] != '#') playerX = newX, playerY = newY;
} void strafe (float dx, float dy) {
    float newX = playerX + dx;
    float newY = playerY + dy;
    if (map [(int) newY][(int) newX] != '#') {
        playerX = newX;
        playerY = newY;
    }
} void place_block () {
    int tx = (int) (playerX + cos (angle * PI / 180.0));
    int ty = (int) (playerY + sin (angle * PI / 180.0));
    if (tx >= 0 && tx < MAP_WIDTH && ty >= 0 && ty < MAP_HEIGHT && map [ty][tx] == '.')
        map [ty][tx] = '#';
} void remove_block () {
    int tx = (int) (playerX + cos (angle * PI / 180.0));
    int ty = (int) (playerY + sin (angle * PI / 180.0));
    if (tx >= 0 && tx < MAP_WIDTH && ty >= 0 && ty < MAP_HEIGHT && map [ty][tx] == '#')
        map [ty][tx] = '.';
} int inventory ();
int inventory () {
    //Define size of inventory to be 10
    int inventory_index = 10;
    
} int main () {
    init_map ();
    while (1) {
        draw_screen ();
        char c = get_input ();
        if (c == 'q') break;
        else if (c == 'w') move (cos (angle * PI / 180.0) * 0.5, sin (angle * PI / 180.0) * 0.5);
        else if (c == 's') move (-cos (angle * PI / 180.0) * 0.5, -sin (angle * PI / 180.0) * 0.5);
        else if (c == 'd') strafe (-sin (angle * PI / 180.0) * 0.5, cos (angle * PI / 180.0) * 0.5);
        else if (c == 'a') strafe (sin (angle * PI / 180.0) * 0.5, -cos (angle * PI / 180.0) * 0.5);
        else if (c == 'j') angle -= 5;   
        else if (c == 'l') angle += 5;   
        else if (c == 'k') look_offset -= 1; 
        else if (c == 'i') look_offset += 1; 
        else if (c == 'p') place_block ();
        else if (c == 'r') remove_block ();
    } return 0;
}

