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

 // create an output list res
 // create a node to track the tail of res
 // while one of the lists are not empty
 // compare the list heads
 // add to the res the smaller one
 // move the head from list1 or list2 and move tail of res
 // after that, append the non-empty list to res
 // return res

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = nullptr;
        ListNode* res_tail = nullptr;

        while (list1 != nullptr && list2 != nullptr) {

            ListNode* smaller;
            
            if (list1->val > list2-> val) {
                smaller = list2;
                list2 = list2->next;
            } else {
                smaller = list1;
                list1 = list1->next;
            }

            if (res == nullptr) {
                res = smaller;
            } else {
                res_tail->next = smaller;
            }
            res_tail = smaller;
        }

        if (list1 == nullptr) {
            if (res_tail == nullptr) {
                return list2;
            }

            res_tail->next = list2;
        } else {
            if (res_tail == nullptr) {
                return list1;
            }

            res_tail->next = list1;
        }

        return res;
    }
};
