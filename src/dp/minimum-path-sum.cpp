#include <iostream>
#include <vector>
using namespace std;
//1.state: minpath(m,n)
//2.relation of states: minpath(m, n) = min(minpath(m-1,n-1),minpath(n-1,m), minpath(n, m-1))
class Solution {
public:
	int min(int a, int b){
		return (a < b)?a:b;
	}
	void show(vector<vector<int>>& stat){
		for(auto a : stat){
			for(auto b : a){
				cout << b << " ";
			}
			cout << endl;
		}
	}
    int minPathSum(vector<vector<int>>& grid) {
		size_t row = grid.size();
		size_t col = grid[0].size();
		vector<int> buf(col);
        vector<vector<int>> stat;
		for(size_t i = 0; i < row; i++){
			stat.push_back(buf);
		}
		stat[0][0] = grid[0][0];
		for(size_t i = 1; i < row; i++){
			stat[i][0] = stat[i-1][0] + grid[i][0];
		}
		for(size_t i = 1; i < col; i++){
			stat[0][i] = stat[0][i-1] + grid[0][i];
		}
		for(size_t i = 1; i < row; i++){
			for(size_t j = 1; j < col; j++){
				int min_val = min(stat[i-1][j], stat[i][j-1]);
				stat[i][j] = min_val + grid[i][j];
			}
		}
		return stat[row-1][col-1];
    }
};
int main(){
	Solution s;
	vector<vector<int>> grid{{1,3,1},
							 {1,5,1},
							 {4,2,1}};
	cout << s.minPathSum(grid) << endl;
}
