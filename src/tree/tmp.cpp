#include <iostream>
#include <string>
#include <deque>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void rserialize(TreeNode* node, string& str){
        if(!node){
            str += "null,";
            return;
        }
        str += to_string(node->val);
        str += ",";
        rserialize(node->left,str);
        rserialize(node->right, str);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        rserialize(root, str);
        return str;
    }

    deque<string> split(string str, char c){
        deque<string> res;
        int i = 0;
        while(!str.empty()){
            if(str[i] == c){
                string head = str.substr(0, i+1);
                str = str.substr(i+1);
                i = 0;
                res.push_back(head);
            }
            i++;
        }
        return res;
    }
    TreeNode* rdeserialize(deque<string>& datas){
        if(datas.empty()) return nullptr;
        string data(datas.front());
        datas.pop_front();
        if(data == "null"){
            return nullptr;
        }
        int val = stoi(data);
        TreeNode* node = new TreeNode(val);
        node->left = rdeserialize(datas);
        node->right = rdeserialize(datas);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<string> datas = split(data, ',');
        return rdeserialize(datas);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(){
	Codec codec;
	TreeNode* root = new TreeNode(1);
	string str = codec.serialize(root);
	cout << str << endl;

}
