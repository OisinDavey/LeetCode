//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
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

int numRollsToTarget(int d, int f, int target) {
    const int MOD = 1e9 + 7;
    int prev[target+1];
    int cur[target+1];
    memset(prev, 0, sizeof(prev));
    for(int i=1;i<=f && i<=target;++i){
        prev[i] = 1;
    }
    for(int i=0;i<d-1;++i){
        memset(cur, 0, sizeof(cur));
        for(int j=1;j<target+1;++j){
            cur[j] = ((j>0)?prev[j-1]:0);
            cur[j] -= ((j-1-f>=0)?prev[j-1-f]:0);
            if(cur[j] < 0){
                cur[j] += MOD;
            }
            cur[j] += ((j>0)?cur[j-1]:0);
            if(cur[j] >= MOD){
                cur[j] -= MOD;
            }
        }
        memcpy(prev, cur, sizeof(cur));
    }
    return prev[target];
}

int main(){
    cout << numRollsToTarget(30, 30, 500) << endl;
}
