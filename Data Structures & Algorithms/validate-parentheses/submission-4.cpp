
class Solution {
  public:
    bool isValid(string s) {
        vector<char> v;

        if (s.size() % 2 != 0)
            return false;
        bool x = false;
        for (char i : s) {
            if (i == ')' || i == ']' || i == '}') {
                x = true;
                break;
            }
        }

        if (!x)
            return false;

        for (char i : s) {
            if (i == '(' || i == '{' || i == '[')
                v.push_back(i);

            else if (!v.empty() && (v.back() == '(' && i == ')' || v.back() == '[' && i == ']' ||
                                    v.back() == '{' && i == '}'))
                v.pop_back();
            else
                return false;
        }

        if (!v.empty())
            return false;

        return true;
    }
};

