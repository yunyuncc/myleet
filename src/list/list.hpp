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
//得到第k(第一个节点的index为0)个节点的指针
inline ListNode* index(ListNode* list, int k){
	ListNode* p = list;
	for(int i = 0; i < k; i++){
		if(p == nullptr){
			return nullptr;
		}
		p = p->next;
	}
	return p;
}

inline ListNode* listTail(ListNode* list, int* len){
    ListNode* p = list;
	if(p == nullptr){
		if(len) *len = 0;
		return 0;
	}
	int i = 1;
    while(p->next != nullptr){
		i++;
        p = p->next;
    }
	if(len){
		*len = i;
	}
    return p;
}

