class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {
        
    }
    
    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
        } else {
            int currentMin = st.top().second;
            st.push({value, min(value, currentMin)});
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        if (!st.empty()) {
            return st.top().first;
        }
        return -1;
    }
    
    int getMin() {
        if (!st.empty()) {
            return st.top().second;
        }
        return -1;
    }
};