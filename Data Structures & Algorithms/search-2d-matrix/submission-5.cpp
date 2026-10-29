class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        auto collumn_size = matrix[0].size();
        auto row_size = matrix.size();
        int r = (row_size * collumn_size) - 1;

        while (r >= l) {

            int m = (r + l) / 2;

            // convert this m in two part
            // what row and what collumn
            int row = m / collumn_size;
            int collumn = m % collumn_size;

            if (matrix[row][collumn] == target) {
                return true;
            } else if (matrix[row][collumn] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;
    }
};
