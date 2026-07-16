class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // holds the start and end int values of runs
        unordered_set<int> found;
        for (int num : nums) {
            found.insert(num);
        }
        int cur_count = 0;
        int max_count = 0;
        for (int num : nums) {
            // is the start of a run
            if (found.find(num-1) == found.end()) {
                cur_count = 1;
                for (int i = 1; found.find(num+i) != found.end(); ++i) {
                    ++cur_count;
                }
                if (max_count < cur_count) {
                    max_count = cur_count;
                }
            }
        }
        return max_count;
    }

};
