class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row=A.size(),col=A[0].size();
        for(int i=0;i<row;i++){
            if(A[i][0]==0){
                for(int j=0;j<col;j++)
                    A[i][j]=1-A[i][j];
            }
        }

        int tmp_one=0;
        for(int i=1;i<col;i++){
            for(int j=0;j<row;j++)
                if(A[j][i]==1)
                    tmp_one++;
            if(tmp_one<=row/2)
                for(int j=0;j<row;j++)
                    A[j][i]=1-A[j][i];
            tmp_one=0;
        }

        int result = 0;
        for(int i =0;i<row;i++){
            for(int j = 0;j<col;j++){
                result+=(A[i][j]*(int)pow(2,col-j-1));
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
        return result;
    }
};