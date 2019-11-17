#pragma once
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

inline struct ListNode* createList(const std::vector<int>& nums){
    ListNode* dummyhead = new ListNode(0);
    ListNode* p = dummyhead;
    for(auto num : nums){
        p->next = new ListNode(num);
        p = p->next;
    }
    p = dummyhead->next;
    delete dummyhead;
    return p;
}
inline std::string list2str(ListNode* list){
    ListNode* p = list;
    std::string str;
    while(p){
        str += std::to_string(p->val);
        str += "->";
        p = p->next;
    }
    return str;
}

inline void deleteList(ListNode* list){
    ListNode* p = list;
    while(p){
        ListNode* tmp = p;
        p = p->next;
        delete tmp;
    }
}
