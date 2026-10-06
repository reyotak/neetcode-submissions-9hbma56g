class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        std::map<std::pair<int, int>, unordered_set<char>> check_sq_map;
        std::map<int, std::unordered_set<char>> check_row;
        std::map<int, std::unordered_set<char>> check_collumn;

        for (int i = 0; i < board.size(); i++) {

            for (int j = 0; j < board[i].size(); j++) {

                if (board[i][j] == '.') {
                    continue;
                }

                std::pair<int,int> sq_key = {i / 3, j / 3};

                if (check_sq_map[sq_key].count(board[i][j])) {
                    return false;
                } else {
                    check_sq_map[sq_key].insert(board[i][j]);
                }

                if (check_row[i].count(board[i][j])) {
                    return false;
                } else {
                    check_row[i].insert(board[i][j]);
                }

                if (check_collumn[j].count(board[i][j])) {
                    return false;
                } else {
                    check_collumn[j].insert(board[i][j]);
                }

            }
        }

        return true;
    }
};
