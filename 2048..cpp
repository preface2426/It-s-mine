#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int SIZE = 4;

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }
}

void moveLeft(vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        vector<int> newRow;
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 0) {
                newRow.push_back(board[i][j]);
            }
        }
        int k = 0;
        for (int j = 0; j < SIZE; ++j) {
            if (newRow[j] == 0) {
                while (k < SIZE && newRow[k] != 0) ++k;
                if (k < j) {
                    newRow[j] = newRow[k];
                    newRow[k] = 0;
                }
            }
        }
        for (int j = 0; j < SIZE; ++j) {
            if (newRow[j] == 0 && j > 0 && newRow[j-1] != 0) {
                if (newRow[j-1] == 0) {
                    newRow[j] = newRow[j-1];
                    newRow[j-1] = 0;
                } else {
                    newRow[j] *= 2;
                    newRow[j-1] = 0;
                }
            }
        }
        board[i] = newRow;
    }
}

void moveRight(vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        vector<int> newRow(SIZE, 0);
        for (int j = SIZE - 1; j >= 0; --j) {
            if (board[i][j] != 0) {
                newRow[SIZE - 1] = board[i][j];
                int k = SIZE - 1;
                for (int p = SIZE - 2; p >= 0; --p) {
                    if (newRow[p] == 0) {
                        while (k >= 0 && newRow[k] != 0) --k;
                        if (k < p) {
                            newRow[p] = newRow[k];
                            newRow[k] = 0;
                        }
                    }
                }
                for (int p = SIZE - 1; p > 0 && newRow[p] == 0 && newRow[p-1] != 0; --p) {
                    if (newRow[p-1] == 0) {
                        newRow[p] = newRow[p-1];
                        newRow[p-1] = 0;
                    } else {
                        newRow[p] *= 2;
                        newRow[p-1] = 0;
                    }
                }
            }
        }
        board[i] = newRow;
    }
}

void moveUp(vector<vector<int>>& board) {
    vector<vector<int>> newBoard(SIZE, vector<int>(SIZE, 0));
    for (int j = 0; j < SIZE; ++j) {
        vector<int> newRow;
        for (int i = 0; i < SIZE; ++i) {
            if (board[i][j] != 0) {
                newRow.push_back(board[i][j]);
            }
        }
        moveLeft(newRow);
        for (int i = 0; i < SIZE; ++i) {
            newBoard[i][j] = newRow[i];
        }
    }
    board = newBoard;
}

void moveDown(vector<vector<int>>& board) {
    vector<vector<int>> newBoard(SIZE, vector<int>(SIZE, 0));
    for (int j = 0; j < SIZE; ++j) {
        vector<int> newRow(SIZE, 0);
        for (int i = SIZE - 1; i >= 0; --i) {
            if (board[i][j] != 0) {
                newRow[SIZE - 1] = board[i][j];
                int k = SIZE - 1;
                for (int p = SIZE - 2; p >= 0; --p) {
                    if (newRow[p] == 0) {
                        while (k >= 0 && newRow[k] != 0) --k;
                        if (k < p) {
                            newRow[p] = newRow[k];
                            newRow[k] = 0;
                        }
                    }
                }
                for (int p = SIZE - 1; p > 0 && newRow[p] == 0 && newRow[p-1] != 0; --p) {
                    if (newRow[p-1] == 0) {
                        newRow[p] = newRow[p-1];
                        newRow[p-1] = 0;
                    } else {
                        newRow[p] *= 2;
                        newRow[p-1] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            newBoard[i][j] = newRow[SIZE - 1 - i];
        }
    }
    board = newBoard;
}

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));
    // Initialize with two random tiles
    for (int i = 0; i < 2; ++i) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        while (board[row][col] != 0) {
            row = rand() % SIZE;
            col = rand() % SIZE;
        }
        board[row][col] = (rand() % 2 + 1) * 2; // Random 2 or 4
    }

    char command;
    do {
        printBoard(board);
        cout << "Enter move (WASD): ";
        cin >> command;
        command = tolower(command);

        switch (command) {
            case 'a':
                moveLeft(board);
                break;
            case 'd':
                moveRight(board);
                break;
            case 'w':
                moveUp(board);
                break;
            case 's':
                moveDown(board);
                break;
            default:
                cout << "Invalid move. Please use WASD to move the tiles." << endl;
                break;
        }

        // Add a new tile after each move
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        while (board[row][col] != 0) {
            row = rand() % SIZE;
            col = rand() % SIZE;
        }
        board[row][col] = (rand() % 2 + 1) * 2; // Random 2 or 4

    } while (command != 'q');

    return 0;
}