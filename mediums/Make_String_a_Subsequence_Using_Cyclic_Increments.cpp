class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        for(; i < str1.size() && j < str2.size(); i++){
            if(str1[i] == str2[j]) j++;
            else{
                str1[i] = (((str1[i] - 'a') + 1)%26) + 'a';
                if(str1[i] == str2[j]) j++;
            }
        }
        
        if(j < str2.size()) return false;
        return true;
    }
};