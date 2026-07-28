#include <algorithm>

class Solution {
   public:
    int trap(vector<int>& height) {
        vector<int> l_max;
        vector<int> r_max;
        l_max.reserve(height.size());
        r_max.reserve(height.size());

        l_max[0] = height[0];
        r_max[height.size() - 1] = height[height.size() - 1];
        for (int i_l = 1; i_l < height.size(); i_l++) {
            const int i_r = height.size() - 1 - i_l;
            l_max[i_l] = max(height[i_l], l_max[i_l - 1]);
            r_max[i_r] = max(height[i_r], r_max[i_r + 1]);
        }
        int total_water = 0;
        for (int i = 0; i < height.size(); i++) {
            const int fill = max(min(l_max[i], r_max[i]), height[i]);
            total_water += fill - height[i];
        }
        return total_water;
    }
};
