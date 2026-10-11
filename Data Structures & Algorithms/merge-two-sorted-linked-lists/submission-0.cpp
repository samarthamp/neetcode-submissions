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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1, nullptr);
        ListNode* prev = head;
        ListNode* curr;

        while (list1 && list2)
        {
            if (list1-> val <= list2->val) {curr = new ListNode(list1->val, nullptr); list1 = list1->next;}
            else {curr = new ListNode(list2->val, nullptr); list2 = list2->next;}

            prev->next = curr;
            prev = curr;
        }
        while (list1)
        {
            curr = new ListNode(list1->val, nullptr);
            prev->next = curr;
            prev = curr;
            list1 = list1->next;
        }
        while (list2)
        {
            curr = new ListNode(list2->val, nullptr);
            prev->next = curr;
            prev = curr;
            list2 = list2->next;
        }
        return head->next;
    }
};
