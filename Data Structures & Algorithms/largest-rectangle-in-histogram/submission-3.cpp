
class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {

        vector<int> stk;
        vector<int> ans;

        heights.push_back(0);

        if (heights.size() == 2) {
            return heights[0];
        }

        for (int i = 0; i < heights.size(); ++i) {
            while ((!stk.empty() && heights[i] < heights[stk.back()])) {
                int height = heights[stk.back()];
                stk.pop_back();
                if (!stk.empty()) {
                    int width = i - stk.back() - 1;
                    ans.push_back(height * width);

                } else {
                    ans.push_back(height * i);
                }
            }

            stk.push_back(i);
        }

        int max = 0;
        for (int i : ans) {
            if (i > max) {
                max = i;
            }
        }

        return max;
    }
};

