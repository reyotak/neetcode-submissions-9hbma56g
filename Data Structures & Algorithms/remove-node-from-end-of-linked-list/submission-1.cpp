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

 // iterate through the entire list
 // count the size
 // go to the size - n - 1
 // make it point to next->next

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        auto it = head;
        while (it != nullptr) {
            it = it->next;
            count++;
        }
        int pos = count - n - 1;

        if (pos < 0) {
            if (head == nullptr) {
                return head;
            }
            return head->next;
        }

        count = 0;
        it = head;
        while (count != pos) {
            it = it->next;
            count++;
        }

        if (it == nullptr || it->next == nullptr) {
            return head;
        } else {
            it->next = it->next->next;
        }

        return head;
    }
};
