#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

class LRUCache {
public:
    class item{
    public:
        item(int k, int v):key(k),value(v){}
        int key;
        int value;
    };

    LRUCache(int capacity):c(capacity) {
        
    }
    
    int get(int key) {
        if(h.count(key) == 0){
            return -1;
        }
		
        auto it = h[key];
		int value = it->value;
		l.erase(it);
		l.push_front({key, value});
		h[key] = l.begin();
		return value;
    }
    
    void put(int key, int value) {
        if(h.count(key) == 0){//insert
            if(l.size() < c){
                l.push_front({key,value});
                h[key] = l.begin();
            }else{
                //remove last
                h.erase(l.back().key);
                l.pop_back();

                l.push_front({key,value});
                h[key] = l.begin();
            }
        }else{//update
            l.erase(h[key]);
            l.push_front({key,value});
            h[key] = l.begin();
        }
    }
    unordered_map<int, list<item>::iterator> h;
    list<item> l;
    int c;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // 返回  1
	cache.put(3, 3);    // 该操作会使得密钥 2 作废
	cout << cache.get(2) << endl;       // 返回 -1 (未找到)
	cache.put(4, 4);    // 该操作会使得密钥 1 作废
	cout << cache.get(1) << endl;       // 返回 -1 (未找到)
	cout << cache.get(3) << endl;       // 返回  3
	cout << cache.get(4) << endl;       // 返回  4
}

