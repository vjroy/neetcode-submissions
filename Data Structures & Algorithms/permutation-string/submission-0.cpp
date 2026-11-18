
class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        int window_size = s1.size();
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for (char i : s1) {
            freq1[i]++;
        }

        if (s1.size() > s2.size())
            return false;

        string s2_sub = s2.substr(0, s1.size());

        for (char i : s2_sub) {
            freq2[i]++;
        }
        if (freq1 == freq2)
            return true;

        for (int i = s1.size(); i < s2.size(); ++i) {
            if (freq2.count(s2[i - s1.size()])) {
                freq2[s2[i - s1.size()]]--;
                if (freq2[s2[i - s1.size()]] == 0) {
                    freq2.erase(s2[i - s1.size()]);
                }
            }

            freq2[s2[i]]++;
            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};

