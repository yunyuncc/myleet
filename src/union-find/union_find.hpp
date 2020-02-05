#pragma once
#include <unordered_map>
#include <vector>
#include <sstream>
namespace find_union{

using namespace std;
template <typename T>
class disjoint_set{
public:
    //初始化并查集，parents的key为set里面的item，value为该item的父
    void init_set(const vector<T>& nums){
        item_parent_map.clear();
        for(auto num : nums){
            item_parent_map[num] = num;
        }
    }
    
    T find_root(T item){
        if(item_parent_map.count(item) == 0){
            throw invalid_argument(string("item ") + " is not in set");
        }
        T i = item;
        while(i != item_parent_map[i]){
            i = item_parent_map[i];
        }
        T root = i;
        i = item;
        
        while(i != item_parent_map[i]){
            T parent = item_parent_map[i];
            item_parent_map[i] = root;
            i = parent;
        }
        
        return root;
    }
    
    /*
    T find_root(T i) { // path compression
        if (item_parent_map[i] != i) item_parent_map[i] = find(item_parent_map[i]);
        return item_parent_map[i];
    }
    */
    bool connected(T a, T b){
        if(find_root(a) == find_root(b)){
            return true;
        }
        return false;
    }
    bool do_union(T a, T b){
        
        if(connected(a,b)){
            return false;
        }
        
        T root_of_a = find_root(a);
        T root_of_b = find_root(b);
        item_parent_map[root_of_a] = root_of_b;
        return true;
    }
private:
    unordered_map<T,T> item_parent_map;
};
}
