/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// create a map which translates the original address to the deep copy address
// go from start to end of the list, create the nodes and add it to the map
// create output list res and a ptr to tail
// go again from start to end of the original list (it)
// if res is nullptr, res = map[it], res->random = map[it->random] tail = res
// else tail->next = map[it], tail = tail->next , tail->random = map[it->random]
// it = it->next

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> translate_addr;
        translate_addr[nullptr] = nullptr;

        auto it = head;

        while (it != nullptr) {
            // create a deep copy
            Node* temp = new Node(it->val);

            // put in the map
            translate_addr[it] = temp;

            it = it->next;
        }

        it = head;
        Node* res = nullptr;
        Node* res_tail = res;
        while (it != nullptr) {
            if (res == nullptr) {
                res = translate_addr[it];
                res_tail = res;
            } else {
                res_tail = res_tail->next;
            }
            res_tail->next = translate_addr[it->next];
            res_tail->random = translate_addr[it->random];
            it = it->next;
        }

        return res;
    }
};
