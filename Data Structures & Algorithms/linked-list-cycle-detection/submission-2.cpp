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

// create a fast pointer and a slow pointer
// if fast pointer reaches nullptr, no cycles
// if fast pointer reaches the slow pointer, (overlap) there is a cycle

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *fast_ptr, *slow_ptr;

        if (head != nullptr && head->next != nullptr) {
            slow_ptr = head;
            fast_ptr = head->next;
        } else {
            return false;
        }

        while (fast_ptr != nullptr) {
            slow_ptr = slow_ptr->next;

            if (fast_ptr->next == nullptr) {
                return false;
            }
            fast_ptr = fast_ptr->next->next;

            if (slow_ptr == fast_ptr) {
                return true;
            }
        }

        return false;
    }
};
