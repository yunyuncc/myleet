class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> h;
        for(size_t i = 0; i < nums.size(); ++i){
            h[nums[i]] = i;
        }
        for(size_t i = 0; i < nums.size(); i++){
            int res = target - nums[i];
            if(h.count(res) != 0 && i != h[res]){
                vector<int> buf{i, h[res]};
                return buf;
            }
        }
        throw std::runtime_error("No two sum solution");
    }
};
/**** O(n2)*/
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(size_t i = 0; i < nums.size(); ++i){
            for(size_t j = i+1; j < nums.size(); j++){
                if(target == nums[i] + nums[j]){
                    vector<int> res{static_cast<int>(i), static_cast<int>(j)};
                    return res;
                }
            }
        }
        throw std::runtime_error("No two sum solution");
    }
};
