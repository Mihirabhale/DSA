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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            len++;
            tail = tail->next;
        }

        int n = k % len;
        if (n == 0) return head;  // no rotation needed

        tail->next = head;  // make circular

        ListNode* p = head;
        for (int i = 0; i < len - n - 1; i++) {  // land on node before new head
            p = p->next;
        }

        head = p->next;
        p->next = nullptr;

        return head;
    }
};