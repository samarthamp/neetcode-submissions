class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return NULL;

        while (lists.size() > 1)
        {
            vector<ListNode*> temp;

            for (int i = 0; i < lists.size(); i=i+2)
            {
                auto l1 = lists[i];
                auto l2 = (i+1 < lists.size()) ? lists[i+1] : NULL;
                temp.push_back(mergeTwoLists(l1, l2));
            }
            lists = temp;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode* prev = &head;

        while (list1 && list2)
        {
            if (list1->val <= list2->val) {prev->next = list1; list1 = list1->next;}
            else {prev->next = list2; list2 = list2->next;}
            prev = prev->next;
        }
        prev->next = list1 ? list1 : list2;
        return head.next;
    }
};