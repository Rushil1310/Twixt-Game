#include <stdio.h>
#include "library.h"

char player_1,player_2;
int is_quit = 0;

int main(){
    char arr[24][24];
    for(int i=0;i<24;i++){for(int j=0;j<24;j++){arr[i][j]='.';}}
    printf("**ENTER THE NAMES IN CAPITALS ONLY (VIMP)**\n");
    printf("Enter player-1's and player-2's <P1> <P2> char : ");
    scanf(" %c %c",&player_1,&player_2);

    printf("Player 1 = %c | Player 2 = %c | Starting board:\n",player_1,player_2);
    printboard(arr);
    
    int move_index = 0;
    int visited[24][24] = {0};
    // for(int i=0;i<24;i++) for(int j=0;j<24;j++) visited[i][j] = 0;
    while(1){
        move(player_1,arr,move_index);
        for(int i=0;i<24;i++) for(int j=0;j<24;j++) visited[i][j] = 0;
        is_p1_win(arr,visited);
        if(is_quit) return 0;
        move(player_2,arr,move_index);
        for(int i=0;i<24;i++) for(int j=0;j<24;j++) visited[i][j] = 0;
        is_p2_win(arr,visited);
        if(is_quit) return 0;
}
    return 0;
}