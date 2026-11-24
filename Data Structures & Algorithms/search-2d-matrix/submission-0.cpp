
class Solution {
  public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        vector<int> v;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                v.push_back(matrix[i][j]);
            }
        }

        int low = 0;
        int high = v.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (v[mid] == target)
                return true;
            else if (v[mid] > target) {
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return false;
    }
};

