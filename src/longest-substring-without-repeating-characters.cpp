/*
A sliding window is an abstract concept commonly used in array/string problems. 
A window is a range of elements in the array/string which usually defined by the 
start and end indices, i.e. [i, j)[i,j) (left-closed, right-open). 
A sliding window is a window "slides" its two boundaries to the certain direction. 
For example, if we slide [i, j)[i,j) to the right by 11 element, then it becomes [i+1, j+1)[i+1,j+1) (left-closed, right-open).
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.size();
        //set<char> sset;  //20ms
        unordered_set<char> sset;//20ms
        size_t ans = 0, i = 0, j = 0;
        while(i < n && j < n){
            if(sset.count(s[j]) == 0){
                sset.insert(s[j++]);
                ans = max(ans, j - i);
            }else{
                sset.erase(s[i++]);
            }
        }
        return ans;
    }
};
