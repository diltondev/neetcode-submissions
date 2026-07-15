class Solution {
   public:
    // Challenge: O(n) and no division
    vector<int> productExceptSelf(vector<int>& nums) {
        // pp = partial products; product of 0..n or n..0 (left and right)
        vector<int> left_pp(nums.size());
        vector<int> right_pp(nums.size());
        vector<int> final(nums.size());
        left_pp[0] = nums[0];
        right_pp[right_pp.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); ++i) {
            int j = right_pp.size() - 1 - i;
            left_pp[i] = left_pp[i - 1] * nums[i];
            right_pp[j] = right_pp[j + 1] * nums[j];
        }
        final[0] = right_pp[1];
        final[final.size()-1] = left_pp[left_pp.size()-2];
        for (int i = 1; i < final.size()-1; ++i) {
            final[i] = left_pp[i-1] * right_pp[i+1];
        }
        
        return final;
    }
};

