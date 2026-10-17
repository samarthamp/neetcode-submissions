class Solution {
public:
    int reverse(int x) {
        bool is_neg = false;

        if (x < 0)
        {
            is_neg = true;
            if (x == INT_MIN) return 0;
        }

        x = abs(x);
        if (!x) return 0;

        while (!(x % 10)) x = x/10;
        
        stack<int> st;

        while (x)
        {
            st.push(x % 10);
            x = x/10;
        }

        int i = 0;
        int ans = 0;
        while (!st.empty())
        {
            int ele = st.top();
            if (ele * pow(10, (i - 1)) > (INT_MAX/10)) return 0;

            cout << i << " " << ele << "\n";
            st.pop();
            int delta = ele * pow(10, i);
            i++;
            if ((INT_MAX - delta) >= ans) ans += delta;
            else return 0;
        }

        if (is_neg) ans *= -1;
        return ans;
    }
};