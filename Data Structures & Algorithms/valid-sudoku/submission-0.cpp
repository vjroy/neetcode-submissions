
class Solution {
  public:
    bool isValidSudoku(const std::vector<std::vector<char>>& board) {

        std::unordered_map<int, std::vector<int>> box;
        std::unordered_map<int, std::unordered_set<int>> box2;
        for (int i = 0; i < board.size(); ++i) {
            std::unordered_set<char> row;
            std::unordered_set<char> col;
            int countX = 0;
            int countY = 0;
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    box[(i / 3) * 3 + (j / 3)].push_back(board[i][j]);
                    box2[(i / 3) * 3 + (j / 3)].insert(board[i][j]);
                    countX++;
                    row.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    countY++;
                    col.insert(board[j][i]);
                }
            }

            if (row.size() != countX || col.size() != countY)
                return false;
        }

        for (int i = 0; i < 9; ++i) {
            if (box[i].size() != (box2[i].size()))
                return false;
        }
        return true;
    }
};

