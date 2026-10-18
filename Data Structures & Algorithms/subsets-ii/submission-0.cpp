#define all(v) (v).begin(), (v).end()

class Solution {
private:
    vector<vector<int>> ans = {{}};
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(all(nums));
        vector<int> temp;
        build(nums, temp);

        return ans;
    }

    void build(vector<int>& propagate, vector<int>& curr)
    {
        if (!propagate.size()) return;
        
        int prev = -1;
        while(propagate.size())
        {
            if (prev != -1)
            {
                while (propagate.size() && propagate[0] == prev) propagate.erase(propagate.begin());

                if (!propagate.size()) return;
            }
            
            vector<int> curr_next(curr);
            curr_next.push_back(propagate[0]);
            ans.push_back(curr_next);
            prev = propagate[0];
            propagate.erase(propagate.begin());

            vector<int> prop_next(propagate);
            build(prop_next, curr_next);
        }
    }
};