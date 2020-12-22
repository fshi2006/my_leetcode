class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> s_map,t_map;
        int strlen = s.size();
        int i=0;
        for(auto tmpchar:s){
            s_map[tmpchar] ++;
        }
        for(auto tmpchar:t){
            t_map[tmpchar] ++;
        }
        for(auto tmpchar:t){
            if(s_map.count(tmpchar) && s_map[tmpchar] != t_map[tmpchar]) 
                return tmpchar;
            if(!s_map.count(tmpchar))
                return tmpchar;
        }
        return ' ';
    }
};