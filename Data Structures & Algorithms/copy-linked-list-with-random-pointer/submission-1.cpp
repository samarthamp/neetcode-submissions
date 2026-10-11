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

        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;

        for (auto it = head; it; it = it->next)
        {
            auto temp = new Node(it->val);
            mp[it] = temp;
        }

        for (auto it = head; it; it = it->next)
        {
            auto copy = mp[it];
            copy->next = mp[it->next];
            copy->random = mp[it->random];
        }
        return mp[head];
    }   
};
