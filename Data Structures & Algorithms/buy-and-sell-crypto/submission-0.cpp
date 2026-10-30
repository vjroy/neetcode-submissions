
class Solution {
  public:
    int maxProfit(const vector<int>& prices) {
        int l = 0;
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[l]) {
                l = i;
            }

            else {
                if (prices[i] - prices[l] > ans) {
                    ans = prices[i] - prices[l];
                }
            }
        }

        return ans;
    }
};

