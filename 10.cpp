class Solution {
public:
    bool match(char& a, char& b){
      if(a == '_' || b == '_'){
        return (a == b);
      }else if(a == '.' || b == '.'){
        return true;
      }else{
        return (a == b);
      }
    }
    bool isMatch(string s, string p) {
      s = '_' + s;
      p = '_' + p;
      int n = p.size();
      int m = s.size();
      bool dp[n][m];
      memset(dp, 0, sizeof(dp));
      dp[0][0] = true;
      for(int i=1;i<n;++i){
        for(int j=0;j<m;++j){

          if(p[i] == '*'){

            if(i > 1){
              if(dp[i-2][j]){//None
                dp[i][j] = true;
              }
            }

            if(j > 0){
              if(dp[i-1][j]){//One
                dp[i][j] = true;
              }
            }

            if(j > 0){
              if(dp[i][j-1] && match(p[i-1], s[j])){//Many
                dp[i][j] = true;
              }
            }
          }

          else if(p[i] == '.'){
            if(j > 0){
              dp[i][j] = dp[i-1][j-1];
            }
          }

          else{
            if(j > 0){
              dp[i][j] = dp[i-1][j-1] && match(p[i], s[j]);
            }
          }

        }
      }
      return dp[n-1][m-1];
    }
};
