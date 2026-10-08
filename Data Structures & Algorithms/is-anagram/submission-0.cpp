class Solution {
  public:
    bool isAnagram(std::string& s, std::string& t) {
        std::unordered_map<char, int> freq;
        std::unordered_map<char, int> freq2;
        for (char i : s) {
            freq[i]++;
        }

        for(char i : t)
  {
      freq2[i]++;
    }

    if(freq == freq2) return true;
    return false;
    }
};


