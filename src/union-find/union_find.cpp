#include <iostream>
#include <cassert>
#include "union_find.hpp"
using namespace std;
using namespace find_union;
void test_string(){
    disjoint_set<string> s;
    s.init_set({"1","2","3","4","5"});
    assert(s.count() == 5);
    //初始化后每个item都在独立的集合里面，他们的root都等于自己
    assert(s.find_root("1") == "1");
    assert(s.find_root("2") == "2");
    assert(s.find_root("3") == "3");
    assert(s.find_root("4") == "4");
    assert(s.find_root("5") == "5");
    //在union之前，这些item之间是没有连接在一起的
    assert(!s.connected("1","2"));
    assert(!s.connected("3","4"));
    assert(!s.connected("4","5"));
    //连接了1和2,现在1和2的root相等了
    assert(s.do_union("1","2"));
    assert(s.count() == 4);
    assert(s.find_root("1") == s.find_root("2"));
    assert(s.connected("1","2"));
    //1和2已经连接在一起了，这个时候do_union会失败
    assert(!s.do_union("1","2"));
    
    //这个时候所有的item都连接到一个集合里面去了
    assert(s.do_union("1","3"));
    assert(s.do_union("1","4"));
    assert(s.do_union("4","5"));
    assert(s.count() == 1);
    assert(s.find_root("1") == s.find_root("2"));
    assert(s.find_root("2") == s.find_root("3"));
    assert(s.find_root("3") == s.find_root("4"));
    assert(s.find_root("4") == s.find_root("5"));
}

void test_int(){
    disjoint_set<int> s;
    s.init_set({1,2,3,4,5});
    //初始化后每个item都在独立的集合里面，他们的root都等于自己
    assert(s.find_root(1) == 1);
    assert(s.find_root(2) == 2);
    assert(s.find_root(3) == 3);
    assert(s.find_root(4) == 4);
    assert(s.find_root(5) == 5);
    //在union之前，这些item之间是没有连接在一起的
    assert(!s.connected(1,2));
    assert(!s.connected(3,4));
    assert(!s.connected(4,5));
    //连接了1和2,现在1和2的root相等了
    assert(s.do_union(1,2));
    assert(s.find_root(1) == s.find_root(2));
    assert(s.connected(1,2));
    //1和2已经连接在一起了，这个时候do_union会失败
    assert(!s.do_union(1,2));
    
    //这个时候所有的item都连接到一个集合里面去了
    assert(s.do_union(1,3));
    assert(s.do_union(1,4));
    assert(s.do_union(4,5));
    assert(s.find_root(1) == s.find_root(2));
    assert(s.find_root(2) == s.find_root(3));
    assert(s.find_root(3) == s.find_root(4));
    assert(s.find_root(4) == s.find_root(5));
}
int main(){
    test_int();
    test_string();
}
