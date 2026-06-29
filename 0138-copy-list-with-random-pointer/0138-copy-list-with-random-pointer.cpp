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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // pass 1: interleave copies with originals
        // 1→1'→2→2'→3→3'
        Node* curr = head;
        while (curr != nullptr) {
            Node* newNode  = new Node(curr->val);
            newNode->next  = curr->next;
            curr->next     = newNode;
            curr           = newNode->next;
        }

        // pass 2: copy random pointers
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // pass 3: separate the two lists
        curr           = head;
        Node* newHead  = head->next;
        Node* newCurr  = newHead;

        while (curr != nullptr) {
            curr->next    = newCurr->next;      // restore original
            curr          = curr->next;
            if (curr != nullptr) {
                newCurr->next = curr->next;     // wire copy list
                newCurr       = newCurr->next;
            }
        }

        return newHead;
    }
};