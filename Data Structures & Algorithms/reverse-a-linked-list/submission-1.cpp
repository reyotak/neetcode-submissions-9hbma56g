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

// criar um ponteiro next e prev
// serao usados pra n perder referencia da lista original
// next = head prev = nullptr
// while next != nullptr
// temp = next
// fazer o temp apontar pro prev
// temp->next = prev
// pasar os ponteiros next e prev
// next = next->next
// prev = temp
// retornar o prev


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *next;
        prev = nullptr;
        next = head;

        while (next != nullptr) {

            ListNode* temp = next;
            next = temp->next;
            temp->next = prev;
            prev = temp;

        }

        return prev;
    }
};
