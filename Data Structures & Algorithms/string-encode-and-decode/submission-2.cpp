class Solution {
public:

    string encode(vector<string>& strs) {
        string final = "";
        for (string str : strs) {
            string::iterator it;
            for (auto it = str.begin(); it != str.end(); it++) {
                if (*it == ',') {
                    final += ",";
                }
                final += *it;
            }
            final += ",w";
        }
        cout << final << endl;
        return final;
    }

    vector<string> decode(string s) {
        string::iterator it;
        vector<string> final;
        string curString;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it == ',') {
               if (it != s.end() && *(it + 1) == 'w') {
                    int commaCount = 0;
                    for (string::iterator lookback = it; lookback != s.begin(); --lookback) {
                        if (*(lookback-1) == ',') {
                            ++commaCount;
                        } else {
                            break;
                        }
                    }
                    if (it == s.begin() || commaCount % 2 == 0) {
                        final.push_back(curString);
                        curString = "";
                        ++it;
                        continue;
                    }
               }
            }
            if (it != s.end() && *it == ',' && *(it+1) == ',') {
                ++it;
            }
            curString += *it;
        }
        return final;
    }
};
