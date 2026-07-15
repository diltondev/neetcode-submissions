class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // each category is [space][int]
        // ex. cols[4][2] = true represents in 3rd column, int 1 exists

        bool squares[9][9] = {false};
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char cur_val_char = board[i][j];
                if (cur_val_char == '.') {
                    continue;
                }
                int cur_val = cur_val_char - '1';
                int square_num = ((i  / 3) * 3) + (j/ 3);
                // cur_val already in board at conflicting position
                if (squares[square_num][cur_val] ||  cols[j][cur_val] ||  rows[i][cur_val]) {
                    return false;
                }
                squares[square_num][cur_val] = true;
                rows[i][cur_val] = true;
                cols[j][cur_val] = true;
            }
        }
        return true;
    }
};
