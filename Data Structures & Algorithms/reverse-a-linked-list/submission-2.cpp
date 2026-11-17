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

// crete output list with head nullptr
// remove node from the input list
// create temp point to head
// head move to head next
// temp next output head
// output head = temp
// do this while input is not empty

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* head_res = nullptr;

        while (head != nullptr) {
            auto temp = head;
            head = head->next;
            temp->next = head_res;
            head_res = temp;
        }

        return head_res;
    }
};
