class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> pos;
        for(int i=0;i<n;++i){
            if(pos[target-nums[i]] != 0){
                return {pos[target-nums[i]]-1, i};
            }
            pos[nums[i]] = i+1;
        }
        return {0, 0};
    }
};
