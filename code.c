#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

bool checkWin(char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(int position, char mark) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == position + '0') {
                board[i][j] = mark;
                return;
            }
        }
    }
}

int main() {
    int choice;
    char currentPlayer = 'X';
    bool gameRunning = true;

    printf("Welcome to Tic Tac Toe!\n");
    displayBoard();

    while (gameRunning) {
        printf("Player %c, enter your position (1-9): ", currentPlayer);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid choice! Please pick a number between 1 and 9.\n");
            continue;
        }

        if (board[(choice - 1) / SIZE][(choice - 1) % SIZE] == 'X' ||
            board[(choice - 1) / SIZE][(choice - 1) % SIZE] == 'O') {
            printf("Position already taken! Try again.\n");
            continue;
        }

        makeMove(choice, currentPlayer);
        displayBoard();

        if (checkWin(currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            gameRunning = false;
        } else if (isDraw()) {
            printf("It's a draw!\n");
            gameRunning = false;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    printf("Game over. Thanks for playing!\n");
    return 0;
}
