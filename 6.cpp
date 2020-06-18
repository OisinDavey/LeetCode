class Solution {
public:
    string convert(string s, int numRows) {
      string ans = s;
      int n = numRows - 1;
      int m = s.size();
      if(m == 1 || n == 0){
        return ans;
      }
      vector<char> rows[numRows];
      for(int i=0;i<m;++i){
        if(i % (2*n) == 0){
          rows[0].push_back(s[i]);
        }else if(i % n == 0){
          rows[numRows-1].push_back(s[i]);
        }else if(i % (2*n) < n){
          rows[i % n].push_back(s[i]);
        }else{
          rows[n - (i % n)].push_back(s[i]);
        }
      }
      int glit = 0;
      for(int i=0;i<numRows;++i){
        for(int j=0;j<rows[i].size();++j){
          ans[glit] = rows[i][j];
          cout << rows[i][j] << ' ';
          ++glit;
        }
        cout << endl;
      }
      return ans;
    }
};
