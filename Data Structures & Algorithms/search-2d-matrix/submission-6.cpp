// do a regular binary search
// treat the 2d matrix as a 1d array
// just need to convert the 1d array index to a 2d matrix indexes

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int collums = matrix[0].size();

        int l = 0;
        int r = rows * collums - 1;

        // do the binary search

        while (l <= r) {
            int m = (l + r) / 2;

            // convert the 1D m position to 2D i,j position
            int i = (m / collums);
            int j = (m % collums);

            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return false;
    }
};
