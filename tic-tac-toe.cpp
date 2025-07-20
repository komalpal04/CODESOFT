#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void setupBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void showBoard() {
    cout << "\nthe current board:\n\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool moveIsOkay(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

bool placeMove(int row, int col) {
    if (moveIsOkay(row, col)) {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool someoneWon() {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return true;
    }

    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return true;

    return false;
}

bool gameIsDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void changePlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playTicTacToe() {
    int row, col;

    while (true) {
        showBoard();
        cout << "Player " << currentPlayer << ", it's your turn!\n";
        cout << "Pick a row and column (1 to 3 each): ";
        
        cin >> row >> col;
        row--; col--;

        if (!cin || !moveIsOkay(row, col)) {
            cout << "That's not a valid move. Try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        placeMove(row, col);

        if (someoneWon()) {
            showBoard();
            cout << "Yay! Player " << currentPlayer << " wins! \n";
            break;
        }

        if (gameIsDraw()) {
            showBoard();
            cout << "It's a draw!\n";
            break;
        }

        changePlayer();
    }
}

int main() {
    cout << "=============================\n";
    cout << "  Welcome\n";
    cout << "=============================\n";

    char again;

    do {
        setupBoard();
        currentPlayer = 'X';
        playTicTacToe();

        cout << "Want to play again? (y/n): ";
        cin >> again;
    } while (tolower(again) == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}
