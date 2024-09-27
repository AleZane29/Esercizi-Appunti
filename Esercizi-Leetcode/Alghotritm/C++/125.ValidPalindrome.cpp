class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(int i=0; i<s.length(); i++){
            if(isalnum(s[i])){res+=tolower(s[i]);}
        }
        for(int i=0; i<res.length()/2; i++){
            if(res[i]!=res[res.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};