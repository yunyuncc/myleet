#pragma once

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//01 这个递归函数要干什么：将sortedNums的中间值创建一个节点，然后将左右两边的sub array构造成左右子树
inline struct TreeNode* createTree(const std::vector<int>& sortedNums){
	//02 递归终止条件：sortedNums为空
    if(sortedNums.empty()){
        return nullptr;
    }
    auto mid = sortedNums.begin() + sortedNums.size()/2;
    TreeNode* node = new TreeNode(*mid);
	//03 拆分子问题
    vector<int> left(sortedNums.begin(), mid);
    vector<int> right(mid+1, sortedNums.end());
    node->left = createTree(left);
    node->right = sortedArrayToBST(right);
    return node;
}

