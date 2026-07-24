class Solution {
   public:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int left_index = 0;
        int right_index = s.size() - 1;
        while (left_index < right_index) {
            const char lchar = std::tolower(s[left_index]);
            const char rchar = std::tolower(s[right_index]);
            if ((lchar < '0' || lchar > '9') && (lchar < 'a' || lchar > 'z')) {
                ++left_index;
                continue;
            }
            if ((rchar < '0' || rchar > '9') && (rchar < 'a' || rchar > 'z')) {
                --right_index;
                continue;
            }
            if (lchar != rchar) {
                return false;
            }
            ++left_index;
            --right_index;
            // std::cout << "Left : " << left_index << " Right : " << right_index << std::endl;
        }
        return true;
    }
};
