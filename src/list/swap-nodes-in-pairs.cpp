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
    ListNode* swapTwoNode(ListNode* prev, ListNode* n1, ListNode*n2) {
        assert(n1 != nullptr);
        assert(n1->next == n2);
        if(n2 == nullptr){
            return n1;
        }
        n1->next = n2->next;
        n2->next = n1;
        if(prev){
            assert(prev->next == n1);
            prev->next = n2;
        }
        return n2;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* new_head = nullptr;
        while(true){
            if(cur == nullptr){
                break;
            }
            cur = swapTwoNode(prev, cur, cur->next);
            if(new_head == nullptr){
                new_head = cur;
            }
            if(cur->next == nullptr){
                break;
            }
            prev = cur->next;
            cur = cur->next->next; 
        }
        return new_head;
    }
};
