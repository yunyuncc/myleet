#include "tree.hpp"
class Solution {
public:
	struct TreeNode* createTree(const std::vector<int>& sortedNums, int n){
		//02 递归终止条件：sortedNums为空
	    if(sortedNums.empty()){
	        return nullptr;
	    }
		auto it = find(sortedNums.begin(), sortedNums.end(), n);
	    TreeNode* node = new TreeNode(*it);
		//03 拆分子问题
	    std::vector<int> left(sortedNums.begin(), it);
	    std::vector<int> right(it+1, sortedNums.end());

		if(!left.empty()){
			int left_n = *(left.begin() + left.size()/2);
	    	node->left = createTree(left, left_n);
		}else{
			node->left = nullptr;
		}
		if(!right.empty()){
			int right_n = *(right.begin() + right.size()/2);
	    	node->right = createTree(right, right_n);
		}else{
			node->right = nullptr;
		}
	    return node;
	}

    vector<TreeNode*> generateTrees(int n) {
     	vector<int> nums;
		for(int i = 1; i <= n; i++){
			nums.emplace_back(i);
		}   
		vector<TreeNode*> trees;
		for(int num : nums){
			trees.emplace_back(createTree(nums, num));
		}
		return trees;
    }

};
int main(){
	Solution s;
	auto trees = s.generateTrees(3);
	for(auto tree : trees){
		auto nums = inorderTraversal(tree);
		for(int num : nums){
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}
