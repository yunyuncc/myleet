#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        //dp[i][j]
        //i:第1天
        //j:0,1 none,keep
        //dp[i][none] = max(
        //  dp[i-1][none],
        //  dp[i-1][keep] + prices[i] //卖
        //)
        //dp[i][keep] = max(
        //  dp[i-1][none] - prices[i] //买
        //  dp[i-1][keep]
        //)
        vector<vector<int>> dp(prices.size(), vector<int>(2));  
        dp[0][0] = 0;
        dp[0][1] = -1*prices[0];
        for(int i = 1; i <prices.size(); i++){
            dp[i][0] = max(
                dp[i-1][0],
                dp[i-1][1] + prices[i]
            );
            dp[i][1] = max(
                dp[i-1][0] - prices[i],
                dp[i-1][1]
            );
        }
        return dp[prices.size()-1][0];
    }
};
int main(){
	Solution s;
	vector<int> ps{7,1,5,3,6,4};
	int res = s.maxProfit(ps);
	cout << res << endl;
}
