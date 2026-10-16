
class Solution {
  public:
    int maxArea(std::vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int ans = 0;

        while (l < r) {
            ans = std::max(ans, (std::min(heights[l], heights[r])) * (r - l));
            if (heights[l] < heights[r])
                l++;
            else
                r--;
        }

        return ans;
    }
};

