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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* p = head;
        ListNode* prev = dummyhead;
        while(true){
            while(true){
                if(p->next == nullptr|| p->val != p->next->val){
                    break;
                }
                p = p->next;
                prev->next = p;        
            }
            if(p->next == nullptr){
                break;
            }
            p=p->next;
            prev=prev->next;
        }
        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;
    }
};
