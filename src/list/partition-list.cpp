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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return nullptr;

        
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* prev = dummyhead;
        ListNode* p = head;
        ListNode* partition_ptr = nullptr;
        while(true){
            if(p == nullptr){
                break;
            }
            if(p->val >= x){
                if(partition_ptr == nullptr){
                    //找到了partition_ptr，第一个大于等于x的节点的prev
                    partition_ptr = prev;
                }
                p=p->next;
                prev=prev->next;
            }else{
                if(partition_ptr){
                    //将p指向的节点交换到partition_ptr的后面
                    ListNode* save = p->next;
                    prev->next = save;
                    p->next = partition_ptr->next;
                    partition_ptr->next = p;
                    partition_ptr = partition_ptr->next;
                    p = save;
                }else{
                    p=p->next;
                    prev=prev->next;
                }
            }
        }
        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;
    }
};
