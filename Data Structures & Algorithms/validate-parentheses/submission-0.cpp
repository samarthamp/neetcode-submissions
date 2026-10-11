class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        int n = s.length();
        bool ans = true;

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if ((c == '[') || (c == '(') || (c == '{')) st.push(c);
            else 
            {
                if (st.empty()) {ans = false; break;}
                char top = st.top();
                st.pop();

                if ((c == ']') && (top != '[')) {ans = false; break;}
                else if ((c == '}') && (top != '{')) {ans = false; break;}
                else if ((c == ')') && (top != '(')) {ans = false; break;}
            }
        }

        if (!st.empty()) ans = false;

        return ans;
    }
};
