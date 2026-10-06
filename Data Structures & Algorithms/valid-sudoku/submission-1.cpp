class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int mask_sq[10] = {0};
        int mask_row[10] = {0};
        int mask_collumn[10] = {0};

        for (int i = 0; i < board.size(); i++) {

            for (int j = 0; j < board[i].size(); j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                int sq_key = (i / 3) + ((j / 3) * 3);

                if (mask_sq[sq_key] & (1 << board[i][j]) 
                    || mask_row[i] & (1 << board[i][j])
                    || mask_collumn[j] & (1 << board[i][j])) {
                    return false;
                }

                mask_sq[sq_key] |= 1 << board[i][j];
                mask_row[i] |= 1 << board[i][j];
                mask_collumn[j] |= 1 << board[i][j];
            }
        }

        return true;
    }
};
