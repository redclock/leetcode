/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
class Solution {
public:
    bool isValid(int xs[9], int ys[9], vector<vector<char>>& board) {
        bool has[9] = {false};
        for (int i = 0; i < 9; i++) {
            char ch = board[xs[i]][ys[i]];
            if (ch != '.') {
                ch -= '1';
                if (has[ch]) return false;
                has[ch] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int xs[9], ys[9];
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++) {
                xs[j] = i;
                ys[j] = j;
            }
            if (!isValid(xs, ys, board)) return false;
            if (!isValid(ys, xs, board)) return false;
            int startx = i % 3 * 3;
            int starty = i / 3 * 3;
            for (int j = 0; j < 9; j++) {
                xs[j] = startx + j % 3;
                ys[j] = starty + j / 3;
            }
            if (!isValid(xs, ys, board)) return false;
        }
        return true;
    }
};