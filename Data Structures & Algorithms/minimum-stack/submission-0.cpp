
class MinStack {

  private:
    vector<int> v;
    vector<int> mins = {};

  public:
    MinStack() {}

    void push(int val) {
        v.push_back(val);
        if (mins.empty() || val <= mins.back()) {
            mins.push_back(val);
        }
    }

    void pop() {
        if (v.back() == mins.back()) {
            v.pop_back();
            mins.pop_back();
        }

        else {
            v.pop_back();
        }
    }

    int top() {
        return v.back();
    }

    int getMin() {
        return mins.back();
    }
};