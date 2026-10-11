class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head->next) return head;

        ListNode head_rev;
        ListNode* prev = &head_rev;

        auto it = head;

        while (it)
        {
            stack<ListNode*> st;
            bool cond = true;
            auto temp = it;
            for (int i = 0; i<k; i++)
            {
                st.push(it);
                it = it->next;
                if (!it)
                {
                    if (i != k-1) cond = false;
                    break;
                }
            }

            if (!cond) {prev->next = temp; break;}

            while (!st.empty())
            {
                auto curr = st.top();
                st.pop();
                prev->next = curr;
                prev = curr;
                prev->next = nullptr;
            }
        }

        return head_rev.next;
    }
};