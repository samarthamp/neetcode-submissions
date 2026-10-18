#define all(v) (v).begin(), (v).end()

class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(all(nums));
        vector<int> curr;
        build(nums, curr, nums.size());
        
        return ans;
    }

    void build(vector<int>& choices, vector<int>& curr, int n)
    {
        if (!choices.size())
        {
            ans.push_back(curr); 
            return;
        } 

        for (int i = 0; i < choices.size(); i++)
        {
           vector<int> temp(curr);
           temp.push_back(choices[i]);

           vector<int> temp2(choices);
           auto it = temp2.begin() + i;
           temp2.erase(it);
           build(temp2, temp, n);
        }

        return;
    }
};