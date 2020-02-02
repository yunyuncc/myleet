#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()){
            return 0;
        }
        vector<vector<int>> dp(
            triangle.size(),
            vector<int>(triangle[triangle.size()-1].size())
        );
        for(size_t i = 0; i < triangle[triangle.size()-1].size(); i++){
            dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
        }
        for(int i = triangle.size()-2; i >= 0; i--){
            for(size_t j = 0; j < triangle[i].size(); j++){
                cout << "do " << i << " " << j << endl;
                int a = dp[i+1][j];
                int b = dp[i+1][j+1];
                int t = triangle[i][j];
                cout << "dp[" << i << "," << j << "] = min(" << a << "," << b << ") + " << t << endl;
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
    
    //f(i, j) = total
};
int main(){
	Solution s;
	vector<vector<int>> tri{{2}, {3,4}, {6,5,7}, {4,1,8,3}};
	int res = s.minimumTotal(tri);
	cout << res << endl;
}
