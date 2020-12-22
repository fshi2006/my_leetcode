class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;
        unordered_map<char, int> in_st;
        for(int i = 0; i < s.size(); ++i)
            mp[s[i]] = i;//记录某个字符出现的最后位置
        vector<char> st;//记录结果的栈
        for(int i = 0; i < s.size(); ++i){
            if(in_st[s[i]])continue;//栈中有当前遍历的字符
            while(st.size() && s[i] < st.back() && mp[st.back()] > i){
            //栈顶元素会在之后的位置出现
                --in_st[st.back()];
                st.pop_back();
            //出栈并抹除记录
            }
            st.push_back(s[i]);
            ++in_st[s[i]];
        //压栈，并记录出现过
        }
        string res;
        for(auto& i : st)res += i;    
        return res;
    }
};