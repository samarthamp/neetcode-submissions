#define all(v) (v).begin(), (v).end()
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> arr;

        for (int i = 0; i<nums.size(); i++)
        {
            arr.push_back({nums[i], i});
        }

        sort(all(arr));

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            if (arr[left].first + arr[right].first == target) 
            {
                if (arr[left].second <= arr[right].second) return {arr[left].second, arr[right].second};
                else return {arr[right].second, arr[left].second};
            }
            
            else if (arr[left].first + arr[right].first < target) left++;

            else right--;
        }
        return {0, 0};
    }
};
