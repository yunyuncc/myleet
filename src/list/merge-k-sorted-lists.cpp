/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class FirstSolution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> curs;
        ListNode* dummyhead = new ListNode(0);
        ListNode* tail = dummyhead;
        for(size_t i = 0; i < lists.size(); i++){
            curs.push_back(lists[i]);
        }
        bool end;
        do{
            end = true;
            int min = INT_MAX;
            int min_idx = -1;
            for(size_t i = 0; i < curs.size(); i++){
                ListNode* l = curs[i];
                if(l == nullptr){
                    continue;
                }
                end = false;
                if(l->val < min){
                    min = l->val;
                    min_idx = i;
                }
            }
            if(min_idx != -1){
                tail->next = new ListNode(min);
                curs[min_idx] = curs[min_idx]->next;
                tail = tail->next;
            }
        }while(!end);
        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class RefactorFirstSolution {
public:
    int findMinNode(vector<ListNode*> firstNodes){
        int min = INT_MAX;
        int min_idx = -1; 
        for(size_t i = 0; i < firstNodes.size(); i++){
            ListNode* l = firstNodes[i];
            if(l == nullptr){
                continue;
            }   
            if(l->val < min){
                min = l->val;
                min_idx = i;
            }   
        }   
        return min_idx;
    }   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> curs;
        ListNode* dummyhead = new ListNode(0);
        ListNode* tail = dummyhead;
        for(size_t i = 0; i < lists.size(); i++){
            curs.push_back(lists[i]);
        }   
        
        while(true){
                int min_idx = findMinNode(curs);
                if(min_idx == -1){
                    break;
                }
                tail->next = new ListNode(curs[min_idx]->val);
                curs[min_idx] = curs[min_idx]->next;
                tail = tail->next;
        }   
        ListNode* res = dummyhead->next;
        delete dummyhead;
        return res;
    }   
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//分治
//分治和map reduce的关联
class SecondSolution {
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        auto const b = lists.cbegin();
        auto const m = b+(lists.size()+1)/2;
        auto const e = lists.cend();

        vector<ListNode*> left(b, m);
        vector<ListNode*> right(m, e);
        ListNode* l1 = mergeKLists(left);
        ListNode* l2 = mergeKLists(right);
        return mergeTwoLists(l1,l2);
    }   
};
