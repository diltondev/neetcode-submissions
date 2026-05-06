class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> sM;
        std::unordered_map<char, int> tM;
        for (char sChar : s) {
            if (!sM.contains(sChar)) {
                sM[sChar] = 0;
            }
            sM[sChar]++;
        }
        for (char tChar : t) {
            if (!tM.contains(tChar)) {
                tM[tChar] = 0;
            }
            tM[tChar]++;
        }
        for (auto& [sChar, sCount] : sM) {
            if (sCount != tM[sChar]) {
                // s has chars at different counts (including t[sChar] == 0)
                return false;
            }
            tM.erase(sChar);
        }
        if (!tM.empty()) {
            // t has chars s doesn't have
            return false; 
        }
        return true;
    }
};
