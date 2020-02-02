#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
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
    std::vector<int> left(sortedNums.begin(), mid);
    std::vector<int> right(mid+1, sortedNums.end());
    node->left = createTree(left);
    node->right = createTree(right);
    return node;
}
inline std::vector<int> inorderTraversal(TreeNode* root){
    if(root == nullptr){
        return {};
    }
    auto left = inorderTraversal(root->left);
    auto right = inorderTraversal(root->right);
    left.push_back(root->val);
    std::copy(right.begin(), right.end(), std::back_inserter(left));
    return left;
}
