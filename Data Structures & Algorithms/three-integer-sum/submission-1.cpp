#include <algorithm>
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (k > j) {
                const int cur_sum = nums[k] + nums[j];
                // cout << "Checking : " << nums[i] << ", " << nums[j] << ", " << nums[k] <<
                // std::endl;
                if (-nums[i] == cur_sum) {
                    // cout << "triplet" << endl;
                    vector<int> t = {nums[i], nums[j], nums[k]};
                    --k;
                    bool found = false;
                    for (vector<int> trip : triplets) {
                        if (trip[0] == t[0] && trip[1] == t[1] && trip[2] == t[2]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) triplets.emplace_back(t);

                } else if (cur_sum < -nums[i]) {
                    ++j;
                } else if (cur_sum > -nums[i]) {
                    --k;
                }
            }
        }
        return triplets;
    }
};
