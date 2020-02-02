#include "tree.hpp"
#include <iostream>
using namespace std;

int main(){
    TreeNode* tree = createTree({1,2,3});
    auto vals = inorderTraversal(tree);
    for(auto v : vals){
        cout << v << endl;
    }
}
