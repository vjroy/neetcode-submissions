
class Solution {
  public:
    int evalRPN(const vector<string>& tokens) {
        vector<int> stk;

        int sum = 0;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "+" && tokens[i] != "*" && tokens[i] != "/" &&
                tokens[i] != "-") {
                stk.push_back(stoi(tokens[i]));
                continue;
            }

            int x = stk.back();
            if (tokens[i] == "+") {
                stk.pop_back();
                int y = stk.back();
                stk.pop_back();
                stk.push_back(x + y);
            } else if (tokens[i] == "-") {
                stk.pop_back();
                int y = stk.back();
                stk.pop_back();
                stk.push_back(y - x);
            } else if (tokens[i] == "*") {
                stk.pop_back();
                int y = stk.back();
                stk.pop_back();
                stk.push_back(x * y);
            }

            else {
                stk.pop_back();
                int y = stk.back();
                stk.pop_back();
                stk.push_back(y / x);
            }
        }

        return stk.back();
    }
};

