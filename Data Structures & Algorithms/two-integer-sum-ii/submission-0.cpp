class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left_idx = 0;
        int right_idx = numbers.size() - 1;

        while (left_idx < right_idx) {
            const int left = numbers[left_idx];
            const int right = numbers[right_idx];
            if (left + right == target) {
                vector<int> result = {left_idx + 1, right_idx + 1};
                return result;
            }
            if (left + right > target) {
                --right_idx;
                continue;
            }
            ++left_idx;
        }
    }
};
