
class Solution {
  public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        vector<int> stk;

        stk.push_back(0);
        vector<int> arr(temperatures.size(), 0);
        for (int i = 1; i < temperatures.size(); ++i) {
            while (temperatures[i] > temperatures[stk.back()]) {
                arr[stk.back()] = i - stk.back();
                stk.pop_back();
                if (stk.size() == 0)
                    break;
            }

            stk.push_back(i);
        }

        return arr;
    }
};

