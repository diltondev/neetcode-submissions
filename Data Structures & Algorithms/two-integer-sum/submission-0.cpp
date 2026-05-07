class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> s; // value -> nums index
        for (int i = 0; i < nums.size(); i++) {
            auto diff = s.find(target-nums[i]);
            if (diff != s.end()) {
                int ind = diff->second;
                vector<int> result = {ind, i};
                return result;
            }
            s[nums[i]] = i;
        }
        return vector<int>(2);
    }
};
