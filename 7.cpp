class Solution {
public:
    int reverse(int x) {
      int tmp = 1;
      long long int X = x, ans;
      if(X < 0){
        tmp = -1;
        X *= -1;
      }
      string s;
      stringstream ss;
      stringstream oo;
      ss << X;
      ss >> s;
      std::reverse(s.begin(), s.end());
      oo << s;
      oo >> ans;
      if(ans > 2147483647 || ans < -2147483648){
        return 0;
      }else{
        return (int)ans * tmp;
      }
    }
};
