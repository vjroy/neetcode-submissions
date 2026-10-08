class Solution {
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::unordered_map<int, int> s;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = s.find(target - nums[i]);
            if (it != s.end()) {
                return std::vector<int>{it->second, i};
            }
            s[nums[i]] = i;
        }

        return {};
    }
};

