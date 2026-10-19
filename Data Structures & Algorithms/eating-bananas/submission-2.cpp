class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //upper bond is max number in piles
        int max = 0;
        for (auto &i : piles) {
            max = std::max(max, i);
        }

        // binary search the value where we found the lowest value until
        // the eating rate is not enough

        int l = 1, r = max, res = 0;
        
        while (l <= r) {
            int m = (l + r) / 2;
            int needed_h = 0;
            for (auto &i : piles) {
                needed_h += std::ceil(i * 1.0 / m);
            }
            if (needed_h > h) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l > r ? l : r;
    }
};
