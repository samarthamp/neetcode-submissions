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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto prev = dummy;  
        int carry = 0;

        auto it1 = l1;
        auto it2 = l2;
        while (it1 || it2)
        {
            int a = 0;
            int b = 0;
            if (it1) a = it1->val;
            if (it2) b = it2->val;

            int sum = a + b + carry;
            carry = sum/10;
            sum = sum%10;

            auto temp = new ListNode(sum);
            prev->next = temp;
            prev = temp;

            if (it1) it1 = it1->next;
            if (it2) it2 = it2->next;
        }

        if (carry)
        {
            auto temp = new ListNode(carry);
            prev->next = temp;
        }

        return dummy->next;
    }
};
