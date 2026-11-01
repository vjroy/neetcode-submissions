
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        int ans = 0;

        if (s.size() == 1)
            return 1;

        unordered_set<char> seen;
        for (int i = 0; i < s.size(); ++i) {
            if (!seen.count(s[i])) {
                seen.insert(s[i]);
                if (seen.size() > ans) {
                    ans = seen.size();
                }
            }

            else {
                {
                    if (seen.size() > ans) {
                        ans = seen.size();
                    }
                    while (seen.count(s[i])) {
                        seen.erase(s[l]);
                        l++;
                    }

                    seen.insert(s[i]);
                }
            }
        }

        return ans;
    }
};

