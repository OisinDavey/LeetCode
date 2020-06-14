class Solution {
    public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //Find closest number to x in the list, if equal spaced, pick smaller
        //Sliding window away from there, this is the same complexity as the size of the vector has to b k anyway
        int n = arr.size();
        int L = 0;
        int R = n-1;
        while(L < R){
            int M = L + (R - L + 1)/2;
            if(arr[M] > x){
                R = M-1;
            }else{
                L = M;
            }
        }
        if(L < n-1){
            if(abs(x - arr[L]) > abs(x - arr[L+1])){
                ++L;
            }
        }
        while(R - L + 1 < k){
            if(L > 0 && R < n-1){
                if(abs(x - arr[L-1]) <= abs(x - arr[R+1])){
                    --L;
                }else{
                    ++R;
                }
            }else if(L > 0){
                --L;
            }else{
                ++R;
            }
        }
        vector<int> ans = {};
        for(int i=L;i<=R;++i){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
