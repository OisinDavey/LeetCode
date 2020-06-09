//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            500001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

int maximumSum(vector<int>& arr) {
    int n = arr.size();
    int K_prefix[n]; //Max sum subarray ending here
    int K_suffix[n]; //Max sum subarray starting here
    K_prefix[0] = arr[0];
    for(int i=1;i<n;++i){
        K_prefix[i] = max(arr[i], arr[i] + K_prefix[i-1]);
    }
    K_suffix[n-1] = arr[n-1];
    for(int i=n-1;i>=0;--i){
        K_suffix[i] = max(arr[i], arr[i] + K_suffix[i+1]);
    }
    int best = 0;
    for(int i=0;i<n;++i){
        best = max(best, (i > 0)?K_prefix[i-1]:0 + (i<n-1)?K_suffix[i+1]:0);
        best = max(best, K_prefix[i]);
        best = max(best, K_suffix[i]);
    }
    return best;
}
