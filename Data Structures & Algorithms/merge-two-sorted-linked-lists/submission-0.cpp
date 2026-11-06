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


/*
 *  get 1 aux pointers for each list: aux
    get 1 res pointer; res
    get 1 aux res pointer: aux_res
    aux = head

    while (aux != nullptr)

    if aux1 != nullptr
    temp1 = aux1

    if aux2 != nullptr
    temp2 = aux2

    se for nullptr add temp

    if (aux1->val < aux2->val) {
        aux-res->next = aux1 else aux2
    }

    return res

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp_l1, *temp_l2, *res, *temp_res;

        if (list1 == nullptr && list2 == nullptr) return nullptr;

        temp_l1 = list1;
        temp_l2 = list2;
        
        if (temp_l1 == nullptr) {
            res = temp_l2;
            temp_l2 = temp_l2->next;
        } else if (temp_l2 == nullptr) {
            res = temp_l1;
            temp_l1 = temp_l1->next;
        } else {
            if (temp_l1->val < temp_l2->val) {
                res = temp_l1;
                temp_l1 = temp_l1->next;
            } else {
                res = temp_l2;
                temp_l2 = temp_l2->next;
            }
        }

        temp_res = res;

        while (temp_l1 != nullptr || temp_l2 != nullptr) {

            if (temp_l1 == nullptr) {
                temp_res->next = temp_l2;
                temp_l2 = temp_l2->next;
            } else if (temp_l2 == nullptr) {
                temp_res->next = temp_l1;
                temp_l1 = temp_l1->next;
            } else {
                if (temp_l1->val < temp_l2->val) {
                    temp_res->next = temp_l1;
                    temp_l1 = temp_l1->next;
                } else {
                    temp_res->next = temp_l2;
                    temp_l2 = temp_l2->next;
                }
            }
            temp_res = temp_res->next;
        }

        return res;
    }
};
