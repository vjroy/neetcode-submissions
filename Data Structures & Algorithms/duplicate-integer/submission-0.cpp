#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> s;
        for(int i = 0; i < nums.size(); ++i)
        {
            s.insert(nums[i]);
        }
            if(s.size() == nums.size())
            {
                return false;
            }

            return true;
        
    }
};