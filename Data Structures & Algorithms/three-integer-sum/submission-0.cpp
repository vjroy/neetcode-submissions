
class Solution {
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> v;
        std::set<std::vector<int>> s;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int r = nums.size() - 1;
            int l = i + 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if (sum > 0) {
                    r--;
                }

                else {
                    l++;
                }
            }
        }

        for (const auto& i : s) {
            v.push_back(i);
        }

        return v;
    }
};

