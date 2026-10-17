class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<int> st;
        int cnt = 0;
        while (n)
        {
            st.push(n%2);
            n = n >> 1;
            cnt++;
        }
        
        for (int i = 0; i < 32 - cnt; i++) st.push(0);

        uint32_t ans = 0;
        int exp = 0;
        while (!st.empty())
        {
            int bit = st.top();
            st.pop();
            if (bit) ans += pow(2, exp);
            exp++;
        }
        return ans;
    }
};
