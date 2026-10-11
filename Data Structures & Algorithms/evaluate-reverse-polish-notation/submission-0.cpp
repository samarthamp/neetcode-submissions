class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            bool cond = isOp(tokens[i]);

            if (cond)
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int c;
                if (tokens[i] == "+") c = a+b;
                else if (tokens[i] == "-") c= a-b;
                else if (tokens[i] == "*") c = a*b;
                else c = a/b;

                st.push(c);
            }
            else 
            {
                int temp = stoi(tokens[i]);
                st.push(temp);
            }
        }

        int ans = st.top();
        st.pop();

        return ans;
    }

    bool isOp(string s)
    {
        return ((s == "+") || (s == "-") || (s == "*") || (s == "/")); 
    }
};
