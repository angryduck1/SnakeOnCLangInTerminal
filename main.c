#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

void logo() {
    printf("       /^\\/^\\\n");
    printf("     _|__|   |\n");
    printf("\\/     /~     \\_/ \\\n");
    printf(" \\____|__________/  \\\n");
    printf("        \\_______      \\\n");
    printf("                `\\     \\                 \\\n");
    printf("                  |     |                  \\\n");
    printf("                 /      /                    \\\n");
    printf("                /     /                       \\\\\n");
    printf("              /      /                         \\ \\\n");
    printf("             /     /                            \\  \\\n");
    printf("           /     /             _----_            \\   \\\n");
    printf("          /     /           _-~      ~-_         |   |\n");
    printf("         (      (        _-~    _--_    ~-_     _/   |\n");
    printf("          \\      ~-____-~    _-~    ~-_    ~-_-~    /\n");
    printf("            ~-_           _-~          ~-_       _-~\n");
    printf("               ~--______-~                ~-___-~\n");
    printf("\t Change your layout to English and relax");
    usleep(3000000);
}

int main() {
    logo();
    int weight = 15;
    int height = 10;

    int food = {0, 0};

    int max_snake = 5;
    char input_controller = 's';
    
    int head[2] = {0, 6};
    int body[5][2];

    body[0][0] = 0; body[0][1] = 5;
    body[1][0] = 0; body[1][1] = 4;
    body[2][0] = 0; body[2][1] = 3;
    body[3][0] = 0; body[3][1] = 2;
    body[4][0] = 0; body[4][1] = 1;

    bool flag = true;

    while(flag == true) {
        system("cls || clear");
        for (int i = 1; i < weight; i++){
        printf("0");
    }
        printf("0");
        
        if (kbhit()) {
            char ch = getch();
            if (ch == 'w' || ch == 'W') {
                input_controller = 'w';
            } else if (ch == 's' || ch == 'S') {
                input_controller = 's';
            } else if (ch == 'a' || ch == 'A') {
                input_controller = 'a';
            } else if (ch == 'd' || ch == 'D') {
                input_controller = 'd';
            } else if (ch == 27) {
                break;
            }
        }

        switch(input_controller) {
            case 'w':
                head[1] -= 1;
                break;
            case 's':
                head[1] += 1;
                break;
            case 'a':
                head[0] -= 1;
                break;
            case 'd':
                head[0] += 1;
                break;
        }
        
        for (int i = max_snake - 1; i > 0; i--) {
            memcpy(body[i], body[i - 1], sizeof(body[i]));
        }

        body[0][0] = head[0]; 
        body[0][1] = head[1];

        if (head[1] < 1 || head[1] >= height || head[0] < 0 || head[0] >= weight) {
            max_snake = 5;
            input_controller = 's';

            memset(head, 0, sizeof(head));
            memset(body, 0, sizeof(body));

            head[0] = 0;
            head[1] = 6;
            body[5][2];

            body[0][0] = 0; body[0][1] = 5;
            body[1][0] = 0; body[1][1] = 4;
            body[2][0] = 0; body[2][1] = 3;
            body[3][0] = 0; body[3][1] = 2;
            body[4][0] = 0; body[4][1] = 1;

            flag = true;

            usleep(555000);

        }

     {
        for(int h = 0; h < height; h ++) {
            for(int w = 0; w < weight; w ++) {
                if (w == head[0] && h == head[1]) {
                    printf("1");
                } else {
                    bool isBodyPart = false;
                    for(int i = 0; i < 5; i ++) {
                      if(h == body[i][1] && w == body[i][0]) {
                        printf("2");
                        isBodyPart = true;
                        break;
                        }
                    }
                    if(!isBodyPart) {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }

        for (int i = 0; i <= weight; i++){
        printf("0");
        }

       }
        
        usleep(55000);
    }
    return 0;
}