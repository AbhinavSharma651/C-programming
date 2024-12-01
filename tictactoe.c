#include <stdio.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int checkWinner() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;

    return 0;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Player %c, enter row and column (0-2) to place your mark: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

int main() {
    int winner = 0;
    int turnCount = 0;

    initializeBoard();
    currentPlayer = 'X';

    while (turnCount < 9 && winner == 0) {
        displayBoard();
        playerMove();
        turnCount++;
        
        winner = checkWinner();
        
        if (winner) {
            displayBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

       
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (!winner) {
        displayBoard();
        printf("It's a draw!\n");
    }

    return 0;
}
