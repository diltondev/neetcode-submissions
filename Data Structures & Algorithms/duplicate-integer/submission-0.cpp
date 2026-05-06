class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (int num : nums) {
            if (s.contains(num)) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};