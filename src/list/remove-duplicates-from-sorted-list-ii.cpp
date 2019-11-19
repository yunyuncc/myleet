#include "list.hpp"
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* dummyhead = new ListNode(0);
		dummyhead->next = head;
		ListNode* prev = dummyhead;
		ListNode* p = prev->next;
		while(p->next != nullptr){
			ListNode* dupBegin = p;
			ListNode* dupEnd = p;
			while(true){
                if(dupEnd->next == nullptr){//到了最后一个节点
                    break;
                }
                if(dupEnd->val != dupEnd->next->val){//现在dupEnd走到了真正的最后一个重复节点的位置了
                    break;
                }
			    dupEnd = dupEnd->next;
			}
			if(dupBegin != dupEnd){//有重复节点，删除dupBegin到dupEnd之间的节点
				p = dupEnd->next;
				prev->next = p;
				//free memory between dupBegin and dupEnd
			}else{//没有重复节点
				p = p->next;
				prev = prev->next;
			}
            if(p == nullptr){
                break;
            }
		}
		ListNode* res = dummyhead->next;
		delete dummyhead;
		return res;
    }
};

int main(){
	ListNode* list1 = createList({});
	cout << "list1:" << list2str(list1) << endl;
	Solution s;
	ListNode* list2 = s.deleteDuplicates(list1);
	cout << "list2:" << list2str(list2) << endl;
	return 0;
}
