class Solution {
public:
    string largestOddNumber(string num) {
        int last = num.size()-1;
        while(last>=0){
            if(num[last]%2==0) last--;
            else{
                string largest = num.substr(0,last+1);
                return largest;
            }
        }
        return "";
    }
};