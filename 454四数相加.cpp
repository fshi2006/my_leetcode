class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int a = A.size(),b=B.size(),c=C.size(),d=D.size();
        unordered_map<int,int> tmp1;
        int result=0;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++){
                //cout<<A[i]+B[j]<<endl;
                tmp1[A[i]+B[j]]++;
            }
        }
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<d;j++){
                if(tmp1.find(-(C[i]+D[j]))!=tmp1.end())
                {
                    int tmp2=-(C[i]+D[j]); 
                    result+=tmp1[tmp2];
                }
            }
        }
        return result;    
    }
};