
class Solution {
  public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int max_window_length = 0;
        int l = 0;
        for (int i = 0; i < s.size(); ++i) {
            int window_length = i - l + 1;
            freq[s[i]]++;
            int max_freq = 0;
            char most_common_char;
            for (auto& [key, v] : freq) {
                if (v > max_freq) {
                    max_freq = v;
                    most_common_char = key;
                }
            }

            while (window_length - max_freq > k) {
                freq[s[l]]--;
                l++;

                window_length = i - l + 1;
            }

            window_length = i - l + 1;

            if (window_length > max_window_length) {
                max_window_length = window_length;
            }
        }

        return max_window_length;
    }
};

