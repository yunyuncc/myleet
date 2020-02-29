#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> directions{
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    bool vaild(int i, int j, int w, int h){
        if(i < 0 || j < 0){
            return false;
        }
        if(i >= h || j >= w){
            return false;
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx, set<int>& visited){
        int h = board.size();
        int w = board[0].size();
        if(visited.count(i*w+j) == 1){
            return false;
        }
        if(board[i][j] != word[idx]){
            return false;
        }
        visited.insert(i*w+j);
        if(idx == word.size()-1 && board[i][j] == word[idx]){
            return true;
        }
        bool res = false;
        for(auto d : directions){
            int ii = i + d[0];
            int jj = j + d[1];
            if(!vaild(ii, jj, w, h)){
                continue;
            }
            if(dfs(board, ii, jj, word, idx+1, visited)){
                res = true;
                break;
            }
        }
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size();
        if(h == 0){
            return false;
        }
        int w = board[0].size();
        if(w == 0){
            return false;
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                int idx = 0;
                set<int> visited;
                if(board[i][j] == word[idx]){
                    if(dfs(board, i,j, word,idx, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main(){
	Solution s;
	vector<vector<char>> board{
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'E', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	string word("ABCESEEEFS") ;
	bool res = s.exist(board, word);
	cout << res << endl;
}
