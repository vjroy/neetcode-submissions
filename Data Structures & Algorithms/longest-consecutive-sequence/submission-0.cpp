class Solution {
  public:
    int longestConsecutive(const std::vector<int>& nums) {
        std::unordered_map<int, int> seq;
        std::vector<int> start;
        for (int i : nums) {
            seq[i] = i + 1;
        }

        for (const auto& [k, v] : seq) {
            if (!seq.count(v - 2))
                start.push_back(k);
        }

        int answer = 0;
        for (int i = 0; i < start.size(); ++i) {
            int count = 0;
            auto it = seq.find(start[i]);
            while (it != seq.end()) {
                count++;
                it = seq.find(it->second);
            }

            if (count > answer)
                answer = count;
        }
        return answer;
    }
};

