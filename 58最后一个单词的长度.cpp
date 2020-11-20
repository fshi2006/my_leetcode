class Solution {
public:
    int lengthOfLastWord(string s) {
        int result=0;
        int len=s.size()-1;
        for(int i=s.size()-1;i>-1;i--)
        {
            if(s[i]==' ') len--;
            else break;
        }
        //cout<<len;
        for(int i=len;i>-1;i--)
        {  
            if(s[i]!=' '){
            result++;
            cout<<result;}
            else if(s[i]==' ')
            break;
        }
        return result;
    }
};