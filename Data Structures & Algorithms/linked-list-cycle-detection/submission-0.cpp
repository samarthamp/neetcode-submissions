/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto ptr = head;
        unordered_map<ListNode*, int> mp;

        while (ptr)
        {
            auto key = ptr;
            if (mp.find(key) != mp.end()) return true;
            mp[key] = 1; 
            ptr = ptr->next;
        }
        return false;
    }
};
