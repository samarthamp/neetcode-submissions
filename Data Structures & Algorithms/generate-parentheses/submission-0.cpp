class Solution {
private:
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        build(curr, n, n, 0);
        return ans;
    }

    void build(string curr, int open, int close, int parity)
    {
        if ((!open) && (!close)) {ans.push_back(curr); return;}
        
        if (!open)
        {
            string temp = curr + ')';
            build(temp, open, close - 1, parity - 1);
            return;
        }

        if (!parity)
        {
            string temp = curr + '(';
            build(temp, open - 1, close, parity + 1);
            return;
        }

        string temp1 = curr + '(';
        build(temp1, open - 1, close, parity + 1);
        
        string temp2 = curr + ')';
        build(temp2, open, close - 1, parity - 1);
        
        return;
    }
};