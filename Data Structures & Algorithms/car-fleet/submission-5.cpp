
class Solution {
  public:
    int carFleet(int target, const vector<int>& position, const vector<int>& speed) {

        vector<pair<int, int>> ps;

        for (int i = 0; i < position.size(); ++i) {
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.rbegin(), ps.rend());

        vector<double> time;
        for (int i = 0; i < position.size(); ++i) {
            time.push_back((target - ps[i].first) / (double)(ps[i].second));
        }

        int fl = 1;
        double lb = time[0];
        for (int i = 1; i < time.size(); ++i) {
            if (time[i] > lb) {
                fl++;
                lb = time[i];
            }
        }

        return fl;
    }
};

