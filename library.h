#ifndef LIBRARY_H
#define LIBRARY_H
extern char player_1, player_2;
extern int is_quit;
void printboard(char arr[24][24]);
int is_crossing(char arr[24][24],int i1,int j1,int i2,int j2,char player);
void check_p1(char arr[24][24],int visited[24][24],int pos[8][2],int i,int j);
void is_p1_win(char arr[24][24], int visited[24][24]);
void check_p2(char arr[24][24],int visited[24][24],int pos[8][2],int i,int j);
void is_p2_win(char arr[24][24], int visited[24][24]);
void move(char player,char arr[24][24],int move_index);
#endif