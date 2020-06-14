class Solution {
    public:
    int findPeakElement(vector<int>& nums){
        int n = nums.size();
        int L = 0;
        int R = n-1;
        while(L < R){
            int M = L + (R - L)/2;
            if(nums[M] > nums[M+1]){
                R = M;
            }else{
                L = M+1;
            }
        }
        return L;
    }
};
