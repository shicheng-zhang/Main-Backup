#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
void enable_raw_mode () {
    struct termios term;
    tcgetattr (STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr (STDIN_FILENO, TCSANOW, &term);
    fcntl (STDIN_FILENO, F_SETFL, fcntl (STDIN_FILENO, F_GETFL) | O_NONBLOCK);
} void disable_raw_mode () {
    struct termios term;
    tcgetattr (STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr (STDIN_FILENO, TCSANOW, &term);
} char get_keypress (); 
char get_keypress () {
    char ch;
    if (read (STDIN_FILENO, &ch, 1) == 1) {
        return ch;
    } return 0;
} void printout (int size_y, int size_x, int grid [size_y][size_x], int score);
void printout (int size_y, int size_x, int grid [size_y][size_x], int score) {
    system ("clear");
    printf (" ");
    for (int x = 0; x < size_x; x++) {
        printf ("- ");
    } printf ("\n");
    for (int y = 0; y < size_y; y++) {
        printf ("|");
        for (int x2 = 0; x2 < size_x; x2++) {
            if (grid [y][x2] == -1) {
                printf ("  ");
            } else if (grid [y][x2] == 0) {
                printf ("* ");
            } else if (grid [y][x2] == 1) {
                printf ("@ ");
            } else if (grid [y][x2] == 2) {
                printf ("A ");
            } else if (grid [y][x2] == 3) {
                printf ("D ");
            } else {
                exit (0);
            }
        } printf ("|\n");
    } printf (" ");
    for (int x3 = 0; x3 < size_x; x3++) {
        printf ("- ");
    } printf ("\nScore = %d\n", score);
} int count_apples (int size_y, int size_x, int board [size_y][size_x]);
int count_apples (int size_y, int size_x, int board [size_y][size_x]) {
    int apple_count = 0;
    for (int yh = 0; yh < size_y; yh++) {
        for (int xh = 0; xh < size_x; xh++) {
            if (board [yh][xh] == 2) {
                apple_count++;
            }
        }
    } return apple_count;
} void main_algorithm () {
    int size_board_x = 0, size_board_y = 0;
    printf ("Enter the x size of the board:");
    scanf ("%d", &size_board_x);
    printf ("Enter the y size of the board:");
    scanf ("%d", &size_board_y);
    int playingboard [size_board_y][size_board_x];
    for (int y = 0; y < size_board_y; y++) {
        for (int x = 0; x < size_board_x; x++) {
            playingboard [y][x] = -1; //Uninitialised
        }
    } //-1 is Uninitialised, 0 is prev track, 1 is current snail position, 2 is apple position, 3 is barrier position (2, 3 UNINT)
    int start_pos_x = 0, start_pos_y = 0;
    input_pos_start:
    printf ("Enter the starting x position:");
    scanf ("%d", &start_pos_x);
    printf ("Enter the starting y position:");
    scanf ("%d", &start_pos_y);
    if ((start_pos_x > -1) && (start_pos_x < size_board_x)) {
        if ((start_pos_y > -1) && (start_pos_y < size_board_y)) {
            playingboard [start_pos_y][start_pos_x] = 1;
            //Snail starter        
        } else {
            printf ("Invalid start position. Resubmit.\n");
            goto input_pos_start;
        }
    } //After we have our starting position for our snail, it is time to make our first printout
    int current_x = start_pos_x, current_y = start_pos_y;
    int new_x = -1, new_y = -1;
    char command;
    int score = 0;
    int count_barriers = 0;
    printf ("How many barriers do you want:");
    scanf ("%d", &count_barriers);
    //Generate barriers
    int barriers [count_barriers][2];
    reenter_barrier:
    for (int b = 0; b < count_barriers; b++) {
        printf ("Enter the x coordinate of the %dth barrier:", b); 
        scanf ("%d", &barriers [b][0]);
        printf ("Enter the y coordinate of the %dth barrier:", b);
        scanf ("%d", &barriers [b][1]);
        printf ("\n");   
    } for (int c = 0; c < count_barriers; c++) {
        if (playingboard [barriers [c][1]][barriers [c][0]] == 1) {
            printf ("You cannot place a barrier where your snail starts.\n");
            goto reenter_barrier;
        } else {
            playingboard [barriers [c][1]][barriers [c][0]] = 3;
        }
    } enable_raw_mode (); 
    while (1) {
        //Commands: 
        //WASD: Movement
        //Q: Quit Game
        //Generate Apple
        reset_apple:
        srand (time (NULL));
        int apple_x = rand () % size_board_x;
        srand (time (NULL));
        int apple_y = rand () % size_board_y;
        if (playingboard [apple_y][apple_x] == 1) {
            //If apple gen is the snail
            goto reset_apple;
        } else {
            //Code for apple
            int apple_count = count_apples (size_board_x, size_board_y, playingboard);
            if ((apple_count == 1) || (apple_count == 3)) {
                //Already has a apple or barrier. No generation
                ;
            } else {
                playingboard [apple_y][apple_x] = 2;
            }
        } command = get_keypress ();
        if (command == 0) continue;
        if (command == 'w') {
            new_x = current_x;
            new_y = current_y - 1;
            if ((new_y == size_board_y) || (new_y == -1)) {
                break;
            } else {
                ;
            } //Placeholder
            if (playingboard [new_y][new_x] == 3) {
                printf ("You have hit a rock and died.\n");
                exit (0);
            } else {
                if (playingboard [new_y][new_x] == 2) {
                    score++;
                } else {
                    ;
                }
            }
            playingboard [current_y][current_x] = 0;
            playingboard [new_y][new_x] = 1;
            current_x = new_x;
            current_y = new_y;
            new_x = 0;
            new_y = 0;
        } else if (command == 'a') {
            new_x = current_x - 1;
            new_y = current_y;
            if ((new_x == size_board_x) || (new_x == -1)) {
                break;
            } else {
                ;
            } //Placeholder
            if (playingboard [new_y][new_x] == 3) {
                printf ("You have hit a rock and died.\n");
                disable_raw_mode ();
                exit (0);
            } else {
                if (playingboard [new_y][new_x] == 2) {
                    score++;
                } else {
                    ;
                }
            }
            playingboard [current_y][current_x] = 0;
            playingboard [new_y][new_x] = 1;
            current_x = new_x;
            current_y = new_y;
            new_x = 0;
            new_y = 0;
        } else if (command == 's') {
            new_x = current_x;
            new_y = current_y + 1;
            if ((new_y == size_board_y) || (new_y == -1)) {
                break;
            } else {
                ;
            } //Placeholder
            if (playingboard [new_y][new_x] == 3) {
                printf ("You have hit a rock and died.\n");
                disable_raw_mode ();
                exit (0);
            } else {
                if (playingboard [new_y][new_x] == 2) {
                    score++;
                }
            }
            playingboard [current_y][current_x] = 0;
            playingboard [new_y][new_x] = 1;
            current_x = new_x;
            current_y = new_y;
            new_x = 0;
            new_y = 0;
        } else if (command == 'd') {
            new_x = current_x + 1;
            new_y = current_y;
            if ((new_x == size_board_x) || (new_x == -1)) {
                break;
            } else {
                ;
            } //Placeholder
            if (playingboard [new_y][new_x] == 3) {
                printf ("You have hit a rock and have died.\n");
                disable_raw_mode ();
                exit (0);
            } else {
                if (playingboard [new_y][new_x] == 2) {
                    score++;
                }
            }
            playingboard [current_y][current_x] = 0;
            playingboard [new_y][new_x] = 1;
            current_x = new_x;
            current_y = new_y;
            new_x = 0;
            new_y = 0;
        } else if (command == 'q') {
            printf ("Exiting.\n");
            disable_raw_mode ();
            exit (0);
        } else {
            printf ("Invalid Command.\n");
        } printout (size_board_y, size_board_x, playingboard, score);
    } disable_raw_mode ();
} int main () {
    main_algorithm ();
    return 0;
}
