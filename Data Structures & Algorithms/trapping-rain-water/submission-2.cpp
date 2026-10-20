class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> prefix_max(height.size());
        std::vector<int> suffix_max(height.size());

        int max_pre = 0, max_suff = 0;
        int l = 0, r = height.size() - 1;

        for (int i = 1; i < height.size(); i++) {
            max_pre = std::max(height[l], max_pre);
            l++;
            prefix_max[l] = max_pre;

            max_suff = std::max(height[r], max_suff);
            r--;
            suffix_max[r] = max_suff;
        }

        int res = 0;
        
        for (int i = 0; i < height.size(); i++) {
            res += std::max(std::min(prefix_max[i], suffix_max[i]) - height[i] , 0);
        }

        return res;
    }
};
