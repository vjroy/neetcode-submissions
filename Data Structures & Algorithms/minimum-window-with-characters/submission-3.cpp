
class Solution {
  public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        string ans = "";
        int best_l = 0;

        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;

        int min_len = s.size() + 1;

        for (char i : t) {
            freq_t[i]++;
        }

        int l = 0;
        for (int i = 0; i < s.size(); ++i) {
            bool contains_t = true;
            freq_s[s[i]]++;
            for (auto& [k, v] : freq_t) {
                if (!freq_s.count(k)) {
                    contains_t = false;
                    break;
                } else if (freq_s[k] < v) {
                    contains_t = false;
                    break;
                }
            }

            while (contains_t) {
                if (i - l + 1 < min_len) {
                    min_len = i - l + 1;
                    best_l = l;
                }
                freq_s[s[l]]--;
                for (auto& [k, v] : freq_t) {
                    if (freq_s[k] < v) {
                        contains_t = false;
                        break;
                    }
                }

                l++;
            }
        }

        if (min_len == s.size() + 1)
            return "";

        return s.substr(best_l, min_len);
    }
};

