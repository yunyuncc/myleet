#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        if(s.size() == 1){
            return {s};
        }
        if(s.empty()){
            return {};
        }
        set<string> res;
        size_t len = s.size();
        for(size_t i = 0; i < len; i++){
            char c = s[i];
            string head = s.substr(0, i);;
            string tail = s.substr(i + 1);
            string sub = head+tail;
            vector<string> sub_ress = permutation(sub);
            for(auto& sub_res:sub_ress){
                string res1 = string(1,c) + sub_res;
                res.insert(res1);
            }
        }
        vector<string> vec(res.begin(), res.end());
        return vec;
    }
};

int main(){
	Solution s;
	auto res = s.permutation("abc");
	for(auto s : res){
		cout << s << endl;
	}
}
