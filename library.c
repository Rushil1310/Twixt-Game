#include <stdio.h>
#include "library.h"

void printboard(char arr[24][24]){
    for(int i=0;i<24;i++){
        if(i==0){
            printf("  00  |"); 
            for(int j=1;j<23;j++) printf("%02d ",j);
            printf("| 23\n");
        }
        if(i==1||i==23){
            printf("------+------------------------------------------------------------------+----\n");
        }
        for(int j=0;j<24;j++){
            if(j==0) printf("%02d ",i);
            if(j==1){
                printf("|");
            }
            if (arr[i][j] == player_1 || arr[i][j] == player_1-'A'+'a')
                printf("\033[1;32m%c\033[0m  ",arr[i][j]);
            else if (arr[i][j] == player_2 || arr[i][j] == player_2-'A'+'a')
                printf("\033[1;31m%c\033[0m  ",arr[i][j]);
            else if (arr[i][j] == '.')
                printf("\033[1;33m%c\033[0m  ",arr[i][j]);
            if(j==22){
                printf("|");
            }
        }
        printf("\n");
    }
}

int is_crossing(char arr[24][24],int i1,int j1,int i2,int j2,char player){
    int i_low = (i1>i2)*i2 + (i2>i1)*i1; 
    int j_low = (j1>j2)*j2 + (j2>j1)*j1;   
    int i_high = (i1>i2)*i1 + (i2>i1)*i2;
    int j_high = (j1>j2)*j1 + (j2>j1)*j2;
    char opp = player_1;
    if(player==player_1){
        opp = player_2;
    }
    for (int i=i_low;i<=i_high;i++){
        for (int j=j_low;j<=j_high;j++){
            if(arr[i][j]==opp - 'A' + 'a'||arr[i][j]==player - 'A' + 'a'){
                int pos[8][2] = {
                    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
                };
                for (int d = 0; d < 8; d++) {
                    int ni = i + pos[d][0];
                    int nj = j + pos[d][1];
                    if (ni >= 0 && ni < 24 && nj >= 0 && nj < 24) {
                        if (arr[ni][nj] == opp - 'A' + 'a') {
                            if((float)(ni+i)/2 <= i_high && (float)(ni+i)/2 >= i_low&&(float)(nj+j)/2 <= j_high && (float)(nj+j)/2 >= j_low){
                                printf("There is an overlap between %d %d pos and %d %d pos's node and the node you are making\n",ni,nj,i,j);
                                printf("This may be due to %f,%f lying inside the  area formed %d %d %d %d\n",(float)(i+ni)/2,(float)(j+nj)/2,i_low,j_low,i_high,j_high);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

void check_p1(char arr[24][24],int visited[24][24],int pos[8][2],int i,int j){
    if(is_quit) return;
    if(i==23){//base case h
        printf("LES GO , PLAYER 1 WON !!\n");
        printf("1st -> %c | 2nd -> %c",player_1,player_2);
        is_quit = 1;
        return;
    }
    if(visited[i][j]) return;
    visited[i][j] = 1;
    for(int k = 0; k < 8; k++){
        int ni = i+pos[k][0];
        int nj = j+pos[k][1];
        if(ni>=0&&ni<24&&nj>=0&&nj<24&&arr[ni][nj]==player_1-'A'+'a'&&visited[ni][nj]==0) check_p1(arr,visited,pos,ni,nj);
    }
}

void is_p1_win(char arr[24][24], int visited[24][24]) {
    int pos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (int j = 0; j < 24; j++) {
        if (arr[0][j] == player_1 - 'A' + 'a') {
            check_p1(arr,visited,pos,0,j);
            if (is_quit) return;
        }
    }

    /* while(nodes_visited<=nodes_p1){
        for(int k=0;k<8;k++){
            int ni = i + pos[k][0];
            int nj = j + pos[k][1];
            if (ni>=0&&ni<24&&nj>=0&&nj<24&&arr[ni][nj]==player_1-'A'+'a'&&visited[ni][nj]==0){
                nodes_visited ++;
                visited[ni][nj] = 1;
                i = ni;
                j = nj;
            }
        }
        if(i==23){
            printf("PLAYER 1 WINS !!!\nCrown goes to %c",player_1);
            is_quit = 1;
            return;
        }
    }*/
}

void check_p2(char arr[24][24],int visited[24][24],int pos[8][2],int i,int j){
    if(is_quit) return;
    if(j==23){//base case h
        printf("LES GO , PLAYER 2 WON !!\n");
        printf("1st -> %c | 2nd -> %c",player_2,player_1);
        is_quit = 1;
        return;
    }
    if(visited[i][j]) return;
    visited[i][j] = 1;
    for(int k=0;k<8;k++){
        int ni = i+pos[k][0];
        int nj = j+pos[k][1];
        if(ni>=0&&ni<24&&nj>=0&&nj<24&&arr[ni][nj]==player_2-'A'+'a'&&visited[ni][nj]==0) check_p2(arr,visited,pos,ni,nj);
    }
}

void is_p2_win(char arr[24][24], int visited[24][24]) {
    int pos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (int i=0;i<24;i++) {
        if (arr[i][0] == player_2-'A'+'a') {
            check_p2(arr,visited,pos,i,0);
            if (is_quit) return;
        }
    }
}

void move(char player,char arr[24][24],int move_index){
    printf("ENTER -1 -1 to quit -2 -2 for instructions |\n");
    printf("PLAYER %c | PLAY YOUR MOVE <ROW> <COLUMN> : ",player);
    int pos_i, pos_j;
    scanf("%d %d",&pos_i,&pos_j);
    if(pos_i==-2&&pos_j==-2){
        printf("THE SET OF GENERAL INSTRUCTIONS:\n");
        printf("\tThere will be 2 players 1st player wins by making a sequence from up to down\n");
        printf("\tThe second player needs to make it from side to side\n");
        printf("\tpieces cant make links that intersect a link can only be made when there is a sqrt(5) distance between 2 nodes\n");
        printf("\tLinks are represented by lowercase char of the same letter\n");
        return;
    }
    if(pos_i==-1&&pos_j==-1){
        is_quit = 1;
        return;
    }
    if(player==player_2&&(pos_i==0||pos_i==23)){
        printf("THAT IS NOT YOUR TERRITORY BRO\nTRY AGAIN\n");
        move(player,arr,move_index);
        return;
    }
    if(player==player_1&&(pos_j==0||pos_j==23)){
        printf("THAT IS NOT YOUR TERRITORY BRO\nTRY AGAIN\n");
        move(player,arr,move_index);
        return;
    }
    if(arr[pos_i][pos_j]=='.'&&pos_i>=0&&pos_i<=23&&pos_j>=0&&pos_j<=23){
        arr[pos_i][pos_j] = player;
    int pos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (int d = 0; d < 8; d++) {
        int ni = pos_i + pos[d][0];
        int nj = pos_j + pos[d][1];
        if (ni >= 0 && ni < 24 && nj >= 0 && nj < 24) {
            if (arr[ni][nj] == player || arr[ni][nj] == player-'A'+'a') {
                int cross = is_crossing(arr,pos_i,pos_j,ni,nj,player);
                if(cross==0){
                    printf("LINKS ARE CROSSING SO DO IT WILL BE PLACED WITHOUT A LINKS\n");
                    arr[pos_i][pos_j] = player;
                    return;
                }
                arr[pos_i][pos_j] = player-'A'+'a';
                if (arr[ni][nj] == player){
                    arr[ni][nj] = player-'A'+'a';
                }
            }
        }
    }
    }
    else{
        printf("INVALID POSITION\nTry again -- \n");
        move(player,arr,move_index);
        return;
    }
    printboard(arr);
}