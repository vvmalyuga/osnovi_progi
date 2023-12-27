
//------------------------------------------------------ #4 ------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<string>& board, int row, int col) {
    int n = board.size();
    // Проверка вертикали и диагоналей
    for (int i = 0; i < row; ++i) {
        if (i < n && col < board[i].size() && board[i][col] == 'Q') {
            return false;
        }
        if (i < n && col - row + i >= 0 && board[i][col - row + i] == 'Q') {
            return false;
        }
        if (i < n && col + row - i < board[i].size() && board[i][col + row - i] == 'Q') {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<string>& board, int row, int n, vector<string>& result) {
    if (row == n) {
        result.push_back("[\"" + board[0]);
        for (int i = 1; i < n; ++i) {
            result.back() += "\",\"" + board[i];
        }
        result.back() += "\"]";
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n, result);
            board[row][col] = '.';
        }
    }
}

vector<string> solveNQueens(int n) {
    vector<string> result;
    vector<string> board(n, string(n, '.'));

    solveNQueens(board, 0, n, result);

    // нет решений 
        if (result.empty()) {
        result.push_back("No solution");
    }

    return result;
}

int main() {
    int n;
    cout << "Enter n (1<=n<=9)\n";
    cin >> n;

    vector<string> result = solveNQueens(n);

    if (result[0] == "No solution") {
        cout << "No solutions found :(" << endl;
    }
    else {
        cout << "[" << result[0];
        for (int i = 1; i < result.size(); ++i) {
            cout << "," << result[i];
        }
        cout << "]" << endl;
    }

    return 0;
}
