
class Solution {
  public:
    string encode(const vector<string>& strs) {
        string s;
        for (int i = 0; i < strs.size(); ++i) {
            s += to_string(strs[i].size());
            s += "#";
            s += strs[i];
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#')
                j++;
            int len = stoi(s.substr(i, j - i));
            v.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }
        return v;
    }
};

