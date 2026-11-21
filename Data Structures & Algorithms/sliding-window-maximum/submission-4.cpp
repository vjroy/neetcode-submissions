
class Solution {
  public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {

        if (k == 1)
            return nums;

        deque<int> arr;
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            arr.push_back(i);
        }

        int max = INT_MIN;

        for (int i = 0; i < arr.size(); ++i) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }

        ans.push_back(max);

        for (int i = k; i < nums.size(); ++i) {
            if (max != nums[arr.front()]) {
                arr.pop_front();
                arr.push_back(i);

                if (nums[i] > max) {
                    max = nums[i];
                    ans.push_back(max);
                }

                else {
                    ans.push_back(max);
                }
            }

            else {
                max = INT_MIN;
                arr.pop_front();
                arr.push_back(i);

                for (int j : arr) {
                    if (nums[j] > max) {
                        max = nums[j];
                    }
                }

                ans.push_back(max);
            }
        }

        return ans;
    }
};

