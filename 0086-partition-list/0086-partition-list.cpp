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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small= new ListNode(0);
        ListNode* large=new ListNode(0);

        ListNode* p =small;
        ListNode* q = large;

        while(head!=nullptr){
            if(head->val<x){
                p->next=head;
                p=p->next;
            }else{
                q->next=head;
                q=q->next;
            }
            head=head->next;
        }
        q->next=nullptr;
        p->next=large->next;
        return small->next;
    }
};