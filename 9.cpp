class Solution {
public:
    bool isPalindrome(int x) {
      string num, rev;
      stringstream in_stream;
      in_stream << x;
      in_stream >> num;
      rev = num;
      std::reverse(rev.begin(), rev.end());
      return (rev == num);
    }
};

class Solution {
public:
    vector<long long int> powers_of_ten = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
    int digit_at(long long int& x, int at){
      return ((x % powers_of_ten[at+1]) - (x % powers_of_ten[at]))/powers_of_ten[at];
    }
    bool is_palindrome(long long int x){
      if(x < 0){
        return false;
      }
      if(x == 0){
        return true;
      }
      int num_digits = floor(log10(x)) + 1;
      for(int i=0;i<num_digits;++i){
        if(digit_at(x, i) != digit_at(x, num_digits - i - 1)){
          return false;
        }
      }
      return true;
    }
    bool isPalindrome(int x) {
      return is_palindrome(x);
    }
};
