class Solution {
  public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {

        std::unordered_map<int, int> map;

        for (int i : nums) {
            map[i]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;

        for (auto& [k, v] : map) {
            std::pair<int, int> a = {v, k};
            pq.push(a);
        }

        while (pq.size() != k) {
            pq.pop();
        }

        std::vector<int> ans;
        ans.reserve(k);

        while (pq.size() != 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

