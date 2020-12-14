class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> strmap;
      for(int i=0;i<strs.size();i++){
            string strtmp=strs[i];
            sort(strtmp.begin(),strtmp.end());
            strmap[strtmp].push_back(strs[i]);
        }
        for(auto iter = strmap.begin(); iter != strmap.end(); iter++)
            result.push_back(iter->second);
        return result;
    }
};