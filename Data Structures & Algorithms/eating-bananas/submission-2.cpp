
class Solution {
  public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (complete(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool complete(vector<int>& v, int k, int h) {
        long long hrs = 0;
        for (int i = 0; i < v.size(); ++i) {
            hrs += (v[i] / k);
            if (v[i] % k != 0)
                hrs++;
        }

        return hrs <= h;
    }
};

