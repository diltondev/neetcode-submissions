#include <algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Minimum and maximum valued indicies
        int min = 0;
        int max = prices.size() - 1;

        // Search list from both sides for maxes right of min and mins left of max 
        for (int l = 0, r = prices.size() - 1 - l; l < max || r > min; ++l, --r) {
            if (r > min && prices[r] > prices[max]) {
                max = r;
            }
            if (l < max && prices[l] < prices[min]) {
                min = l;
            }
        }
        // Minimum profit of 0 as if negative, just don't buy
        return std::max(prices[max] - prices[min], 0);
    }
};
