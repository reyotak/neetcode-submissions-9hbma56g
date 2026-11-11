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

 // create an unordred set with the node address values
 // do a while has next
 // if node not in set add it
 // go to next
 // if is in set return false

class Solution {
public:
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*> node_set;
        
        if (head == nullptr) {
            return false;
        }

        node_set.insert(head);
        auto it = head;

        while (it->next != nullptr) {
            if (node_set.count(it->next)) {
                return true;
            }

            node_set.insert(it->next);
            it = it->next;
        }

        return false;
    }
};
