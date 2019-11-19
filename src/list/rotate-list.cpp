#include "list.hpp"
#include <iostream>
using namespace std;
class Solution {
public:
	
    ListNode* rotateRight(ListNode* head, int k) {
		int len = 0;
		ListNode* tail = listTail(head, &len);
		if(tail == nullptr){
			return nullptr;
		}
		tail->next = head;
		ListNode* p = head;
		k = k % len;
		int step = len - k;
		for(int i = 0; i < step; i++){
			p = p->next;
		}
		ListNode* new_tail = index(p, len - 1);
		new_tail->next = nullptr;
		return p;
	}
};

int main(){
	ListNode* list = createList({0,1,2});
	cout << "list1:" << list2str(list) << endl;
	Solution s;
	ListNode* l = s.rotateRight(list, 4);
	cout << "list2:" << list2str(l) << endl;
}
