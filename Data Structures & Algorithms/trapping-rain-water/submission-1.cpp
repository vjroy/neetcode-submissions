
class Solution {
  public:
    int trap(vector<int>& height) {
        int sum = 0;
        vector<int> leftMax;
        vector<int> rightMax;
        leftMax.reserve(height.size());
        rightMax.reserve(height.size());
        int lMax = 0;
        int rMax = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] > lMax) {
                lMax = height[i];
            }
            leftMax.push_back(lMax);
        }

        for (int i = height.size() - 1; i >= 0; --i) {
            if (height[i] > rMax) {
                rMax = height[i];
            }

            rightMax.push_back(rMax);
        }

        int j = height.size() - 1;
        for (int i = 0; i < height.size(); ++i) {
            sum += max(min(leftMax[i], rightMax[j]) - height[i], 0);
            j--;
        }

        return sum;
    }
};

