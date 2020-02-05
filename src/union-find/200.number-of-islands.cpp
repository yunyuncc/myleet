#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <unordered_map>
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
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){return 0;}
        vector<int> items;
        int h = grid.size();
        int w = grid[0].size();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                //if(grid[i][j] == '0') continue;
                int aa = i*w + j;
                items.push_back(aa);
            }
        }
        disjoint_set<int> s;
        s.init_set(items);
        vector<vector<int>> directions{
            {-1, 0},//up
            {1, 0},//down
            {0, -1},//left
            {0, 1}//right
        };
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == '0') continue;
                for(auto d : directions){
                    int x =  i+d[0];
                    int y = j+d[1];
                    if(!valid(grid, x, y)) continue;
                    if(grid[x][y] == '0') continue;
                    s.do_union(x*w+y, i*w+j);
                }
            }
        }
        set<int> aa;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == '1'){
                    aa.insert(s.find_root(i*w+j));
                }
            }
        }
        return aa.size();
    }
    bool valid(vector<vector<char>>& set_grid, int i, int j){
        if(i < 0 || j < 0){return false;}
        if(i >= set_grid.size() || j >= set_grid[0].size()){return false;}
        return true;
    }
};

int main(){
	
	Solution s;
	vector<char> aa;
	aa.push_back(999999999999999999999999999999);
	cout << int(aa[0]) << endl;
	vector<vector<char>> grid{
		{'1','1','0','1','1'},
		{'1','1','0','1','1'},
		{'1','1','0','1','1'},
        {'1','1','0','1','1'}
	};
	int num = s.numIslands(grid);
	cout << num << endl;

}
