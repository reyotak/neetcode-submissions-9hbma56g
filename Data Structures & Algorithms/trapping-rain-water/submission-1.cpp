class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> prefix_max(height.size());
        std::vector<int> suffix_max(height.size());

        int max = 0;
        for (int l = 1; l < height.size(); l++) {
            max = std::max(height[l - 1], max);
            prefix_max[l] = max;
        }

        max = 0;
        for (int r = height.size() - 2; r >= 0; r--) {
            max = std::max(height[r + 1], max);
            suffix_max[r] = max;
        }

        int res = 0;
        
        for (int i = 0; i < height.size(); i++) {
            res += std::max(std::min(prefix_max[i], suffix_max[i]) - height[i] , 0);
        }
        

        return res;
    }
};
