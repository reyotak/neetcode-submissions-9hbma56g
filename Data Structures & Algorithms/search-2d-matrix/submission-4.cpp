class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // b_search lookin only at the last number of arrays
        // target should be last interation of l >= target and r <= target
        // b_search on the array that contains r
        int l = 0;
        int r = matrix.size() - 1;

        while (l < r) {

            int m = (r + l) / 2;
            
            if (matrix[m][0] == target) {
                return true;
            } else if (matrix[m][0] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }


        // b_search the array collum l
        if (matrix[l][0] == target) {
            return true;
        }


        if (matrix[l][0] > target) {
            l--;

            if (l < 0) {
                return false;
            }
        }

        auto arr = matrix[l];
        //std::cout << "l: " << l << " r: " << r << std::endl;

        l = 0;
        r = arr.size() - 1;

        while (l <= r) {

            int m = (r + l) / 2;
            
            if (arr[m] == target) {
                return true;
            } else if (arr[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return false;
    }
};
