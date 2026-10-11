/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, int> mp;
        int idx = 0;
        for (auto it = head; it; it = it->next) mp[it] = idx++;
        
        vector<int> arr;
        for (auto it = head; it; it = it->next)
        {
            if (it->random) arr.push_back(mp[it->random]);
            else arr.push_back(-1);
        }

        Node* dummy = new Node(-1);
        auto prev = dummy;

        vector<Node*> idx_to_ptr;
        for (auto it = head; it; it = it->next)
        {
            auto temp = new Node(it->val);
            idx_to_ptr.push_back(temp);
            prev->next = temp;
            prev = temp;
        }

        idx = 0;
        for (auto it = dummy->next; it; it = it->next)
        {
            int rand_idx = arr[idx];
            if (rand_idx != -1) it->random = idx_to_ptr[rand_idx];
            idx++;
        }

        return dummy->next;
    }   
};
