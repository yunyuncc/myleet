/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution {
public:
    class Window{
    public:
        enum class stat_t{
          close,
          half_open,
          open
        };
        int distance(ListNode*l1, ListNode*l2){
            ListNode*p = l1;
            if(p == nullptr){
                return 0;
            }
            int i = 0;
            while(p != l2){
                p = p->next;
                i++;
            }
            return i;
        }
        Window(ListNode *beg, int n):width(n),first(beg), second(beg), cnt(0){}
        ListNode* get_second(){return second;}
        stat_t get_stat(){
            if(first == second){
                return stat_t::close;
            }
            if(distance(second, first) == width - 1){
                return stat_t::open;
            }
            return stat_t::half_open;
        }
        ListNode* get_first(){return first;}
        int get_width(){return width;}
        ListNode * move(){
            if(first->next == nullptr){//已经移动到了尾节点
                return first;
            }
            cnt++;
            if(cnt < width){
                first = first->next;
            }else{
                first = first->next;
                second = second->next;
            }
            return first;
        }
    private:
        int width;
        ListNode *first;
        ListNode *second;
        int cnt;
    };
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        Window *window = new Window(head, n+1);
        ListNode* first = nullptr;
        do{
            first = window->move();
        }while(first->next != nullptr);//first移动到最后一个节点
        ListNode* prev_node = window->get_second();
        if(window->get_stat() == Window::stat_t::close){//window关闭
            return nullptr;
        }
        if(Window::stat_t::open == window->get_stat()){//window 完全展开
            prev_node->next=prev_node->next->next;
            return head;
        }
        assert(window->get_stat() == Window::stat_t::half_open);//window 半展开
        return head->next;
        //没有释放内存，因为不知道测试用例的内存是怎么申请下来的
    }
};
