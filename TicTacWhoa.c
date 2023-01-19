#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int printBoard(char input[2], int turnCounter);
int checkifWinner(char board[50]);

int printBoard(char input[2], int turnCounter){
        
        //determines position of X or O based on input given
        int turn;
        if (input[0] == 'A'){ 
            if (input[1] == '1'){turn = 31;}
            else if (input[1] == '2'){turn = 17;}
            else if (input[1] == '3') {turn = 3;}
        }
        else if (input[0] == 'B') {
            if (input[1] == '1'){turn = 35;}
            else if (input[1] == '2'){turn = 21;}
            else if (input[1] == '3') {turn = 7;}
            }
        
        else if (input[0] == 'C') {
            if (input[1] == '1'){turn = 39;}
            else if (input[1] == '2'){turn = 25;}
            else if (input[1] == '3') {turn = 11;}
            }
        
        return turn;
}

int checkifWinner (char board[50]) {
    // winNum = 1(user1 wins), 2 (user2 wins), 3 (neither,continues)
    int winNum;
    
    if ((board[3] == 'X'&& board[7] == 'X'&& board[11] == 'X') ||
    (board[17] == 'X'&& board[21] == 'X' && board[25] == 'X') ||
    (board[31] == 'X'&& board[35] == 'X'&& board[39] == 'X') ||
    (board[3] == 'X'&& board[17] == 'X'&& board[31] == 'X')||
    (board[7] == 'X'&& board[21] == 'X'&& board[35] == 'X') ||
    (board[11] == 'X'&& board[25] == 'X'&& board[39] == 'X') ||
    (board[3] == 'X'&& board[21] == 'X'&& board[39] == 'X') ||
    (board[11] == 'X'&& board[21] == 'X'&& board[31] == 'X')) {
        winNum = 1;
    }
    else if ((board[3] == 'X'&& board[7] == 'X'&& board[11] == 'X') ||
    (board[17] == 'O'&& board[21] == 'O' && board[25] == 'O') ||
    (board[31] == 'O'&& board[35] == 'O'&& board[39] == 'O') ||
    (board[3] == 'O'&& board[17] == 'O'&& board[31] == 'O') ||
    (board[7] == 'O'&& board[21] == 'O'&& board[35] == 'O') ||
    (board[11] == 'O'&& board[25] == 'O'&& board[39] == 'O') ||
    (board[3] == 'O'&& board[21] == 'O'&& board[39] == 'O') ||
    (board[11] == 'O'&& board[21] == 'O'&& board[31] == 'O')){
        winNum = 2;
    }
    else {winNum = 3;}
    
    return winNum;   
}


int main(void){
        char user1[24];
        char user2[24];
        char move[4];
        int turnCounter = 0;
        int winNum;
        bool continuePlaying = true;
        int turn;
        char board[] = "3 ___|___|___\n2 ___|___|___\n1    |   |   \n   A   B   C ";
        int previousMoves[9];
        
        printf("Welcome to TicTacWhoa!\n Player 1, please enter your name: ");
        scanf("%s", user1);
        printf("Player 1 = %s \nPlayer 2, please enter your name: ", user1);
        scanf("%s", user2);
        printf("Player 2 = %s",user2);
        printf("\n%s",board);
        
        //loop until all turns are completed
        while (continuePlaying == true) {
        bool validInput = false;
        turnCounter++;
        //keeps track of whose turn it is
        if (turnCounter == 1 || turnCounter == 3 || turnCounter == 5 || turnCounter == 7 ){
           printf("\n%s, It's your turn!", user1); }
        else if (turnCounter == 2 || turnCounter == 4 || turnCounter == 6 || turnCounter == 8){
            printf("\n%s, It's your turn!", user2);}
        
        printf("\nEnter your move: ");
        scanf("%s", move);  
        
        //check input and handle incorrect input
        while (validInput == false){
            int moveLength = 0;
            for (int i=0; move[i] != 0; i++){moveLength++;}
            if (moveLength == 1){
                printf("Invalid move, please specify both column and row.");
                printf("\nEnter your move: ");
                scanf("%s", move);  
                validInput = false;
            }
            else if (move[0] == 'q' && move[1] == 'u' && move[2] == 'i' && move[3] == 't'){
                printf("Exitting game...");
                exit(1);
            }
            else if (moveLength >= 3 && move != "quit"){
                printf("Invalid move, please only specify one column and one row.");
                printf("\nEnter your move: ");
                scanf("%s", move);
                validInput = false;
            }
            else if( (move[0] == 'A' || move[0] == 'B' || move[0] == 'C') && (move[1] == '1' || move[1] == '2' || move[1] == '3') ){
                validInput = true;
            }
            else {
                printf("Invalid move, input is out of range.");
                printf("\nEnter your move: ");
                scanf("%s", move);
                validInput = false;
            }
        }
        validInput = false;
        
        
        while (validInput == false) {
            int bad =0;
        //determines which board piece to update based on user input and which user
        turn = printBoard(move, turnCounter);
        for (int i=1; i<=9; i++){
            if (previousMoves[i] == turn){
                bad = 1;
            }
            else {
                
            }
        }
        if (bad == 1){
            printf("%s", board);
            printf("\nThis spot is already occupied. Enter a new move: ");
                scanf("%s", move);
                validInput = false;
        }
        else {
            validInput = true;
        }
        
        }
        previousMoves[turnCounter] = turn;
        
        if (turnCounter == 1 || turnCounter == 3 || turnCounter == 5 || turnCounter == 7 ){
            board[turn]= 'X';}
        else if (turnCounter == 2 || turnCounter == 4 || turnCounter == 6 || turnCounter == 8){
            board[turn] = 'O';}
        printf("%s",  board);
        
        //check who the winner is or if the game should continue
        winNum = checkifWinner(board);
        if (turnCounter == 9){continuePlaying = false;
        printf("\nTie! End of game");
        exit(1);}
        else if (winNum == 1) {
            continuePlaying = false;
            printf ("\nGame over. %s wins", user1);
            exit(1);
        }
        else if (winNum == 2) {
            continuePlaying = false;
            printf ("\n Game over. %s wins", user2);
            exit(1);
        }
        else {
            continuePlaying = true;
        }
        
        }
        
        return 0;
        }