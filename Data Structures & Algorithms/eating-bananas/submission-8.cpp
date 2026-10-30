// create an array from 1 up to highest value of pile
// check the middle value and how long it takes
// if it takes h, return this value
// if it takes more than h, check second part, we need a higher eating rate
// if it takes less than h, check first part we can try a lower eating rate

// pseudo code
// find max (piles)
// vector from 1 to max
// l = 0, r = vector size - 1
// min hours = r
// while (l >= r)
// m = (l + r) / 2
// hours = for (n in piles) -> += ceil(n / m)
// if (hours == target) return m
// if hours < target 
// min_hours = hours
// r = m - 1
// else
// l = m + 1
// when end while loop return min_hours

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];
        for (auto &i : piles) {
            max = std::max(i, max);
        }

        int l = 1, r = max;
        int min_rate = max;

        while (l <= r) {

            int m = (l + r) / 2;
            long long hours = 0;

            for (auto &n : piles) {
                hours+= std::ceil((n * 1.0) / m);
            }

            if (hours <= h) {
                min_rate = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return min_rate;
    }
};
