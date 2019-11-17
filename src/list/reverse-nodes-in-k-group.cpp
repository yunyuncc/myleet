#include <iostream>
#include <utility>
#include "list.hpp"
using namespace std;
/**
 * Definition for singly-linked list.
 */

class Solution {
public:
    //将list在第n个节点劈开两半
    pair<ListNode*, ListNode*> pickSubList(ListNode* l, int n){
        if(n == 0){
            return{nullptr, l};
        }
        ListNode* p = l;
        ListNode* first_tail = nullptr;
        for(int i = 0; i < n; i++){
            if(p == nullptr){
                return {l, nullptr};
            }
            if(i == n - 1){
                first_tail = p;
            }
            p = p->next;
        }
        if(first_tail){
            first_tail->next = nullptr;
        }
        return {l, p};
    }
    //将list批成n个长度为k的小链表
    vector<ListNode*> split(ListNode* list, int k){
        vector<ListNode*> lists;
        ListNode* p = list;
        while(true){
            auto [first, second] = pickSubList(p, k);
            if(first == nullptr){
                break;
            }
            lists.push_back(first);
            if(second == nullptr){
                break;
            }
            p = second;
        }
        return lists;
    }
    //反转链表
    ListNode* reverse(ListNode* head) {
        ListNode* p = head;
        ListNode* save_broken = nullptr;
        ListNode* prev = nullptr;
        while(true){
            //1.保存下一个节点的指针
            save_broken = p->next;
            //2.反转当前节点
            p->next = prev;//反转
            //3.走向下一个节点
            prev = p;
            p = save_broken;
            if(save_broken == nullptr){
                break;
            }
        }
        return prev;
    }
    ListNode* listTail(ListNode* list){
        ListNode* p = list;
        while(p->next != nullptr){
            p = p->next;
        }
        return p;
    }
    int listLen(ListNode* list){
        ListNode* p = list;
        int i = 0;
        while(p != nullptr){
            i++;
            p = p->next;
        }
        return i;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        auto lists = split(p, k);
        vector<ListNode*> reverse_lists;
        for(size_t i = 0; i < lists.size(); i++){
            if(i == lists.size() - 1){
                if(listLen(lists[i]) < k){
                    reverse_lists.push_back(lists[i]);
                }else{
                    reverse_lists.push_back(reverse(lists[i]));
                }
            }else{
                reverse_lists.push_back(reverse(lists[i]));
            }
        }
        return merge(reverse_lists);
    }
    ListNode* merge(vector<ListNode*>& lists){
        if(lists.empty()){
            return nullptr;
        }
        ListNode* last_tail = nullptr;
        for(auto list : lists){
            if(last_tail){
                last_tail->next = list;
            }
            last_tail = listTail(list);
        }
        return lists[0];
    }
};

int main(int argc, char** argv){
	std::vector<int> nums{};
	ListNode* list = createList(nums);
	cout << "ori:" <<  list2str(list) << endl;
	Solution s;
    ListNode* res = s.reverseKGroup(list, 1);
    cout << "res:" << list2str(res) << endl;
	return 0;
}
