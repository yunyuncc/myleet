/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while(l1 != nullptr && l2 != nullptr ){
            if(l1->val < l2->val){
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }else{
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }
        }
        if(l1){
            p->next = l1;
        }
        if(l2){
            p->next = l2;
        }
        ListNode *res = head->next;
        delete head;
        return res;
    }
};
