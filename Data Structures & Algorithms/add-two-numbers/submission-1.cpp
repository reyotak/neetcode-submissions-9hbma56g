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

 // iterate through the list
 // add the node values
 // have a carry on
 // add in the list

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        auto tail = head;
        int carry_on = 0;

        while (l1 != nullptr && l2 != nullptr) {

            int sum = l1->val + l2->val + carry_on;
            ListNode* temp = new ListNode(sum % 10);
            carry_on = sum >= 10 ? 1 : 0;
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            int sum = l1->val + carry_on;
            ListNode* temp = new ListNode(sum % 10);
            carry_on = sum >= 10 ? 1 : 0;
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            int sum = l2->val + carry_on;
            ListNode* temp = new ListNode(sum % 10);
            carry_on = sum >= 10 ? 1 : 0;
            tail->next = temp;
            tail = temp;
            l2 = l2->next;
        }

        if (carry_on > 0) {
            ListNode* temp = new ListNode(carry_on);
            tail->next = temp;
            tail = temp;
        }

        return head->next;
    }
};
