class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        std::vector<std::vector<int>> buckets(nums.size() + 1, std::vector<int>(0));
        for (const int num : nums) {
            if (!counts.contains(num)) {
                counts[num] = 0;
            }
            counts[num]++;
        }
        for (const auto& [num, count] : counts) {
            buckets[count].emplace_back(num);
        }
        std::vector<int> result = *(new std::vector<int>);
        result.reserve(k);
        for (int i = buckets.size() - 1; i > 0; i--) {
            for (int num : buckets[i]) {
                result.emplace_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
    }
};
