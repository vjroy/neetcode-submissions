
class Solution {
  public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> map;

        for (int i = 0; i < strs.size(); ++i) {
            std::string copy = strs[i];
            std::sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(copy);
        }

        std::vector<std::vector<std::string>> ans;

        for (auto& [k, v] : map) {
            ans.push_back(v);
        }

        return ans;
    }
};

