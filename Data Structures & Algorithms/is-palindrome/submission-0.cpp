
class Solution {
  public:
    bool isPalindrome(const std::string& s) {
        std::string filter;
        for (int i = 0; i < s.size(); ++i) {
            if (std::isalnum(s[i])) {
                filter += std::tolower(s[i]);
            }
        }

        int l = 0;
        int r = filter.size() - 1;
        while (l < r) {
            if (filter[l] != filter[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
};

