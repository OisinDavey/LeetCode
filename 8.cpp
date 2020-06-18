class Solution {
public:
    int myAtoi(string str) {
      long long int x;
      string tmp = "";
      stringstream in_stream, temp_stream, out_stream;
      in_stream << str;
      in_stream >> tmp;
      if(tmp.size() == 0){
        return 0;
      }
      if(tmp[0] != '-' && tmp[0] != '+'){
        tmp = '+' + tmp;
      }
      int start = -1;
      for(int i=1;i<tmp.size();++i){
        if(tmp[i] != '0'){
          start = i;
          break;
        }
      }
      if(start == -1){
        return 0;
      }
      tmp = tmp[0] + tmp.substr(start, tmp.size()-start+1);
      if(tmp.size() > 18){
        return (tmp[0] == '+')?INT_MAX:INT_MIN;
      }
      temp_stream << tmp;
      temp_stream >> x;
      if(x > INT_MAX){
        return INT_MAX;
      }
      if(x < INT_MIN){
        return INT_MIN;
      }
      return (int)x;
    }
};
