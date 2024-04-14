class Solution {
public:
    void storeSolution(vector<vector<char>>& board, int n,
                       vector<vector<string>>& ans) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string output="";
            for (int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
        // check karenge ki kya current cell p queen rakh sakte hai ki nhii
        // row safety check
        int i = row;
        int j = col;
        while (j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            j--;
        }

        i = row;
        j = col;
        // upper left diagonal check
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        i = row;
        j = col;
        // lower left diagonal check
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }
        // khii bhii queen nhii mili to return true akrdo
        return true;
    }
    void solve(vector<vector<char>>& board, int col, int n,
               vector<vector<string>>& ans) {
        if (col >= n) {
            storeSolution(board, n, ans);
            return;
        }
        // 1 case solve karna baaki recurssion sambhaal lega
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                // safe hai to rakh do
                board[row][col] = 'Q';
                // baaki solution recursiion laayega
                solve(board, col + 1, n, ans);
                // backtracking lagaao
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int col = 0;
        solve(board, col, n, ans);
        return ans;
    }
};