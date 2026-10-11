
class Solution {
  public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> ans;
        ans.reserve(nums.size());

        int count = 1;

        for (int i : nums)
            count *= i;

        if (count == 0) {
            int zero_count = 0;
            for (int i : nums) {
                if (i == 0)
                    ++zero_count;
            }

            if (zero_count > 1) {
                for (int j : nums) {
                    ans.push_back(0);
                }

                return ans;
            }

            int zero_i = -1;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    zero_i = i;
                }
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (i == zero_i) {
                    int c2 = 1;
                    for (int j = 0; j < nums.size(); ++j) {
                        if (j != zero_i) {
                            c2 *= nums[j];
                        }
                    }

                    ans.push_back(c2);
                }

                else {
                    ans.push_back(0);
                }
            }

            return ans;
        }

        for (int i : nums) {
            ans.push_back(count / i);
        }
        return ans;
    }
};
