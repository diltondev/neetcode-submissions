class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> countsStrings;
        for (string str : strs) {
            int counts[26] = {0};
            for (char ch : str) {
                const int index = static_cast<int>(ch) - 'a'; 
                counts[index]++;
            }
            string stringified = "";
            for (int count : counts) {
                stringified += std::to_string(count) + ",";
            }
                    
            auto location = countsStrings.find(stringified);
            if (location == countsStrings.end()) {
                vector<string> *newArr = new vector<string>;
                newArr->emplace_back(str);
                countsStrings[stringified] = *newArr;
            } else {
                location->second.emplace_back(str);
            }
        }
        vector<vector<string>> result;
        for (auto& [counts, strList] : countsStrings) {
            result.push_back(std::move(strList));
        }
        return result;
    } 
};
