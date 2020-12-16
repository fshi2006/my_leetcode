class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> char_hash;
        unordered_map<string,char> str_hash;
        int strlen = s.size();
        int i=0;
        for(auto tmpchar:pattern){
            if (i >= strlen) 
                return false;
            int j=i;
            while(j<strlen&&s[j]!=' '){
                j++;
            }
            const string &tmpstr = s.substr(i,j-i);  
            if (char_hash.count(tmpchar) && char_hash[tmpchar] != tmpstr) {
                return false;
            }
            if (str_hash.count(tmpstr) && str_hash[tmpstr] != tmpchar) {
                return false;
            }
            char_hash[tmpchar] = tmpstr;
            str_hash[tmpstr] = tmpchar;
            i = j + 1;

        }
        return i>=strlen;
    }
};