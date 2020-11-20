class Solution {
public:
    string replaceSpace(string s) {
        int space_num = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                space_num++;
        }
        int size_old = s.size();
        int size_new= s.size()+space_num*2;
        s.resize(size_new);
        for(int i=size_new-1,j=size_old-1;j>=0;j--,i--)
        {
            if(s[j]!=' ')
            {
                s[i]=s[j];
            }
            else
            {
                s[i]='0';s[i-1]='2';s[i-2]='%';
                i-=2;
            }
            std::cout<<s<<std::endl;
        }
        return s;
    }
};