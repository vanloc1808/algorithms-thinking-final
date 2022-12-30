#include <bits/stdc++.h>

using namespace std;

int ansCount = 0;
vector<vector<vector<int>>> ans;

// check if it is safe to place a queen at (row, col)
bool isSafe(vector<vector<int>> board, int row, int col, int n) {
    // check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // check the diagonal to the upper left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // check the diagonal to the upper right
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void n_queens(vector<vector<int>>& board, int row, int n) {
    // if all queens have been placed, add the current board to the list of solutions and return 1
    if (row == n) {
        ans.push_back(board);
        ansCount++;
        return;
    }

    // try placing the queen in each column of the current row
    for (int col = 0; col < n; col++) {
        // check if it is safe to place a queen at (row, col)
        if (isSafe(board, row, col, n)) {
            // place the queen at (row, col)
            board[row][col] = 1;

            // recursively place the remaining queens
            n_queens(board, row + 1, n);

            // remove the queen at (row, col) and try a different position
            board[row][col] = 0;
        } 
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    
    n_queens(board, 0, n);

    cout << ansCount << "\n";
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            for (int k = 0; k < ans[i][j].size(); k++) {
                if (ans[i][j][k] == 1) {
                    cout << "Q ";
                } else {
                    cout << ".";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
}